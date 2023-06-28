#include<bits/stdc++.h>

//Brute force code having O(2^N) time complexity.

void f(int i, vector<int> &arr, vector<int> &ds, int n){
    if(i==0){
        if(ds.size()==0)
        cout<<"{}";
        
        for(int i: ds){
            cout<<i<<" ";
        }
        
        cout<<endl;
        return;
    }
    
    f(i-1, arr, ds, n);
    
    ds.push_back(arr[i]);
    f(i-1, arr, ds, n);
    ds.pop_back();
}


int main() {
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    vector<int> ds;      
    f(n-1, arr, ds,n);
    
}
 
