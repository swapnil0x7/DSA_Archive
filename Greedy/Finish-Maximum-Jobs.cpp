bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();

    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++){
        arr[i] = {A[i], B[i]};
    }
    sort(arr.begin(), arr.end(), cmp);

    int total = 0;
    int lastEndTime = -1;

    for(int i=0;i<n;i++){
        int startTime = arr[i].first;
        int endTime = arr[i].second;

        if(startTime >= lastEndTime){
            total++;
            lastEndTime = endTime;
        }
    }
    return total;

}
