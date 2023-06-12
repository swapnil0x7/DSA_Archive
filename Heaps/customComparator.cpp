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
