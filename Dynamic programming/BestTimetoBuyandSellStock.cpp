#include <bits/stdc++.h> 
int maximumProfit(vector<int> &arr){
    int n = arr.size();
    int minimum = arr[0];
    int profit = 0;

    for(int i=1;i<n;i++){
        profit = max(profit, arr[i] - minimum);
        minimum = min(minimum, arr[i]);
    }
    return profit;
}

// TC - O(N)
