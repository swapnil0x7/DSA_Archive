#include<bits/stdc++.h>

class DisjointSet{
  public:
    vector<int> parent, size;
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        
        for(int i=0;i<=n;i++) parent[i] = i;
    }
    
    int findUltimateParent(int node){
        if(node == parent[node]) 
            return node;
        
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int parent_u = findUltimateParent(u);
        int parent_v = findUltimateParent(v);
        
        if(parent_u == parent_v) return;
        
        if(size[parent_u] < size[parent_v]){
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else if(size[parent_u] > size[parent_v]){
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
        else{
            parent[parent_u] = parent_v;
            size[parent_u] += size[parent_v];
        }
    }
};


int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);    
    ds.unionBySize(3, 7);
    //if 3 and 7 are connected or not?
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) 
        cout<<"Same!";
    else
        cout<<"Not same!";
}
