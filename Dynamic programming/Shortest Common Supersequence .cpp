class Solution {
public:
  string shortestCommonSupersequence(string a, string b) {
      int n = a.size(), m = b.size();
      vector<vector<int>> dp(n+1, vector<int> (m+1, 0));  
      
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(a[i-1] == b[j-1])
                  dp[i][j] = 1 + dp[i-1][j-1];
              else
                  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
      }
      string ans = "";
      int i=n, j=m;                          // we only add the common characters once, which are part of lcs.
      while(i>0 and j>0){                    // the main idea is to include the non-common characters (which aren't the part of LCS)
          if(a[i-1] == b[j-1]){
              ans += a[i-1];
              i--, j--;
          }
          else if(dp[i-1][j] > dp[i][j-1]){
              ans+= a[i-1];
              i--;
          }
          else{
              ans += b[j-1];
              j--;
          }
      }
      while(i>0){
          ans += a[i-1];
          i--;
      }
      while(j>0){
          ans += b[j-1];
          j--;
      }
      reverse(ans.begin(), ans.end());
      return ans;
  }
};
