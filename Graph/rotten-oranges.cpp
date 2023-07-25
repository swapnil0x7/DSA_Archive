int Solution::solve(vector<vector<int> > &arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> visited(n, vector<int> (m, 0));

    queue<pair<pair<int,int>, int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
        }
    }
    int totalTime = 0;

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int x=0;x<4;x++){
            int n_row = row + dx[x];
            int n_col = col + dy[x];

            if(n_row>=0 and n_row<n and n_col>=0 and n_col<m and arr[n_row][n_col]==1 and visited[n_row][n_col] == 0){
                visited[n_row][n_col] = 2;
                q.push({{n_row, n_col}, time + 1});
                totalTime = max(totalTime, time+1);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1 and visited[i][j] != 2){
                return -1;
            }
        }
    }

    return totalTime;
}
