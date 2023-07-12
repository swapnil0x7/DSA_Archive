// Dijkstra's algo using QUEUE (bfs) technique since the distance increases uniformly so we don't need priority_queue. 

int shortestPath(vector<vector<int>> &arr, pair<int, int> source, pair<int, int> destination) {
    int n = arr.size();
    int m = arr[0].size();
    
    if(source.first==destination.first && source.second==destination.second)     // when source == destination
        return 0; 
    
    vector<vector<int>> dist(n, vector<int> (m, 1e9));
    dist[source.first][source.second] = 0;
    
    queue<pair<int, pair<int,int>>> q;
    q.push({0, {source.first, source.second}});
    
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    while(!q.empty()){
        int row = q.front().second.first;
        int col = q.front().second.second;
        int w = q.front().first;
        q.pop();
        
        for(int i=0;i<4;i++){
            int n_row = row + dx[i];
            int n_col = col + dy[i];
            
            if(n_row>=0 and n_row < n and n_col>=0 and n_col < m and arr[n_row][n_col] == 1 and dist[n_row][n_col] > 1 + w){
                
                dist[n_row][n_col] = 1 + w;
                if(n_row == destination.first and n_col == destination.second)        
                    return 1+w;
                q.push({1+w, {n_row, n_col}});
            }
        }
        
    }
    return -1;
}



// simple DFS (using visited array instead of distance arr) -> basically the same thing in this question!
int shortestPath(vector<vector<int>> &arr, pair<int, int> source, pair<int, int> destination) {
    int n = arr.size();
    int m = arr[0].size();
    
    if(source.first==destination.first && source.second==destination.second)     // when source == destination
    return 0; 
    
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});
    
    while(!q.empty()){
        int row = q.front().second.first;
        int col = q.front().second.second;
        int dist = q.front().first;
        q.pop();
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        for(int i=0;i<4;i++){
             int n_row = row + dx[i];
             int n_col = col + dy[i];
             
             if(n_row>=0 and n_row < n and n_col>=0 and n_col < m and arr[n_row][n_col] == 1 and !visited[n_row][n_col]){
                 visited[n_row][n_col] = 1;
                 if(n_row == destination.first and n_col == destination.second) return 1 + dist;
                 q.push({1 + dist, {n_row, n_col}});
             }
        }
    }
    return -1;
}
