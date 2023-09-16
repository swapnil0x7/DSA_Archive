#include<bits/stdc++.h>
int mod = 1e9+7;

int distinctSubsequences(string &A, string &B)
{
	int n = A.size(), m = B.size();
	vector<int> prev(n+1, 0), curr(m+1, 0);
	
	prev[0] = 1;
	curr[0] = 1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(A[i-1] == B[j-1]){
				curr[j] = (prev[j-1] + prev[j]) % mod;
			}
			else{
				curr[j] = prev[j] % mod;
			}
		}
		prev = curr;
	}
	return prev[m];
}
