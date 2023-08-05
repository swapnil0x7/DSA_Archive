bool static compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end(), compare);

    int count = 1;
    int lastEnd = arr[0][1];

    for(int i=1;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];

        if(start >= lastEnd){
            count++;
            lastEnd = end;
        }
    }
    return n - count;
}
