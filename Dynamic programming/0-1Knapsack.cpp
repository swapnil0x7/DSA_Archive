//Memoization
#include <bits/stdc++.h> 

int f(int i, int W, vector<int> weight, vector<int> value, vector<vector<int>> &dp){
	if(i==0){
		if(weight[0] <= W) return value[0];
		return 0;
	}
	if(dp[i][W] != -1) return dp[i][W];
	
	int not_take = f(i-1, W, weight, value, dp);
	int take = -1e9;
	if(weight[i] <= W) take = value[i] + f(i-1, W-weight[i], weight, value, dp);

	return dp[i][W] = max(take, not_take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  return f(n-1, maxWeight, weight, value, dp);
}




//Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
	
	for(int w=0;w<=maxWeight;w++){
		if(w>=weight[0]) dp[0][w] = value[0];
	}
	for(int i=1;i<n;i++){
		for(int W=0;W<=maxWeight;W++){
			int not_take = dp[i-1][W];
			int take = -1e9;
			if(weight[i] <= W) take = value[i] + dp[i-1][W-weight[i]];

			dp[i][W] = max(take, not_take);
		}
	}
	return dp[n-1][maxWeight];
}

// space optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
	for(int w=0;w<=maxWeight;w++){
		if(w>=weight[0]) prev[w] = value[0];
	}
	for(int i=1;i<n;i++){
		for(int W=0;W<=maxWeight;W++){
			int not_take = prev[W];
			int take = -1e9;
			if(weight[i] <= W) take = value[i] + prev[W-weight[i]];
	
			curr[W] = max(take, not_take);
		}
		prev = curr;
	}
	return prev[maxWeight];
}
