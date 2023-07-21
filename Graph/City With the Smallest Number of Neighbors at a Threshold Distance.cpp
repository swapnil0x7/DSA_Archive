int findCity(int n, int m, vector<vector<int>>& edges, int threshold) {
        
    vector<vector<int>> arr(n, vector<int>(n, 1e9));
    
    for(auto it: edges){
        int i = it[0];
        int j = it[1];
        int w = it[2];
        arr[i][j] = w;
        arr[j][i] = w;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) arr[i][j] = 0;
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][k] == 1e9 or arr[k][j] == 1e9)
                    continue;
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    
    int city = -1;
    int lowest = n;
    
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i][j] <= threshold){
                count++;
            }
        }
        if(count <= lowest){
            city = i;
            lowest = count;
        }
    }
    return city;
    
}
