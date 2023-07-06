int Solution::findLIS(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 0);
    int lis = 1;
    dp[0] = 1;

    for(int i=1;i<n;i++){
        int temp = 0;
        for(int j=0;j<i;j++){                       // for all the previous elements that are smaller than the current element.
            if(arr[j] < arr[i]){
                temp = max(temp, dp[j]);
            }
        }
        dp[i] = 1 + temp;
        lis = max(lis, dp[i]);
    }
    return lis;
}

// TC - O(N*N) SC - O(N)
