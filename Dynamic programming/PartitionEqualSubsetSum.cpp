bool f(int n, int k, vector<int> &arr) {
	vector<vector<bool>> dp(n, vector<bool>(k+1, false));
	
	//base cases
	for(int i=0;i<n;i++) dp[i][0] = true;
	dp[0][arr[0]] = true;                          //from line 7, this of this as, for i==0 any index of sum (col) having value == arr[0] is true. 

  //recurrance relation
	for(int i=1;i<n;i++){
		for(int target=1;target<=k;target++){
			bool take = false;
			if(arr[i] <= target) take = dp[i-1][target-arr[i]];
			bool not_take = dp[i-1][target];
			
			dp[i][target] = take or not_take;
		}
	}
	return dp[n-1][k];	
}

bool canPartition(vector<int> &arr, int n)
{
	int total_sum = 0;
	for(int i: arr) total_sum += i;

	if(total_sum % 2 != 0) return false;
	
	int target = total_sum/2;
	
	return f(n, target, arr);
}

// Tabulation
bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int e: arr) sum += e;

        if(sum % 2 != 0) return false;
        sum = sum/2;
        
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
	
	    //base cases
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(arr[0] <= sum) dp[0][arr[0]] = true;			// make sure to put this condition!

        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool take = false;
                if(arr[i] <= target) take = dp[i-1][target-arr[i]];
                bool not_take = dp[i-1][target];
                
                dp[i][target] = take or not_take;
            }
        }
        return dp[n-1][sum];	
}

// Space optimised
bool canPartition(vector<int>& arr) {
	int n = arr.size();
	int sum = 0;
	for(int e: arr) sum += e;
	
	if(sum % 2 != 0) return false;
	sum = sum/2;
	
	vector<int>prev(sum+1, 0), curr(sum+1, 0);
	    
	//base cases
	prev[0] = true;
	curr[0] = true;
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
	return prev[sum];	
}
