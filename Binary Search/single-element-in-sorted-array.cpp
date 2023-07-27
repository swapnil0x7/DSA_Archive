int singleNonDuplicate(vector<int>& arr) {
      int n = arr.size();
      
      if(n == 1) return arr[0];                    // case-1 : when array size=1
      
      if(arr[0] != arr[1]) return arr[0];          // edge-1
      
      if(arr[n-1] != arr[n-2]) return arr[n-1];    //edge-2
      
      int low = 1, high = n-2;                    // to prevent index out of bound error in line 15, that's why wee need to handle edge-1 and edge-2 separately!!!
      
      while(low <= high){
          int mid = low + (high-low)/2;
      
          if(arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1])
              return arr[mid];
      
          // if that unique element is not on the left half
          if((mid % 2 == 0 and arr[mid] == arr[mid+1]) or (mid % 2 != 0 and arr[mid] == arr[mid-1])){
              low = mid + 1;
          }
          // if that unique element is not on the right half
          else{
              high = mid - 1;
          }
      }
      return -1;
}
