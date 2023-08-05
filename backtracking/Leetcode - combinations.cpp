void f(int idx, int n, int k, vector<int> &ans, vector<vector<int>> &res){
        
        if(ans.size() == k){
            res.push_back(ans);
            return;
        }

        for(int i=idx;i<=n;i++){
            ans.push_back(i);
            f(i+1, n, k, ans, res);
            ans.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ans;

        f(1, n, k, ans, res);

        return res;
    }
