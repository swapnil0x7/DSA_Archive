//Memoisation
int f(int i, int j, vector<vector<int>> &arr, vector<vector<int>>&dp){
    if(i==0 and j==0)
        return arr[i][j];
    if(i<0 or j<0)
        return 1e9;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = arr[i][j] + f(i-1, j, arr, dp);
    int left = arr[i][j] + f(i, j-1, arr, dp);
    
    return dp[i][j] = min(up, left);
}

int minPathSum(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m,-1));

    return f(n-1, m-1, arr, dp);
}

//Tabulation
int minPathSum(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0) {
                dp[i][j] = arr[i][j];
            }
            else {
                int up = 1e9, left = 1e9;
                if(i-1>=0) up = dp[i-1][j];
                if(j-1>=0) left = dp[i][j-1];
                
                dp[i][j] = arr[i][j] + min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}

//Space optimisation
int minPathSum(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    vector<int> prev(m, 0);

    for(int i=0;i<n;i++){
        vector<int> curr(m, 0);
        for(int j=0;j<m;j++){
            if(i==0 and j==0) {
                curr[j] = arr[i][j];
            }
            else {
                int up = 1e9, left = 1e9;
                if(i-1>=0) up = prev[j];
                if(j-1>=0) left = curr[j-1];
                
                curr[j] = arr[i][j] + min(up, left);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}
