//Memoization - TC: O(N*K)  SC: O(N*K) + recursion stack space
#include <bits/stdc++.h> 

int f(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
  	if(i==0){
  		if(sum%arr[0] == 0) return sum/arr[0];
  		return 1e9;
  	}
  	if(dp[i][sum] != -1) return dp[i][sum];
  	
  	int not_take = f(i-1, sum, arr, dp);
  	int take = INT_MAX;
  	if(arr[i] <= sum) take = 1 + f(i, sum-arr[i], arr, dp);
  	
  	return dp[i][sum] = min(take, not_take);
  	
}

int minimumElements(vector<int> &arr, int k)
{
    int n = arr.size();
  	vector<vector<int>> dp(n, vector<int>(k+1, -1));
  	int ans = f(n-1, k, arr, dp);
  	if(ans >= 1e9) return -1;
  	else return ans;
}

//Tabulation - TC: O(N*K)  SC: O(N*K)
#include <bits/stdc++.h> 
int minimumElements(vector<int> &arr, int k)
{
    int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	
	for(int sum=0; sum<=k; sum++){
		if(sum % arr[0] == 0) dp[0][sum] = sum/arr[0];
		else dp[0][sum] = 1e9;                                      //Do not use INT_MAX as adding one to it causes overflow. 
	}
	for(int i=1;i<n;i++){
		for(int sum = 0;sum<=k;sum++){
			int not_take = dp[i-1][sum];
			int take = INT_MAX;
			if(arr[i] <= sum) take = 1 + dp[i][sum-arr[i]];
			
			dp[i][sum] = min(take, not_take);
		}
	}
	int ans = dp[n-1][k];
	if(ans >= 1e9) return -1;
	return ans;
}
