int completeRows(int n) {
        int low = 1, high = n;
        int count = 0;
        
        while(low <= high){
            long long int mid = low + (high - low)/2;
            long long int  total_bricks = mid*(mid+1)/2;
            
            if(total_bricks <= n){
                count = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return count;
    }
