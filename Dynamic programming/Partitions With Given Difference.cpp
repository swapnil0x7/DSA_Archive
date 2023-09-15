// Memoisation
#include <bits/stdc++.h> 
int mod = 1e9+7;

int f(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(i==0){
        if(target == 0 and arr[0] == 0)
            return 2;
            
        if(target == 0 or target - arr[0] == 0)
            return 1;
        
        return 0;
    }
    if(dp[i][target] != -1)
        return dp[i][target];
    
    int not_take = f(i-1, target, arr, dp);
    int take = 0;
    if(arr[i] <= target){
        take = f(i-1, target - arr[i], arr, dp);
    }
    return dp[i][target] = (take % mod+ not_take % mod) % mod;
}


int countPartitions(int n, int d, vector<int> &arr) {
    
    int total = accumulate(arr.begin(), arr.end(), 0);
    
    int target = (total - d)/2;

    if((total - d) < 0 or (total - d) % 2 != 0)
        return 0; 

    vector<vector<int>> dp(n, vector<int> (target+1, -1));

    return f(n-1, target, arr, dp);
}

// Tabulation
