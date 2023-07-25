int Solution::knight(int n, int m, int src_x, int src_y, int dest_x, int dest_y) {

    vector<vector<int>> visited(n+1, vector<int>(m+1, 0));
    visited[src_x][src_y] = 1;

    queue<pair<pair<int,int>,int>> q;
    q.push({{src_x, src_y}, 0});

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if(row == dest_x and col == dest_y) return d;

        int dx[] = { -2,-2,-1,1,-1,1,2,2 };
        int dy[] = { -1,1,-2,-2,2,2,-1,1 };

        for(int i=0;i<8;i++){
            int n_row = row + dx[i];
            int n_col = col + dy[i];
            
            if(n_row >= 1 and n_row <= n and n_col >= 1 and n_col <= m and !visited[n_row][n_col]){
                visited[n_row][n_col] = 1;
                q.push({{n_row, n_col}, d+1});
            }
        }
    }
    return -1;
}
