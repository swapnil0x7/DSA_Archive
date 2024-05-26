// Brute force
class LRUCache {
public:
    vector<pair<int,int>> cache;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(int i=0;i<cache.size();i++){
            if(cache[i].first == key){
                int val = cache[i].second;
                cache.erase(cache.begin() + i);
                cache.push_back({key, val});
                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0;i<cache.size();i++){
            if(cache[i].first == key){
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        if(cache.size() == n){
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else{
            cache.push_back({key, value});
        }
    }
};




// Optimised
class LRUCache {
public:
    // doubly linked list in cpp
    list<int> dll;
    int n;
    
    // our map stores key -> {address of that item, value of that item}
    unordered_map<int, pair<list<int>::iterator, int>> mp;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeRecentlyUsed(int key) {
        auto node = mp[key].first;
        dll.erase(node);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        // find if this item is present in our LRU or not
        if(mp.find(key) != mp.end()){
            // if present make it recently used and return its value
            makeRecentlyUsed(key);
            return mp[key].second;
        }   
        // if not present then simply return -1
        return -1; 
    }
    
    void put(int key, int value) {
        // check if the same key already exists in our LRU or not
        if(mp.find(key) != mp.end()){
            // if found update its value as given and then make it recently used
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        // if not present then simply increase size, add the key to front and update the map.
        else{
            n--;
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
        }
        // in every put operation always check if size crosses the capacity
        if(n<0){
            // if it does find the key from dll, delete from both map and dll.
            int key_to_delete = dll.back();
            dll.pop_back();
            mp.erase(key_to_delete);
            n++;
        }
    }
};
