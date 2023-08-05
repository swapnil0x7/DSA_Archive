
bool static compare(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
     sort(arr, arr+n, compare);
     
     int maxi = arr[0].dead;
     
     for(int i=0;i<n;i++){
         maxi = max(maxi, arr[i].dead);
     }
     
     vector<bool> slots(maxi + 1, false);
     
     int jobs = 0, profit = 0;
     
     for(int i=0;i<n;i++){
         for(int j=arr[i].dead; j>0; j--){
             if(slots[j] == false){
                 slots[j] = true;
                 jobs++;
                 profit += arr[i].profit;
                 break;
             }
         }
     }
     return {jobs, profit};
} 
