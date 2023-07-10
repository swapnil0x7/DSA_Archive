// Note - Any graph with odd length cycle can't be a bipartite graph!

//BFS method
bool check(int start, vector<int> adj[], vector<int> &color){
    queue<int> q;
    q.push(start);
    color[start] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto j: adj[node]){
            if(color[j] == -1){
                color[j] = !color[node];
                q.push(j);
            }
            else if(color[j] == color[node]) 
                return false;
        }
    }
    return true;
}

bool isBipartite(int n, vector<int>adj[]){
    vector<int> color(n, -1);
    
    for(int i=0;i<n;i++){
        if(color[i] == -1){
            if(!check(i, adj, color)) return false;
        }
    }
    return true;
}

//DFS method
bool dfs(int node, int col, vector<int> adj[], vector<int> &color){
    
    color[node] = col;
  
    for(auto j: adj[node]){
        if(color[j] == -1){
            if(dfs(j, 1-color[node], adj, color) == false)
                return false;
        }
        else if(color[j] == color[node]) 
            return false;
    }
    return true;
}

bool isBipartite(int n, vector<int>adj[]){
    vector<int> color(n, -1);
    
    for(int i=0;i<n;i++){
        if(color[i] == -1){
            if(!dfs(i, 1, adj, color)) return false;
        }
    }
    return true;
}
