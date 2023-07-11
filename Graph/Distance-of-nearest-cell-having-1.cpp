vector<vector<int>>nearest(vector<vector<int>>arr)
{
    int n = arr.size();
    int m = arr[0].size();
    
    vector<vector<int>> visited(n, vector<int> (m, 0));
    vector<vector<int>> dist(n, vector<int> (m, 0));
    
    queue<pair<pair<int,int>,int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1){
                q.push({{i,j}, 0});
                visited[i][j] = 1;
            }
        }
    }
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int d = q.front().second;
        dist[row][col] = d;
        q.pop();
        
        for(int i=0;i<4;i++){
            int n_row = row + dx[i];
            int n_col = col + dy[i];
            
            if(n_row >=0 and n_row<n and n_col >=0 and n_col<m and arr[n_row][n_col] == 0 and !visited[n_row][n_col]){
                    visited[n_row][n_col] = 1;
                    q.push({{n_row, n_col}, d+1});
            }
        }
    }
    return dist;
    
}
