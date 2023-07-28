//Time complexity - O(N * log(max-min))

int checkThreshold(vector<int> &arr, int mid){
	int total = 0;

	for(int i=0;i<arr.size();i++){
		total += ceil((double)arr[i] / mid);
	}
	return total;
}


int smallestDivisor(vector<int>& arr, int limit)
{
	int n = arr.size();
	int minimum = 1e9, maximum = -1e9;
	
	for(int i: arr){
		minimum = min(minimum, i);
		maximum = max(maximum, i);
	}
	int low = minimum, high = maximum;
	int ans = maximum;

	while(low <= high){
		int mid = low + (high-low)/2;

		if(checkThreshold(arr, mid) <= limit){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}
