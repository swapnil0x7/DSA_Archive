//Memoization with 3-D dp.  TC - O(N*2*3) + rec. stack space!

#include <bits/stdc++.h> 

int f(int i, int can_buy, int cap, vector<int> &arr, int n, vector<vector<vector<int>>> &dp){
    if(i==n or cap == 0) 
        return 0; 
    
    if(dp[i][can_buy][cap] != -1) return dp[i][can_buy][cap];

    int profit = 0;
    if(can_buy){
        profit = max( -arr[i] + f(i+1, 0, cap, arr, n, dp), f(i+1, 1, cap, arr, n, dp));
    }
    else{
        profit = max( arr[i] + f(i+1, 1, cap-1, arr, n, dp), f(i+1, 0, cap, arr, n, dp));
    }
    return dp[i][can_buy][cap] = profit;
}

int maxProfit(vector<int>& arr, int n)
{
    int can_buy = 1;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, can_buy, 2, arr, n, dp);
}



//Tabulation
int maxProfit(vector<int>& arr, int n)
{
    int can_buy = 1;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    
    //no need to write base cases specifically as it is already set to zero.(line 6, line 34).
    
    for(int i=n-1;i>=0;i--){
        for(int can_buy = 0;can_buy<=1;can_buy++){
            for(int cap = 1;cap<=2;cap++){
                int profit = 0;
                if(can_buy == 1){
                    profit = max(-arr[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                }
                else{
                    profit = max( arr[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
                dp[i][can_buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}

//Tabulation with space optimization
int maxProfit(vector<int>& arr, int n)
{
    int can_buy = 1;
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    
    for(int i=n-1;i>=0;i--){
        for(int can_buy = 0;can_buy<=1;can_buy++){
            for(int cap = 1;cap<=2;cap++){
                int profit = 0;
                if(can_buy == 1){
                    profit = max(-arr[i] + after[0][cap], after[1][cap]);
                }
                else{
                    profit = max( arr[i] + after[1][cap-1], after[0][cap]);
                }
                curr[can_buy][cap] = profit;
            }
        }
        after = curr;
    }

    return after[1][2];


}
