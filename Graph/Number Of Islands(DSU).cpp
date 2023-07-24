class DisjointSet{
    
  public:
      vector<int> parent, size;
      
      DisjointSet(int n){
          parent.resize(n+1);
          size.resize(n+1, 1);
          for(int i=0;i<=n;i++) parent[i] = i;
      }
      
      int findUltimateParent(int node){
          if(parent[node] == node) return node;
          
          return parent[node] = findUltimateParent(parent[node]);
      }
      
      void unionBySize(int u, int v){
          int parent_u = findUltimateParent(u);
          int parent_v = findUltimateParent(v);
          
          if(parent_u == parent_v) return;
          
          if(size[parent_u] > size[parent_v]){
              parent[parent_v] = parent_u;
              size[parent_u] += size[parent_v];
          }
          else if(size[parent_u] < size[parent_v]){
              parent[parent_u] = parent_v;
              size[parent_v] += size[parent_u];
          }
          else{
              parent[parent_v] = parent_u;
              size[parent_u] += size[parent_v];
          }
          return;
      }
};


class Solution {
public:
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &queries) {
      
      int visited[n][m];
      memset(visited, 0, sizeof visited);
      int count = 0;
      vector<int> res;
      
      DisjointSet ds(n*m);
      
      for(auto v: queries){
          int row = v[0];
          int col = v[1];
          
          if(visited[row][col] == 1){
              res.push_back(count);
              continue;
          }
          
          visited[row][col] = 1;
          count++;
          
          int dx[] = {-1, 1, 0, 0};
          int dy[] = {0, 0, -1, 1};
          
          for(int i=0;i<4;i++){
              int new_row = row + dx[i];
              int new_col = col + dy[i];
              
              if(new_row>=0 and new_row<n and new_col >=0 and new_col<m){
                  if(visited[new_row][new_col] == 1){
                      int node = row * m + col;
                      int new_node = new_row * m + new_col;
                      
                      if(ds.findUltimateParent(node) != ds.findUltimateParent(new_node)){
                          ds.unionBySize(node, new_node);
                          count--;
                      }
                  }
              }
          }
          res.push_back(count);
      }
      return res;
  }
};
