void f(int i, int target, vector<int>& arr, vector<int> &ans, vector<vector<int>> &res, int n){
    if(i==n){
        if (target == 0){
            res.push_back(ans);
        }
        return;
    }

    if(arr[i]<=target){
        ans.push_back(arr[i]);
        f(i, target - arr[i], arr, ans, res, n);
        ans.pop_back();
    }

    f(i+1, target, arr, ans, res, n);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    int n = arr.size();

    vector<vector<int>> res;
    vector<int> ans;

    f(0, target, arr, ans, res, n);

    return res;
}
