//Memoization - TC : O(N*Weight)  SC : O(N*Weight) + recursive stack space
#include <bits/stdc++.h> 

int f(int i, int W, vector<int> &profit, vector<int> &weights, vector<vector<int>> dp){
	if(i==0){
		return profit[0] * (W / weights[0]);
	}
	
	if(dp[i][W] != -1) return dp[i][W];

	int not_take = f(i-1, W, profit, weights, dp);
	int take = -1e9;
	if(weights[i] <= W) take = profit[i] + f(i, W-weights[i], profit, weights, dp);

	return dp[i][W] = max(not_take, take);
}

int unboundedKnapsack(int n, int Weight, vector<int> &profit, vector<int> &weights)
{
    vector<vector<int>> dp(n, vector<int> (Weight+1, -1));
	  return f(n-1, Weight, profit, weights, dp);
}



//Tabulation - TC : O(N*Weight)  SC : O(N*Weight)
int unboundedKnapsack(int n, int Weight, vector<int> &profit, vector<int> &weights)
{
    vector<vector<int>> dp(n, vector<int> (Weight+1, 0));

	for(int w=0;w<=Weight;w++){
		dp[0][w] = profit[0] * (w / weights[0]);
	}

	for(int i=1;i<n;i++){
		for(int W=0;W<=Weight;W++){
			int not_take = dp[i-1][W];
			int take = -1e9;
			if(weights[i] <= W) take = profit[i] + dp[i][W-weights[i]];

			dp[i][W] = max(not_take, take);
		}
	}
	return dp[n-1][Weight];
}
