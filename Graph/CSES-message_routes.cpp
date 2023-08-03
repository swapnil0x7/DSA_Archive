#include<bits/stdc++.h>
using namespace std;

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
    
    queue<int> q;
    q.push(1);
    
    vector<int> dist(n+1, 1e9);
    dist[1] = 0;
    
    vector<int> parent(n+1);
    parent[1] = 1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto j: adj[node]){
            if(dist[j] > dist[node] + 1){
                parent[j] = node;
                dist[j] = dist[node] + 1;
                q.push(j);
            }
        }
    }
    
    if(dist[n] == 1e9){
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else{
        int idx = n;
        vector<int> ans;

        while(idx != parent[idx]){
            ans.push_back(idx);
            idx = parent[idx];
        }
        ans.push_back(idx);

        cout<<dist[n] + 1<<"\n";
        while(ans.size() > 0){
            cout<<ans.back()<<" ";
            ans.pop_back();
        }
    }
    
}
