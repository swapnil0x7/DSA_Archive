vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();

    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0)
                q.push({i, j});
            else
                arr[i][j] = -1;       
        }
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        for(int x=0;x<4;x++){
            int row = i + dx[x];
            int col = j + dy[x];

            if(row >= 0 and row < n and col >= 0 and col < m and arr[row][col] == -1){
                arr[row][col] = 1 + arr[i][j];
                q.push({row, col});
            }
        }
    }
    return arr;
}
