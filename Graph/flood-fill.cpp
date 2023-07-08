//BFS 
void dfs(int i, int j, vector<vector<int>> &res, int original, int newColor, vector<vector<int>> &visited, int n, int m){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j] = 1;
    res[i][j] = newColor;
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        for(int i=0;i<4;i++){
            int new_row = row + dx[i];
            int new_col = col + dy[i];
            
            if(new_row >=0 and new_row <n and new_col >=0 and new_col <m and !visited[new_row][new_col] and res[new_row][new_col] == original){
                visited[new_row][new_col] = 1;
                res[new_row][new_col] = newColor;
                q.push({new_row, new_col});
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int newColor) {
    int n = arr.size();
    int m = arr[0].size();
    
    vector<vector<int>> res = arr;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    int original = arr[sr][sc];
    
    dfs(sr, sc, res, original, newColor, visited, n, m);
    
    return res;
}

//BFS without visited array 
void dfs(int i, int j, vector<vector<int>> &res, int original, int newColor, int n, int m){
    queue<pair<int,int>> q;
    q.push({i,j});
    res[i][j] = newColor;
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        for(int i=0;i<4;i++){
            int new_row = row + dx[i];
            int new_col = col + dy[i];
            
            if(new_row >=0 and new_row <n and new_col >=0 and new_col <m and res[new_row][new_col] != newColor and res[new_row][new_col] == original){
                res[new_row][new_col] = newColor;
                q.push({new_row, new_col});
            }
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int newColor) {
    int n = arr.size();
    int m = arr[0].size();
    
    vector<vector<int>> res = arr;
    
    int original = arr[sr][sc];
    
    dfs(sr, sc, res, original, newColor, n, m);
    
    return res;
}

