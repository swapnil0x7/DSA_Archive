vector<vector<int> > Solution::solve(vector<vector<int> > &arr) {
    int n = arr.size();

    vector<vector<int>> res(n, vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                res[i][j] = 0;
            else if(arr[i][j] == -1) 
                res[i][j] = 1e9;
            else
                res[i][j] = arr[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(res[i][j] == 1e9) res[i][j] = -1;
        }
    }
    return res;

}
