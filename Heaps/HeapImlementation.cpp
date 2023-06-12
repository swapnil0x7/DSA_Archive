#include<bits/stdc++.h>

class MinHeap{
  private:
    int *arr;
    int size;
    int capacity;
    
  public:
    MinHeap(int c){
        size = 0;
        capacity = c;
        arr = new int[c];
    }
    
    int left(int i){
        return 2*i + 1;
    }
    int right(int i){
        return 2*i + 2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    
    //insert a value to heap -> O(logN)    push(val)
    void insert(int val){
        arr[size] = val;
        size++;
        
        int i = size-1;
        int parent_index = parent(i);
        
        while(i > 0 and arr[parent_index] > arr[i]){
            swap(arr[parent_index], arr[i]);
            i = parent_index;
        }
    }
    
    //Heapify -> O(logN)
    void heapify(int i){
        int smallest = i;
        
        if(left(i) < size and arr[left(i)] < arr[smallest])
            smallest = left(i);
        if(right(i) < size and arr[right(i)] < arr[smallest])
            smallest = right(i);
        
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
    
    //Building a heap from a given array  -> T.C = O(N) important!
    void buildHeap(){
        for(int i=size/2-1;i>=0;i--){
            heapify(i);
        }
    }
    
    //extract minimum -> O(logN)    pop()
    int extractMin(){
        if(size == 0) 
            return -1;
        
        int min = arr[0];
        arr[0] = arr[size-1];
        size--;
        heapify(0);
        return min;
    }
    
    //decrease the value of any key -> O(logN)
    void decreaseKey(int i, int val){
        arr[i] = val;
        int parent_index =  parent(i);
        
        while(i>0 and arr[parent_index] > arr[i]){
            swap(arr[i], arr[parent_index]);
            i = parent_index;
        }
    }
    
    //delete a value at given index -> O(logN)
    void deleteKey(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    
    void printHeap(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    MinHeap h(10);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(100);
    h.insert(70); 
    h.insert(50);
    h.printHeap();
}