// variation 1
int countPainters(vector<int> &arr, int time_limit){
    int painters = 1, time = 0;
    for(int i=0;i<arr.size();i++){
        if(time + arr[i] <= time_limit){
            time += arr[i];
        }
        else{
            painters++;
            time = arr[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    int total = 0, max_element = 0;
    for(int i=0;i<n;i++){
        total += arr[i];
        max_element = max(max_element, arr[i]);
    }

    int low = max_element, high = total;

    int ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(countPainters(arr, mid) <= k){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// variation 2 (asked in mock interview) - https://www.interviewbit.com/problems/painters-partition-problem/
int mod = 10000003;
int countPainters(vector<int> &arr, int time_limit){
    int painters = 1, time = 0;
    for(int i=0;i<arr.size();i++){
        if(time + arr[i] <= time_limit){
            time = time +  arr[i];
        }
        else{
            painters++;
            time = arr[i];
        }
    }
    return painters;
}

int Solution::paint(int A, int B, vector<int> &arr) {
    int n = arr.size();
    
    int max_element = 0, total = 0;
    for(int i=0;i<n;i++){
        max_element = max(max_element, arr[i]);
        total  = total + arr[i];
    }
    
    int low = (max_element * B), high = (total * B);
    int ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(countPainters(arr, mid) <= A){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

