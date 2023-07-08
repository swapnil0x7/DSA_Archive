//DFS - TC : O(N) + O(E) | S.C - O(2*N) = O(N)
//Also we can make use of just single visited arrray instead of taking path_visited!!

bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &path_visited){
    visited[node] = 1;
    path_visited[node] = 1;
    
    for(auto j: adj[node]){
        if(!visited[j]){
            if(dfs(j, adj, visited, path_visited) == true)
                return true;
        }
        else if(path_visited[j]){
            return true;
        }
    }
    path_visited[node] = 0;
    return false;
}

bool isCyclic(int n, vector<int> adj[]) {
    
    vector<int> visited(n, 0);
    vector<int> path_visited(n, 0);
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i, adj, visited, path_visited) == true)
                return true;
        }
    }
    return false;
}
