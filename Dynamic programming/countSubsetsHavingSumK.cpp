
//Memoization - TC: O(N*K)  SC: O(N*M) + recursion stack space
#include<bits/stdc++.h>

int f(int i, vector<int> & arr, int target, vector<vector<int>> &dp){
	if(target == 0) return 1;
	if(i==0) return(arr[i] == target);
	if(dp[i][target] != -1) return dp[i][target];
	int notPick = f(i-1, arr, target, dp);
	int pick =0;
	if(arr[i] <= target) pick = f(i-1, arr, target- arr[i], dp);
	return dp[i][target] = pick + notPick;
}

int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(tar+1, -1));
	return f(n-1, num, tar, dp);
}


//Tabulation - TC: O(N*K)  SC: O(N*M)
int findWays(vector<int> &arr, int k)
{
	int n = arr.size();
	int mod = 1e9+7;
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	
	for(int i=0;i<n;i++) dp[i][0] = 1;
	if(arr[0] <= k) dp[0][arr[0]] = 1;
	
	for(int i=1;i<n;i++){
		for(int target = 1; target<=k; target++){
			int notPick = dp[i-1][target];
			int pick =0;
			if(arr[i] <= target) pick = dp[i-1][target-arr[i]];
			dp[i][target] = (pick + notPick)%mod;
		}
	}
	return dp[n-1][k]%mod;
}

