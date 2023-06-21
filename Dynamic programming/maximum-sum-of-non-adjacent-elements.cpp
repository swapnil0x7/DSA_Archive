#include <bits/stdc++.h> 

//Memoization
int f(int i, vector<int> &dp, vector<int> arr){        //every f(i) -> max sum of of non-adjacent elements till that index.
    if(i<0) return 0;

    if(dp[i] != -1) return dp[i];

    int pick = arr[i] + f(i-2, dp, arr);
    int not_pick = f(i-1, dp, arr);

    return dp[i] = max(pick, not_pick);
}

int maximumNonAdjacentSum(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, -1);
    return f(n-1, dp, arr);
}

//Tabulation
int maximumNonAdjacentSum(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n);
    
    dp[0] = arr[0];                     //if the function has reached index=0, that means index=1 has not been picked that's why dp[0] = arr[0].

    for(int i=1;i<n;i++){

        int pick = arr[i];
        if(i>1) pick += dp[i-2];
        int not_pick = dp[i-1];

        dp[i] = max(pick, not_pick);
    }

    return dp[n-1];
}

//Space-optimised 

int maximumNonAdjacentSum(vector<int> &arr){                    //SC - O(1)
    int n = arr.size();
    
    int prev = arr[0];
    int prev2 = 0;

    for(int i=1;i<n;i++){

        int pick = arr[i];
        if(i>1) pick += prev2;
        int not_pick = prev;

        int ans = max(pick, not_pick);
        prev2 = prev;
        prev = ans;
    }

    return prev;
}
