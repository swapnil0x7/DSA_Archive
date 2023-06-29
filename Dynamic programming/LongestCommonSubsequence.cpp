//Memoization without shifting of index
#include<bits/stdc++.h>
int f(int i, int j, string a, string b, vector<vector<int>> &dp){
    
    if(i<0 or j<0) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(a[i] == b[j]) return 1 + f(i-1, j-1, a, b, dp);
    
    return dp[i][j] = max(f(i, j-1, a, b, dp), f(i-1, j, a, b, dp));
    
}

int lcs(string a, string b)
{
	int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n-1, m-1, a, b, dp);
}



//Memoization with shifting of index (important step for tabulation)
#include<bits/stdc++.h>
int f(int i, int j, string a, string b, vector<vector<int>> &dp){
    
    if(i==0 or j==0) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(a[i-1] == b[j-1]) return 1 + f(i-1, j-1, a, b, dp);
    
    return dp[i][j] = max(f(i, j-1, a, b, dp), f(i-1, j, a, b, dp));
    
}

int lcs(string a, string b)
{
	int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return f(n, m, a, b, dp);
}

//Tabulation
int lcs(string a, string b)
{
	int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1];
            else    
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }   
    }
    return dp[n][m];
}

🍕 //ALSO DO THE LONGEST PALINDROMIC SUBSEQUENCE PROBLEM, IT'S RELATED TO THIS. 
