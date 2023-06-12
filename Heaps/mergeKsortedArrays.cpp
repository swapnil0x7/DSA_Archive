#include<bits/stdc++.h>

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> res;
    
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;  
    
    for(int i=0;i<k;i++){
        pq.push({arr[i][0], {i, 0}});
    }      
    
    while(!pq.empty()){
        int curr = pq.top().first;
        int curr_row = pq.top().second.first;
        int curr_idx = pq.top().second.second;
        pq.pop();
        
        res.push_back(curr);
        
        if(curr_idx + 1 < arr[curr_row].size()){
            pq.push({arr[curr_row][curr_idx+1], {curr_row, curr_idx + 1}});
        }
        
    }
    return res;
}

//The main idea is to use a min-heap since we need to sort! (as pq.top() will give min element in pq)
// modify a priority_queue such that it holds an element with its current array pointer and its current index.
//so that when this element is popped out we get the access to it's very next element!
