vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    vector<int> res;
    vector<bool> visited(n, false);
    visited[0] = 1;
    
    queue<int> q;
    q.push(0);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        
        for(auto j: adj[curr]){
            if(!visited[j]){
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    return res;
}