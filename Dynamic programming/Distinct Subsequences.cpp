// memoisation
int f(int i, int j, string &A, string &B, vector<vector<int>> &dp){
	if(j<0) return 1;
	if(i<0) return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	if(A[i] == B[j]){
		return dp[i][j] = (f(i-1, j-1, A, B, dp) + f(i-1, j, A, B, dp)) % mod;
	}
	else{
		return dp[i][j] = f(i-1, j, A, B, dp) % mod;
	}
}

//tabulation
int distinctSubsequences(string &A, string &B)
{
	int n = A.size(), m = B.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=0;i<=n;i++)
		dp[i][0] = 1;

	for(int j=1;j<=m;j++)
		dp[0][j] = 0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(A[i-1] == B[j-1]){
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
			}
			else{
				dp[i][j] = dp[i-1][j] % mod;
			}
		}
	}
	return dp[n][m];
}



// space optimised
#include<bits/stdc++.h>
int mod = 1e9+7;
int distinctSubsequences(string &A, string &B)
{
	int n = A.size(), m = B.size();
	vector<int> prev(n+1, 0), curr(m+1, 0);
	
	prev[0] = 1;
	curr[0] = 1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(A[i-1] == B[j-1]){
				curr[j] = (prev[j-1] + prev[j]) % mod;
			}
			else{
				curr[j] = prev[j] % mod;
			}
		}
		prev = curr;
	}
	return prev[m];
}
