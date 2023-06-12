#include<bits/stdc++.h>

class cmp{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second < b.second;                           // < : for increasing or ascending sort
        }                                                         // > : for decreasing or descending sort
};


int main(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({1,5});
    pq.push({2,10});
    pq.push({3,15});
    pq.push({4,20});
    pq.push({5,25});
    
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        cout<<curr.first<<" "<<curr.second<<endl;
    }
    
}

//But in case other case...for ex. sorting...

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    // If frequencies of two elements are same
    // then the larger number should come first
    if (p1.second == p2.second)
        return p1.first > p2.first;
 
    // Sort on the basis of decreasing order
    // of frequencies
    return p1.second > p2.second;
}

sort(freq_arr.begin(), freq_arr.end(), compare);
