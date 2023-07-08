
void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &s){
    visited[node] = 1;
    
    for(auto j: adj[node]){
	if(!visited[j]){
	    dfs(j, adj, visited, s);
	}
    }
    s.push(node);
}
 
vector<int> topoSort(int n, vector<int> adj[]) 
{
    vector<int> res;
    stack<int> s;
    vector<int> visited(n,0);
    
    for(int i=0;i<n;i++){
	if(!visited[i])
	    dfs(i, adj, visited, s);
    }
    
    while(!s.empty()){
	res.push_back(s.top());
	s.pop();
    }
    return res;
}
