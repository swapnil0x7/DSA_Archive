// Time Complexity - O(N * log(maxElement))

int calculateTime(vector<int> &arr, int rate){
    int n = arr.size();
    int time = 0;
    for(int i=0;i<n;i++){
        time += ceil((double)arr[i] / (double)rate);
    }
    return time;
}

int minimumRateToEatBananas(vector<int> arr, int h) {
    int n = arr.size();
    int maximum = 1e9;
    for(int i=0;i<n;i++){
        maximum = max(maximum, arr[i]);
    }
    
    int low = 1, high = maximum;
    int ans = maximum;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        int timeTaken = calculateTime(arr, mid);
    
        if(timeTaken <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
