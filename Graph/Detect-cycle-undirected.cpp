//BFS -> TC : O(N+2E) SC : O(N)
bool checkCycle(int node, vector<int> adj[], vector<int> &visited){
    queue<pair<int,int>>q;
    q.push({node, -1});
    
    visited[node] = 1;
    
    while(!q.empty()){
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto j: adj[curr]){
            if(!visited[j]){
                visited[j] = 1;
                q.push({j, curr});
            }
            else if(parent != j){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[]) {
    vector<int> visited(n, 0);
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if( checkCycle(i, adj, visited) == true)
                return true;
        }
    }
    return false;
}

//DFS -> TC : O(N+2E) SC : O(N)
bool dfs(int node, int parent, vector<int> &visited, vector<int> adj[]) {
    visited[node] = 1; 
    
    for(auto j: adj[node]) {
        
        if(!visited[j]) {
            if(dfs(j, node, visited, adj) == true) 
                return true; 
        }
        
        else if(j != parent) return true; 
    }
    return false; 
}

bool isCycle(int n, vector<int> adj[]) {
    
    vector<int> visited(n, 0);
    
    for(int i = 0;i<n;i++) {
       if(!visited[i]) {
           if(dfs(i, -1, visited, adj) == true) return true; 
       }
   }
   return false; 
}
