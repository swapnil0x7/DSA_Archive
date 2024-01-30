// O(N) for smaller sized test cases.
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1002, 0);

        for(auto v: trips){
            int passengers = v[0];
            arr[v[1]] += passengers;
            arr[v[2]] -= passengers;
        }

        for(int i=1; i<arr.size(); i++){
            arr[i] += arr[i-1];
        }

        for(int i=0; i<arr.size(); i++){
            if(arr[i] > capacity) return false;
        }

        return true;
    }
};


// O(N*logN) 
class Solution {
public:
    static bool compare(vector<int> A, vector<int> B){
        if(A[1] < B[1] or (A[1] == B[1] and A[2] < B[2]))
            return true;
        return false;
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // sort the array on the basis of start time. 
      
        sort(trips.begin(), trips.end(), compare);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // The minHeap is build on the basis of end time, so that we can know at a given time (i-th index) how many previous rides end. 
        // Also, the heap consist of a pair of {ending time, passengerCount}.
      
        int total = 0;
        for(auto v: trips){
            int start = v[1], end = v[2];
            while(!pq.empty() and pq.top().first <= start){
                total -= pq.top().second;
                pq.pop();
            }
            total += v[0];
            pq.push({v[2], v[0]});
            if(total > capacity) return false;
        }
        return true;
    }
};
