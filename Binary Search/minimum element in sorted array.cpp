// we first look for the sorted part because the first element of sorted part might be our possible ans.
// so we keep the first element and remove the sorted part from out search space!


int findMin(vector<int>& arr)
{
	int n = arr.size();
	int low = 0, high = n-1;
	int ans = 1e9;
	
	while(low <= high){
		int mid = low + (high-low)/2;

		if(arr[low] <= arr[mid]){          
			ans = min(ans,arr[low]);
			low = mid + 1;
		}
		else{
			ans = min(ans,arr[mid]);
			high = mid - 1;
		}
	}
	return ans;
}
