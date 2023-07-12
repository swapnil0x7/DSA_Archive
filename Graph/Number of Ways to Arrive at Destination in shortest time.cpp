//In Gfg convert every int to long long
// Using Dijkstra's algo,  TC : O(E*logV)

int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int,int>> adj[n];
    
    for(auto i: roads){
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    
    vector<int> ways(n,0);
    ways[0] = 1;                  // ways to reach starting node = 1
    
    vector<int> time(n, 1e9);
    time[0] = 0;                 // time to reach starting node = 0
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});                // {time, node}
    
    int mod = (int)(2e9 + 7);
    
    while(!pq.empty()){
        int node = pq.top().second;
        int initial_time = pq.top().first;
        pq.pop();
        
        for(auto it: adj[node]){
            int j = it.first;
            int t = it.second;
            
            if(initial_time + t == time[j]){
                ways[j] = (ways[j] + ways[node]) % mod;              //reaching this node again -> add the ways from the node its reaching here
            }
            else if(initial_time + t < time[j]){
                time[j] = initial_time + t;
                ways[j] = ways[node];                                //reaching node for the very first time
                pq.push({time[j], j});
            }
        }
    }
    return ways[n-1] % mod;
}
