int findMin(vector<int>& arr) {
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = 1e9;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[low] == arr[mid] and arr[mid] == arr[high]){
            ans = min(ans, arr[low]);
            low++;
            high--;
            continue;
        }

        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }    
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
