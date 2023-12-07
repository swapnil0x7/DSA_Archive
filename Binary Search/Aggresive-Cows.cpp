#include<bits/stdc++.h>

bool canPlaceCows(vector<int> &arr, int distance, int cows){      
    int count = 1, curr = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i] - curr >= distance){
            curr = arr[i];
            count++;
            if(count == cows) break;
        }
        else{
            continue;
        }
    }
    return count == cows;
}

int aggressiveCows(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // for high, let's say there are two cows then the max will be arr[n-1] - arr[0]
    // for low, let's say there are cows next to each other at a distance of 1.
    int low = 1, high = arr[n-1] - arr[0];
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low)/2;

       
        if(canPlaceCows(arr, mid, k)) {     // given a distance 'x' we check if we can place k cows.
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
