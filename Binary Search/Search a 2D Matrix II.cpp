bool searchMatrix(vector<vector<int>>& arr, int target) {
      int n = arr.size();
      int m = arr[0].size();
      
      int i = 0, j = m-1;

      while(i<n and j>=0){
          
          if(arr[i][j] == target)
              return true;
          
          else if(arr[i][j] < target)
              i++;

          else
              j--;
      }
      return false;
}
