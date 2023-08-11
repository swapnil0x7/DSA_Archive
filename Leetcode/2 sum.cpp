vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> res;
        int n = arr.size();

        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            if(mp.find(target - arr[i]) != mp.end()){
                res.push_back(mp[target - arr[i]]);
                res.push_back(i);
                break;
            }
            mp[arr[i]] = i;
        }
        return res;
    }