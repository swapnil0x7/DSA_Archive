class DisjointSet{
    public:
    vector<int> parent, rank, size;
    
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int node){
        if(node == parent[node]) 
            return node;
        
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int parent_u = findUltimateParent(u);
        int parent_v = findUltimateParent(v);
        
        if(parent_u == parent_v) return;
        
        if(rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        else if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }
        else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
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
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};


class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int n) {
        
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j] == 1) ds.unionBySize(i, j);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i) count++;
        }
        return count;
    }
};
