vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    int src = 1;
    int end = n;
    
    vector<pair<int,int>> adj[n+1];
    
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) parent[i] = i;
    
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        
        for(auto it: adj[node]){
            int j = it.first;
            int w = it.second;
            
            if(dist[j] > dis + w){
                dist[j] = dis + w;
                parent[j] = node;                //updating the its parent whenever we get a shorter path.
                pq.push({dist[j], j});
            }
        }
    }
  
    if(dist[end] == 1e9) return {-1};            // if destionation node is not reachable from src node.

    int curr = n;
    vector<int> path;
    while(parent[curr] != curr){               // backtracking the path from dest to src.
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(curr);
    reverse(path.begin(), path.end());
    return path;
}
