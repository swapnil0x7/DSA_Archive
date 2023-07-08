void bfs(int i, int j, vector<vector<char>> arr, vector<vector<int>> &visited, int n, int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int new_row = row + i;
                    int new_col = col + j;
                    
                    if(new_row >= 0 and new_row <n and new_col >=0 and new_col<m and arr[new_row][new_col] == '1' and !visited[new_row][new_col]){
                        visited[new_row][new_col] = 1;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] and arr[i][j] == '1'){
                    visited[i][j] = 1;
                     count++;
                    bfs(i, j, arr, visited, n, m);
                }
            }
        }
        return count;
    }
