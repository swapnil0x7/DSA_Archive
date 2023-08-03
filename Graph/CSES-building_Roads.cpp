#include<bits/stdc++.h>

void dfs(int node, vector<int> adj[], vector<int> &visited){
    visited[node] = 1;
    
    for(auto j: adj[node]){
        if(!visited[j]){
            dfs(j, adj, visited);
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    
    vector<int> adj[n+1];
    
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int components = 0;
    vector<int> edges;
    
    vector<int> visited(n+1, 0);
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            components++;
            dfs(i, adj, visited);
            edges.push_back(i);
        }
    }
    cout<<components-1<<endl;
    
    for(int i=1;i<edges.size();i++){
        cout<<edges[i-1]<<" "<<edges[i]<<"\n";
    }
    
}
