void f(vector<int>& arr, vector<int> &ans, vector<vector<int>> &res, vector<int> &visited){
    int n = arr.size();
    if(ans.size() == n){
        res.push_back(ans);
        return;
    }

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            visited[i] = 1;
            ans.push_back(arr[i]);
            f(arr,ans,res,visited);
            ans.pop_back();
            visited[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> res;
    vector<int> ans;
    vector<int> visited(n, 0);
    f(arr, ans, res, visited);

    return res;
}


// Space efficient - using swapping
void f(int idx, vector<int>& arr, vector<vector<int>> &res, int n){
        
        if(idx == n){
            res.push_back(arr);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(arr[idx], arr[i]);
            f(idx+1, arr, res, n);
            swap(arr[idx], arr[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> res;
        
        f(0, arr, res, n);

        return res;
    }
