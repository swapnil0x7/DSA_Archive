#include <bits/stdc++.h> 
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i<0 or j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return 1 + f(i-1, j-1, s1, s2, dp);

    return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
}

int minInsertion(string &s1)
{
    int n = s1.size();
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int longest =  f(n-1, n-1, s1, s2, dp);

    return n-longest;                                    // the only observation and problem ends!

}

// NOTE: Use the most efficient lcs code above.
