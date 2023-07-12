// we use Dijkstra's with QUEUE as the stops are incrementing by 1 at every step! 
// Hence, the TC is O(E) and not O(E*logV) !!!

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        
    vector<pair<int,int>> adj[n];
    
    for(auto i: flights){
        adj[i[0]].push_back({i[1], i[2]});
    }
    
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    
    vector<int> price(n, 1e9);
    
    while(!q.empty()){
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        
        if(stops > k) continue;
        
        for(auto it: adj[node]){
            int j = it.first;
            int p = it.second;
            
            if(cost + p < price[j]){
                price[j] = cost + p;
                q.push({stops+1, {j, cost+p}});
            }
        }
    }
    if(price[dst] == 1e9) return -1;
    return price[dst];
}

// Also this would also work! 👇
int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        
    vector<pair<int,int>> adj[n];
    
    for(auto i: flights){
        adj[i[0]].push_back({i[1], i[2]});
    }
    
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});                              //replaced the sequence {cost, {node, stops}}
    
    vector<int> price(n, 1e9);
    
    while(!q.empty()){
        int cost = q.front().first;
        int node = q.front().second.first;
        int stops = q.front().second.second;
        q.pop();
        
        if(stops > k) continue;
        
        for(auto it: adj[node]){
            int j = it.first;
            int p = it.second;
            
            if(cost + p < price[j]){
                price[j] = cost + p;
                q.push({cost+p, {j, stops+1}});
            }
        }
    }
    if(price[dst] == 1e9) return -1;
    return price[dst];
}
