// Function to return a list containing the DFS traversal of the graph.
void dfs(int root, vector<int> adj[], vector<bool> &visited, vector<int> &res){
    visited[root] = true;
    res.push_back(root);
    
    for(auto j: adj[root]){
        if(!visited[j]){
            dfs(j, adj, visited, res);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    vector<int> res;
    vector<bool> visited(n, 0);
    
    dfs(0, adj, visited, res);
    
    return res;
}
