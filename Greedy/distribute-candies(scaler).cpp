int Solution::candy(vector<int> &A) {
    int n = A.size();

    vector<int> candies(n, 1);

    for(int i=1;i<n;i++){
        if(A[i] > A[i-1])
            candies[i] = 1 + candies[i-1];
    }
    for(int i=n-2;i>=0;i--){
        if(A[i] > A[i+1] and candies[i] <= candies[i+1]){
            candies[i] = 1 + candies[i+1];
        }
    }
    int total = 0;
    for(int i=0;i<n;i++){
        total += candies[i];
    }
    return total;
}

// Logic - traverse the array from both the sides to check each neighbour!
