long long connectRopes(int* arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);

    int total = 0;
    
    while(pq.size() >= 2){                            //the last element left in the pq should be ignored,
        int a = pq.top();                             // as it has already contributed to total cost! (do a dry run)
        pq.pop();
        
        int b = pq.top();
        pq.pop();
        
        total += (a+b);
        pq.push(a+b);
    }
    
    return total;
}
