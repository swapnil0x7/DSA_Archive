// method 1
bool isPossible(vector<int> &arr, int capacity, int m){
    int students = 1, pages = 0;
    for(int i=0;i<arr.size();i++){
        if(pages + arr[i] <= capacity){
            pages += arr[i];
        }
        else{
            students++;
            pages = arr[i];
        }
    }
    return (students <= m);
}

int findPages(vector<int>& arr, int n, int m) {

    if(n < m) return -1;
    int sum = 0, max_element = 0;
    for(int i=0;i<n;i++){
        max_element = max(max_element, arr[i]);
        sum += arr[i];
    }

    int low = max_element, high = sum;
    
    int ans = 0;
    while(low<=high){
        int mid = low + (high - low)/2;

        if(isPossible(arr, mid, m) == true){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

//method 2                // just changing the helper function type. choose whichever is easier.
#include<bits/stdc++.h>

int countStudents(vector<int> &arr, int capacity){
    int students = 1, pages = 0;
    for(int i=0;i<arr.size();i++){
        if(pages + arr[i] <= capacity){
            pages += arr[i];
        }
        else{
            students++;
            pages = arr[i];
        }
    }
    return students;
}



int findPages(vector<int>& arr, int n, int m) {

    if(n < m) return -1;
    int sum = 0, max_element = 0;
    for(int i=0;i<n;i++){
        max_element = max(max_element, arr[i]);
        sum += arr[i];
    }

    int low = max_element, high = sum;
    
    int ans = 0;
    while(low<=high){
        int mid = low + (high - low)/2;

        if(countStudents(arr, mid) <= m){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
