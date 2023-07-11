vector<int> findOrder(int n, int m, vector<vector<int>> pairs) {
  
  vector<int> adj[n];
  
  for(auto i: pairs){
      adj[i[1]].push_back(i[0]);
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
  
  if(res.size() == n) return res;
  return {};
}
