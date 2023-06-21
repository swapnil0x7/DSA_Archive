#include <bits/stdc++.h> 

int f(int i, vector<int> &arr, vector<int> &dp){
    if(i==0) return 0;

    if(dp[i] != -1) return dp[i];

    int one_step = f(i-1, arr, dp) + abs(arr[i] - arr[i-1]);
    int two_step = INT_MAX;
    if(i>1) two_step = f(i-2, arr, dp) + abs(arr[i] - arr[i-2]);
    
    return dp[i] = min(one_step, two_step);
}

int frogJump(int n, vector<int> &arr)
{   
    vector<int> dp(n, -1);
    return f(n-1, arr, dp);
}