vector<int> topoSort(int n, vector<int> adj[]) {
    vector<int> inDegree(n, 0);
    
    for(int i=0;i<n;i++){
        for(auto j: adj[i]) inDegree[j]++;
    }
    
    queue<int> q;
    
    for(int i=0;i<n;i++){
        if(inDegree[i] == 0) q.push(i);
    }
    
    vector<int> res;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        
        for(auto j: adj[curr]){
            inDegree[j]--;
            if(inDegree[j] == 0) q.push(j);
        }
    }
    return res;
}
