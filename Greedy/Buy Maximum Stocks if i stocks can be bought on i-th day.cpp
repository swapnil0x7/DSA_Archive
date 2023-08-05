int buyMaximumProducts(int n, int k, int price[]){
    vector<pair<int,int>> arr;
    
    for(int i=0;i<n;i++){
        arr.push_back({price[i], i+1});
    }
    sort(arr.begin(), arr.end());
    
    int count = 0;
    
    for(int i=0;i<n;i++){
        int amount = arr[i].first;
        int limit =  arr[i].second;
        
        if(amount * limit <= k){
            k -= (amount*limit);
            count += limit;
        }
        else{
            count += (k / amount);
            break;
        }
    }
    return count;
}
