int floorSqrt(long long int n)
{
    int ans = 1;
    int low = 1, high = n;

    while(low <= high){
        long long int mid = low + (high - low)/2;

        if(mid*mid <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
