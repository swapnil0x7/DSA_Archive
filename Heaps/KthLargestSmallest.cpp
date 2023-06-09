int KthLargest(vector<int> &arr, int n, int k){
	
	priority_queue <int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k);

	for(int i=k;i<n;i++){
		if(arr[i] > pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}
	return pq.top();
}

int KthSmallest(vector<int> &arr, int n, int k){
	
	priority_queue<int> pq(arr.begin(), arr.begin() + k);

	for(int i=k;i<n;i++){
		if(arr[i] < pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}
	return pq.top();
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int> res;
  
	int smallest = KthSmallest(arr,n,k);
	int largest = KthLargest(arr,n,k);
	
  res.push_back(smallest);
	res.push_back(largest);
	return res;
	
}

//for Kth Largest we should use minHeap for better TC
// max Heap, TC = O(N + klog(N))
// min Heap, TC = O(k + (n-k)log(K)) which is slightly better! 



//ALternate solution as discussed above.
void kth_Largest_MaxHeap(vector<int>&arr, int k) {

	priority_queue<int>pq ;
	int n = arr.size()  ;

	for (int i = 0; i < arr.size(); i++) {
	    pq.push(arr[i])  ;
	}

	int f = k - 1 ;

	while (f > 0) {
	    pq.pop()  ;
	    f-- ;
	}

	cout << "Kth Largest element " << pq.top() << "\n"  ;
}

void kth_Smallest_MinHeap(vector<int>&arr, int k) {

	priority_queue<int, vector<int>, greater<int>>pq ;
	int n = arr.size()  ;

	for (int i = 0; i < arr.size(); i++) {
	    pq.push(arr[i])  ;
	}

	int f = k - 1 ;

	while (f > 0) {
	    pq.pop()  ;
	    f-- ;
	}

	cout << "Kth Smallest element " << pq.top() << "\n"  ;
}
