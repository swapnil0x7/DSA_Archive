void dfs(int row, int col, int n, int m, vector<vector<char>> &arr, vector<vector<int>> &visited){
  visited[row][col] = 1;
  
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  
  for(int i=0;i<4;i++){
      int n_row = row + dx[i];
      int n_col = col + dy[i];
      
      if(n_row >=0 and n_row < n and n_col >=0 and n_col < m and arr[n_row][n_col] == 'O' and !visited[n_row][n_col]){
          dfs(n_row, n_col, n, m, arr, visited);
      }
  }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> arr)
{
  
  vector<vector<int>> visited(n, vector<int>(m, 0));
  
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(i==0 or j==0 or i==n-1 or j==m-1){
              if(arr[i][j] == 'O' and !visited[i][j]){
                  dfs(i,j, n, m, arr, visited);
              }
          }
      }
  }
  
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(arr[i][j] == 'O' and !visited[i][j]) arr[i][j] = 'X';       
      }
  }
  return arr;
}
