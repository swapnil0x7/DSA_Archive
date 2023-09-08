

// Tabulation
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i: arr) sum += i;

	vector<vector<int>> dp(n, vector<int>(sum+1, 0));

	//base cases
	for(int i=0;i<n;i++) dp[i][0] = true;
	if(arr[0] <= sum) dp[0][arr[0]] = true;

	for(int i=1;i<n;i++){
		for(int target=1;target<=sum;target++){
			bool take = false;
			if(arr[i] <= target) take = dp[i-1][target-arr[i]];
			bool not_take = dp[i-1][target];
			
			dp[i][target] = take or not_take;
		}
	}
	
	int diff = 1e9+7;
	for(int i=0;i<=sum;i++){
		if(dp[n-1][i] == true){
			int s1 = i;
			int s2 = sum - s1;
			diff = min(diff, abs(s1 - s2));
		}
	}
	return diff;
}




// space optimised
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	sum = accumulate(arr.begin(), arr.end(), 0);

	vector<int> prev(sum+1, 0), curr(sum+1, 0);
	
	//base cases
	for(int i=0;i<n;i++) prev[0] = true;
	if(arr[0] <= sum) prev[arr[0]] = true;

	for(int i=1;i<n;i++){
		for(int target=1;target<=sum;target++){
			bool take = false;
			if(arr[i] <= target) take = prev[target-arr[i]];
			bool not_take = prev[target];
			
			curr[target] = take or not_take;
		}
		prev = curr;
	}
	
	int diff = 1e9+7;
	for(int i=0;i<=sum;i++){
		if(prev[i] == true){
			int s1 = i;
			int s2 = sum - s1;
			diff = min(diff, abs(s1 - s2));
		}
	}
	return diff;
}
