// Time complexity - O(N * log(range));

int requiredDays(vector<int> &arr, int capacity){
    int n = arr.size();
    int totalDays = 1, load = 0;

    for(int i=0;i<n;i++){
        if(load + arr[i] > capacity){
            totalDays++;
            load = arr[i];
        }
        else{
            load += arr[i];
        }
    }
    return totalDays;
}


int leastWeightCapacity(vector<int> &arr, int target)
{
    int n = arr.size();
    int maximum = -1e9, total = 0;
    for(auto i: arr) {
        maximum = max(maximum, i);
        total += i;
    }

    int low = maximum, high = total;
    int ans = high;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(requiredDays(arr, mid) <= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;

}
