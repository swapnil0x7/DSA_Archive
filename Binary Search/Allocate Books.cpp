#include<bits/stdc++.h>

int studentsRequired(vector<int> &arr, int pages_limit){
    int count = 1, sum = arr[0];

    for(int i=1;i<arr.size();i++){
        if(sum + arr[i] <= pages_limit){
            sum +=arr[i];
        }
        else{
            count++;
            sum = arr[i];
        }
    }
    return count;
}

int findPages(vector<int>& arr, int n, int m) {
    int low = 0, high = 0;    

    // this of it as you need to divide the array into sections.
    // for low, low = max(arr) which will give each man a book.
    // for high, high = sum(arr) which will give all the books to 1 person.
    for(int i=0;i<n;i++){
        low = max(low, arr[i]);
        high += arr[i];
    }

    int ans = -1;
    if(arr.size() < m) return ans;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(studentsRequired(arr, mid) <= m){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
