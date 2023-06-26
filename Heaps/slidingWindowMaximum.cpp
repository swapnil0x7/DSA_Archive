vector<int> maxSlidingWindow(vector<int>& arr, int k) {
      int n = arr.size();
      vector<int> res;
      deque<int> dq;
  
      for(int i=0;i<n;i++){
          if(!dq.empty() and dq.front() == i-k) dq.pop_front();                  //excluding that index which goes out of range
  
          while(!dq.empty() and arr[dq.back()] < arr[i]) dq.pop_back();          //maintaing the decreasing order in deque
  
          dq.push_back(i);
  
          if(i >= k-1) res.push_back(arr[dq.front()]);                          // returning max value for every range (i.e when i>=k-1)
      }
      return res;
}
