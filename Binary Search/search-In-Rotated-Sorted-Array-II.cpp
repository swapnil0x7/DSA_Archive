bool searchInARotatedSortedArrayII(vector<int>&arr, int x) {
    int n = arr.size();
    int low = 0, high = n-1;
    
    while(low <= high){
        int mid = low + (high - low)/2;
    
        if(arr[mid] == x) return true;
    
        if(arr[low] == arr[mid] and arr[mid] == arr[high]){
            low++;
            high--;
            continue;   
        }
    
        if(arr[low] <= arr[mid]){
            if(x >= arr[low] and x < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(x > arr[mid] and x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
    
    }
