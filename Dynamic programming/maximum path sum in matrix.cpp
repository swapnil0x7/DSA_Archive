// Memoization
#include<bits/stdc++.h>

int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
	if(i==0) return mat[i][j];
	
	if(j<0 or j>=mat[0].size()) return -1e9;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int up = f(i-1,j,mat,dp);
	int ld = f(i-1,j-1,mat,dp);
	int rd = f(i-1,j+1,mat,dp);

	return dp[i][j] = mat[i][j] + max(up, max(ld,rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
	int m = matrix[0].size();
	
	vector<vector<int>> dp(n, vector<int>(m,-1));

	int res = -1e9;
	for(int j=0;j<m;j++){
		res = max(res, f(n-1,j,matrix, dp));
	}
	return res;
}


// Taulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0)); 

	for(int j=0;j<m;j++){
		dp[0][j] = matrix[0][j];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			int up = dp[i-1][j];
			
			int ld = -1e9;
			if(j-1>=0) ld= dp[i-1][j-1];
			
			int rd = -1e9;
			if(j+1<m) rd= dp[i-1][j+1];
			
			dp[i][j] = matrix[i][j] + max(up, max(ld,rd));
		}
	}
	int res = -1e9;
	for(int j=0;j<m;j++){
		res = max(res, dp[n-1][j]);
	}
	return res;
}


//space optimised
int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> dp(n, vector<int>(m, -1)); 
	vector<int> prev(m, 0);

	for(int j=0;j<m;j++){
		prev[j] = matrix[0][j];
	}

	for(int i=1;i<n;i++){
		vector<int> curr(m, 0);
		for(int j=0;j<m;j++){
			int up = prev[j];
			
			int ld = -1e9;
			if(j-1>=0) ld= prev[j-1];
			
			int rd = -1e9;
			if(j+1<m) rd= prev[j+1];
			
			curr[j] = matrix[i][j] + max(up, max(ld,rd));
		}
		prev = curr;
	}
	int res = -1e9;
	for(int j=0;j<m;j++){
		res = max(res, prev[j]);
	}
	return res;
}
