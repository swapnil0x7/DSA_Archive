// Memoization
int f(int i, int j, vector<vector<int>> &dp){
	if(i==0 and j==0) 
		return 1;
		
	if(i<0 or j<0)
		return 0;
	
	if(dp[i][j] != -1) 
		return dp[i][j];
	
	int up = f(i-1, j, dp);
	int left = f(i, j-1, dp);
	
	return dp[i][j] = up+left;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(n, vector<int>(m, -1));
	return f(n-1, m-1, dp);
}


// Tabulation
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(n, vector<int>(m, 0));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 and j==0) dp[i][j] = 1;
			else{
				int up = 0, left = 0;
				if(i-1>=0) up = dp[i-1][j];
				if(j-1>=0) left = dp[i][j-1];
				dp[i][j] = up + left;
			}
		}
	}
	return dp[n-1][m-1];
}


//Space optimised
int uniquePaths(int m, int n) {
    vector<int> prev(m, 0);
    
    for(int i=0;i<n;i++){
        vector<int> curr(m, 0);

        for(int j=0;j<m;j++){
            if(i==0 and j==0) curr[j] = 1;
            else{
                int up = 0, left = 0;
                if(i-1>=0) up = prev[j];
                if(j-1>=0) left = curr[j-1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}
