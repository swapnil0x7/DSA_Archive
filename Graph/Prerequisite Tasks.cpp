//  logic - if there's a cycle tasks are not possible!

// using BFS (Kahn's)                                           
bool isPossible(int n,int p, vector<pair<int, int> >& pairs) {
    vector<int> adj[n];
    
    for(auto i: pairs){
        adj[i.first].push_back(i.second);
    }
    
    vector<int> inDegree(n, 0);
    
    for(int i=0;i<n;i++){
        for(auto j: adj[i]){
            inDegree[j]++;
        }
    }
    
    queue<int> q;
    for(int i=0;i<n;i++) {
        if(inDegree[i] == 0) q.push(i);
    }
    
    vector<int> res;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        
        for(auto j: adj[node]){
            inDegree[j]--;
            if(inDegree[j] == 0) q.push(j);
        }
    }
    
    if(res.size() == n) return true;
    return false;   
}



// using DFS
bool isCycle(int node, vector<int> adj[], vector<int> &visited, vector<int> &path_visited){
    visited[node] = 1;
    path_visited[node] = 1;
    
    for(auto j : adj[node]){
        if(!visited[j]){
            if(isCycle(j, adj, visited, path_visited) == true) 
                return true;
        }
        else if(path_visited[j])
            return true;
    }
    path_visited[node] = 0;
    
    return false;
}

bool isPossible(int n,int p, vector<pair<int, int> >& pairs) {
  vector<int> adj[n];
  
  for(auto i: pairs){
      adj[i.first].push_back(i.second);
  }
  vector<int> visited(n, 0);
  vector<int> path_visited(n, 0);
  
  for(int i=0;i<n;i++){
      if(!visited[i]){
          if(isCycle(i, adj, visited, path_visited) == true) return false;
      }
  }
  return true;
  
}
