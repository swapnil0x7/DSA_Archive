void topoSort(int node, vector<pair<int,int>> adj[], vector<int> &visited, stack<int> &s){
    visited[node] = 1;
    
    for(auto i: adj[node]){
        int j = i.first;
        if(!visited[j]){
            topoSort(j, adj, visited, s);
        }
    }
    s.push(node);
}

vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
    vector<pair<int,int>> adj[n];
    
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
    }
    
    vector<int> visited(n, 0);
    stack<int> s;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topoSort(i, adj, visited, s);
        }
    }
    
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    
    while(!s.empty()){
        int node = s.top();
        s.pop();
        
        for(auto it: adj[node]){
            int j = it.first;
            int w = it.second;
            
            if(dist[node] + w < dist[j]){
                dist[j] = dist[node] + w;
            }
        }
    }
    for(int i=0;i<n;i++) if(dist[i]==1e9) dist[i]=-1;
    return dist;
}

