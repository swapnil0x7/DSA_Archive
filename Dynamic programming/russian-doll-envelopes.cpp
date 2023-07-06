int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    
    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++){
        arr[i] = {A[i][0], A[i][1]};
    }
    sort(arr.begin(), arr.end());
    
    vector<int> dp(n, 0);
    int lis = 1;
    dp[0] = 1;

    for(int i=1;i<n;i++){
        int temp = 0;
        for(int j=0;j<i;j++){
            if(arr[j].first < arr[i].first and arr[j].second < arr[i].second){      // arr[j].first < arr[i].first -> because we shouldn't consider that envelope whose height is same as arr[i].
                temp = max(temp, dp[j]);
            }
        }
        dp[i] = 1 + temp;
        lis = max(lis, dp[i]);
    }
    return lis;
}
