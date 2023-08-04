vector<int> MinimumCoins(int A)
{
    vector<int> arr = {1,2,5,10,20,50,100,500,1000};
    int n = arr.size();
    int i = n-1;
    
    vector<int> res;

    while(i>=0){
        if(arr[i] > A) {
            i--;
        }
        else {
           while(arr[i] <= A){
               A -= arr[i];
               res.push_back(arr[i]);
           }
      }
    }
    return res;
    
}
