//Memoization - TC: O(N*sum) SC: O(N*sum) + recursion stack space 

#include <bits/stdc++.h> 

bool f(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
	if(sum == 0) return true;
	if(i==0) return arr[i] == sum;
	if(dp[i][sum] != -1) return dp[i][sum];
	
	bool take = false;
	if(arr[i] <= sum) take = f(i-1,sum-arr[i], arr, dp);
	bool not_take = f(i-1, sum, arr, dp);
	
	return dp[i][sum] = take or not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp);
}

//Tabulation - TC: O(N*sum) SC:O(N*sum) ~no recursion stack space
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<bool>> dp(n, vector<bool>(k+1, false));
	
	//base cases
	for(int i=0;i<n;i++) dp[i][0] = true;
	dp[0][arr[0]] = true;                          //from line 7, this of this as, for i==0 any index of sum (col) having value == arr[0] is true. 

  //recurrance relation
	for(int i=1;i<n;i++){
		for(int target=1;target<=k;target++){
			bool take = false;
			if(arr[i] <= target) take = dp[i-1][target-arr[i]];
			bool not_take = dp[i-1][target];
			
			dp[i][target] = take or not_take;
		}
	}
	return dp[n-1][k];	
}
