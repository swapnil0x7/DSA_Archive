Link - https://www.codingninjas.com/studio/problems/rose-garden_2248080?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=0

bool isPossible(vector<int> &arr, int mid, int m, int k){		
	int count = 0, noOfBouquets = 0;

	for(int i=0;i<arr.size();i++){
		if(arr[i] <= mid){
			count++;
		}
		else{
			noOfBouquets += count/k;
			count = 0;
		}
	}
	noOfBouquets += count/k;
	return noOfBouquets >= m;
}

int roseGarden(vector<int> arr, int k, int m)
{	
	int n = arr.size();
	long long int totalRequired = k*1LL * m*1LL;			//converting int to long during multiplication to avoid overflow
	if(n < totalRequired) return -1;				// checking for invalid case

	int minimum = 0, maximum = 0;
	for(int i=0;i<n;i++){
		minimum = min(minimum, arr[i]);
		maximum = max(maximum, arr[i]);
	}
	int low = minimum, high = maximum;

	while(low <= high){
		int mid = (low+high)/2;

		if(isPossible(arr, mid, m, k))
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

// Time complexity - O(N * log(maximum-minimum))
// Space Complexity - O(1)
