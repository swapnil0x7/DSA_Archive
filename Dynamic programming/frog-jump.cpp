#include <bits/stdc++.h> 

//Memoization
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


//Tabulation
int frogJump(int n, vector<int> &arr)
{   
    vector<int> dp(n);
    dp[0] = 0;

    for(int i=1;i<n;i++){
        int one_step = dp[i-1] + abs(arr[i] - arr[i-1]);
        int two_step = INT_MAX;
        if(i>1) two_step = dp[i-2] + abs(arr[i] - arr[i-2]);

        dp[i] = min(one_step, two_step);
    }
    return dp[n-1];
}

//Space Optimised
int frogJump(int n, vector<int> &arr)
{   
    int prev = 0;
    int prev2 = 0;

    for(int i=1;i<n;i++){
        int one_step = prev + abs(arr[i] - arr[i-1]);
        int two_step = INT_MAX;
        if(i>1) two_step = prev2 + abs(arr[i] - arr[i-2]);

        int ans = min(one_step, two_step);
        prev2 = prev;
        prev = ans;
    }
    return prev;
}
