int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int count = 0, ans = 0;
    	
    	int i=0, j=0;
    	while(i<n){
    	    if(arr[i] <= dep[j]){
    	        count++;
    	        ans = max(ans, count);
    	        i++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	}
    	return ans;
    }
