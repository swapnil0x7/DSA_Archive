//learn how to traverse diagonally in a 2-D matrix.
int Solution::solve(string A) {
    int n = A.size();

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    
    for(int gap=0;gap<n;gap++){
        int si=0, ei=gap;
        while(ei < n){
            if(gap == 0) dp[si][ei] = true;
            else if(gap == 1) dp[si][ei] = A[si] == A[ei];
            else{
                if(A[si] != A[ei]) 
                    dp[si][ei] = false;
                else
                    dp[si][ei] = dp[si+1][ei-1];
            }
            si++;
            ei++;
        }
    }
    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] == true) count++;
        }
    }
    return count;
}
