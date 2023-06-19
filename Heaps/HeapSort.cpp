#include<bits/stdc++.h>

void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n and arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n and arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest !=i){
        swap (arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(vector<int> &arr, int n){
    
    for(int i=n/2 - 1; i>=0; i--){                  //building max heap
        heapify(arr, n, i);
    }
    
    for(int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    vector<int> arr = {5,8,1,3,4,10,9};
    heapsort(arr, arr.size());
    
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
