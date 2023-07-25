// First check which part is sorted, then on the basis of target's position eliminate either the sorted half of unsorted half.

int search(vector<int>& arr, int n, int x)
{
    int low = 0, high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid] == x) return mid;

        if(arr[low] <= arr[mid]){                              // If left part is sorted
            if(x >= arr[low] and x < arr[mid]){                //checking if target lies in the sorted part or not
                high = mid - 1;  
            }
            else{
                low = mid + 1;
            }
        }
        else{                                                  // If right part is sorted
            if(x > arr[mid] and x<= arr[high]){                // checking if target lies in the sorted part or not
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
