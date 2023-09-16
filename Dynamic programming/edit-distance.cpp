// Memoization -  TC : Exponential (3^N)   SC : O(N*M) + recursive stack space
int f(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){

    if(i<0) return j+1;                        // if str1 is empty then it needs j+1 insertions to become as str2.
    if(j<0) return i+1;                        // if str2 is empty then it needs i+1 deletion from str1 to become as str2.

    if(dp[i][j] != -1) return dp[i][j];

    if(str1[i] == str2[j]) {
        return dp[i][j] = f(i-1, j-1, str1, str2, dp);
    }

    return dp[i][j] = 1 + min(f(i-1, j-1, str1, str2, dp), min(f(i, j-1, str1, str2, dp), f(i-1, j, str1, str2, dp)));      //perform all the operations - delete, insert and replace.
}


int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    return f(n-1, m-1, str1, str2, dp);
}

//SHIFTING OF INDEX for creating the tabulated form 👇
int f(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){

    if(i==0) return j;
    if(j==0) return i;

    if(dp[i][j] != -1) return dp[i][j];

    if(str1[i-1] == str2[j-1]) {
        return f(i-1, j-1, str1, str2, dp);
    }

    return dp[i][j] = 1 + min(f(i-1, j-1, str1, str2, dp), min(f(i, j-1, str1, str2, dp),f(i-1, j, str1, str2, dp)));
}


int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    return f(n, m, str1, str2, dp);
}


// tabulation
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for(int j=0;j<=m;j++) dp[0][j] = j;
    
    for(int i=0;i<=n;i++) dp[i][0] = i;
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
        }
    }

    return dp[n][m];
}

// space optimised
class Solution {
public:
    int minDistance(string A, string B) {
        int n = A.size(), m = B.size();
        
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int j=0;j<=m;j++){
            prev[j] = j;                // base case 1
        }

        for(int i=1;i<=n;i++){
            curr[0] = i;                // base case 2
            for(int j=1;j<=m;j++){
                if(A[i-1] == B[j-1])
                    curr[j] = prev[j-1];
                else{
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    int insert = 1 + curr[j-1];
                    curr[j] = min(del, min(replace, insert));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
