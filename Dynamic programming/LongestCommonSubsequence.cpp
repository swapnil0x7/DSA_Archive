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

//Space Optimization
int Solution::solve(string A, string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    for(int j=0;j<=m;j++) prev[j] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1] == B[j-1]) 
                curr[j] = 1 + prev[j-1];
            else
                curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }

    return prev[m];
}

// Printing LCS
int main(){
    string a = "abcde";
    string b = "ace";
    
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans = "";
    int i = n, j = m;
    while(i>=1 and j>=1){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }    
        else{
            j--;
        }
        
    }
    reverse(ans.begin(), ans.end());
    cout<< ans;
    
}


💡 // Minimum Insertions/Deletions to Convert String A to String B - https://www.youtube.com/watch?v=yMnH0jrir0Q&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=31
💡 // Minimum Insertions to Make String Palindrome - https://www.youtube.com/watch?v=xPBLEj41rFU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=30
💡 // Longest Palindromic Subsequence - https://www.youtube.com/watch?v=6i_T5kkfv4A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=30
💡 // Longest Common Substring - https://www.youtube.com/watch?v=_wP9mWNPL5w&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=28
