//Memoization - TC : O(N*2) SC : O(N*2) + recursive stack space
#include<bits/stdc++.h>

long f(int i, int can_buy, long *arr, int n, vector<vector<long>> &dp){
    if(i==n) return 0;

    if(dp[i][can_buy] != -1) return dp[i][can_buy];
    long profit = 0;

    if(can_buy)
        profit = max((-arr[i] + f(i+1, 0, arr, n, dp)), f(i+1, 1, arr, n, dp));
    else
        profit = max((arr[i] + f(i+1, 1, arr, n, dp)), f(i+1, 0, arr, n, dp));
    
    return dp[i][can_buy] = profit;
}

long getMaximumProfit(long *arr, int n)
{
    int buy = 1;
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return f(0, buy, arr, n, dp);
}


//Tabulation 
long getMaximumProfit(long *arr, int n)
{
    int buy = 1;
    vector<vector<long>> dp(n+1, vector<long>(2, 0));
    
    for(int j=0;j<2;j++){
        dp[n][j] = 0;
    }
    for(int i=n-1;i>=0;i--){
        for(int can_buy=1;can_buy>=0;can_buy--){
            long profit = 0;

            if(can_buy)
                profit = max(-arr[i] + dp[i+1][0], dp[i+1][1]);
            else
                profit = max(arr[i] + dp[i+1][1], dp[i+1][0]);
            
            dp[i][can_buy] = profit;
        }
    }
    return dp[0][1];
    
}


//Tabulation space-optimised
long getMaximumProfit(long *arr, int n)
{
    int buy = 1;
    vector<long> ahead(2, 0), curr(2, 0);
    for(int j=0;j<2;j++){
        ahead[j] = 0;
    }
    for(int i=n-1;i>=0;i--){
        for(int can_buy=1;can_buy>=0;can_buy--){
            long profit = 0;

            if(can_buy)
                profit = max(-arr[i] + ahead[0], ahead[1]);
            else
                profit = max(arr[i] + ahead[1], ahead[0]);
            
            curr[can_buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
    
}
