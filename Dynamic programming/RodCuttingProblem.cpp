//Memoization - TC : O(N*Length)  SC : O(N*length) + recursion stack space

int f(int i, int length, vector<int> &arr, vector<vector<int>> &dp){
	
	if(i==0){
		return arr[i] * length;			    //even if length becomes zero, it will return 0 cost.
	}

	if(dp[i][length] != -1) return dp[i][length];

	int rod_length = i+1;
	int not_take = f(i-1, length, arr, dp);
	int take = -1e9;
	if(rod_length <= length) take = arr[i] + f(i, length-rod_length, arr, dp);            

	return dp[i][length] = max(take, not_take);
}

int cutRod(vector<int> &arr, int length)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(length+1, -1));
	return f(n-1, length, arr, dp);
}



//Tabulation - TC : O(N*Length)  SC : O(N*length)

int cutRod(vector<int> &arr, int length)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(length+1, 0));
	
	for(int l = 0; l<=length; l++){                            //base case from line 5
		dp[0][l] = arr[0] * l;
	}

	for(int i=1;i<n;i++){
		for(int l = 0; l<= length; l++){
			int rod_length = i+1;
			int not_take = dp[i-1][l];
			int take = -1e9;
			if(rod_length <= l) take = arr[i] + dp[i][l-rod_length];

			dp[i][l] = max(take, not_take);
		}
	}
	return dp[n-1][length];
}
