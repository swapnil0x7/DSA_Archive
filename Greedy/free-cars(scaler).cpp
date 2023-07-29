int Solution::solve(vector<int> &A, vector<int> &B) {
    int mod = 1e9+7;
    int n = A.size();
    vector<pair<int, int>> arr(n);

    for(int i=0;i<n;i++){
        arr[i] = {A[i], B[i]};
    }
    sort(arr.begin(), arr.end());

    int time = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++){
        int t = arr[i].first;
        int profit = arr[i].second;

        if(time < t){
            pq.push(profit);
            time++;
        }
        else{
            if(pq.top() < profit){
                pq.pop();
                pq.push(profit);
            }
        }
    }
    long long int totalProfit = 0;
    while(!pq.empty()){
        totalProfit = totalProfit % mod + pq.top() % mod;
        pq.pop();
    }
    return totalProfit % mod;
}
