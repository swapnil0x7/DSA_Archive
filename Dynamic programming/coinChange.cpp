//Memoization - TC : O(N*K)  SC : O(N*K) + recursive stack space
#include <bits/stdc++.h>

long f(int i, int sum, int *arr, vector<vector<long>> &dp){
	
	if(i==0){
		if(sum % arr[0] == 0) return 1;
		return 0;
	}
	
	if(dp[i][sum] != -1) return dp[i][sum];
	
	long not_take = f(i-1, sum, arr, dp);
	long take = 0;
	if(arr[i] <= sum) take = f(i, sum-arr[i], arr, dp);

	return dp[i][sum] = take + not_take;
}

long countWaysToMakeChange(int *arr, int n, int k)
{
    vector<vector<long>> dp(n, vector<long>(k+1, -1));
	return f(n-1, k, arr, dp);
}

//Tabulation - TC : O(N*K)  SC : O(N*K)
#include <bits/stdc++.h>

long countWaysToMakeChange(int *arr, int n, int k)
{
    vector<vector<long>> dp(n, vector<long>(k+1, 0));

  	for(int sum=0;sum<=k;sum++){
  		if(sum%arr[0] == 0) 
  			dp[0][sum] = 1;
  	}	

  	for(int i=1;i<n;i++) {
        for (int sum = 0; sum <= k; sum++) {
            long not_take = dp[i - 1][sum];
            long take = 0;
            if (arr[i] <= sum) take = dp[i][sum-arr[i]];
            dp[i][sum] = take + not_take;
  		  }
  	}
  	return dp[n-1][k];
}

// space optimisation
#include<bits/stdc++.h>
long countWaysToMakeChange(int *arr, int n, int value)
{
    
    vector<long> prev(value+1, 0), curr(value+1, 0);
    for(int i=0;i<n;i++){
        prev[0] = 1;
    }
    for(int t=0;t<=value;t++){
        prev[t] = (t % arr[0] == 0);
    }

    for(int i=1;i<n;i++){
        for(int target=0;target<=value;target++){
            long not_take = prev[target];
            long take = 0;
            if(arr[i] <= target) take = curr[target - arr[i]];

            curr[target] = take + not_take;
        }
        prev = curr;
    }
    return prev[value];
}
