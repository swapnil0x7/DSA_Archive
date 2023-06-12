#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int> res;
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    priority_queue<pair<int,int>> pq;

    for(auto i: mp){
        int elem = i.first;
        int occ = i.second;

        pq.push({occ, elem});
    }

    while(k--){
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(), res.end());
    return res;

}

//T.C = O(N) + O(N*logN)
