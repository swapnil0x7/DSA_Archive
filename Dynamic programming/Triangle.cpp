//Memoisation
int f(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp, int n){
    if(i==n-1)
        return arr[i][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int down = f(i+1, j, arr, dp, n);
    int diagonal = f(i+1, j+1, arr, dp, n);

    return dp[i][j] = arr[i][j] + min(down, diagonal);
}

int minimumTotal(vector<vector<int>>& arr) {
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int> (n, -1));
    return f(0, 0, arr, dp, n);
}

//Tabulation
int minimumTotal(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int j=0;j<n;j++){
        dp[n-1][j] = arr[n-1][j];
    }

    for(int i=n-2; i>=0; i--){
        for(int j=i;j>=0;j--){
            int down = dp[i+1][j];
            int diagonal = dp[i+1][j+1];
            dp[i][j] = arr[i][j] + min(down, diagonal);
        }
    }
    return dp[0][0];
}

//Space optimised
int minimumTotal(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<int> prev(n, 0);

    for(int j=0;j<n;j++){
        prev[j] = arr[n-1][j];
    }

    for(int i=n-2; i>=0; i--){
        vector<int> curr(n, 0);
        for(int j=i;j>=0;j--){
            int down = prev[j];
            int diagonal = prev[j+1];
            curr[j] = arr[i][j] + min(down, diagonal);
        }
        prev = curr;
    }
    return prev[0];
}
