int findKRotation(vector<int> &arr){
    int n = arr.size();

    int low = 0, high = n-1;
    int ans = 1e9, index = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        // if(arr[low] < arr[high]){            // if it is not guaranteed that the given array is rotated at some point
        //     ans = arr[low];
        //     index = low;
        //     break;
        // }


        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
            low = mid+1;
        }
        else{
            if(arr[mid] < ans){
                ans = arr[mid];
                index = mid;
            }
            high = mid-1;
        }
    }
    return index;

}
