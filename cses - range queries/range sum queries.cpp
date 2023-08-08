#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, q;
    cin>>n>>q;
    
    long long int arr[n+1];
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    long long int prefixSum[n+1];
    memset(prefixSum, 0, sizeof prefixSum);
    
    long long int sum = 0;
    for(int i=1;i<=n;i++){
        sum += arr[i];
        prefixSum[i] = sum;
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        
        cout<<prefixSum[b] - prefixSum[a-1]<<"\n"; 
        
    }
}