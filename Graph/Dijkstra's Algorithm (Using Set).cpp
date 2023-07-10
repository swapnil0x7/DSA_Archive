// Using set we save extra iteration by deleting the longer path from set, but on an expense of logN (unlike pq). 
// Hence we can't say if set is faster or priority_queue, it depends on the given graph.
// reference - https://www.youtube.com/watch?v=PATgNiuTP20&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=33

vector <int> dijkstra(int n, vector<vector<int>> adj[], int s) {
    vector<int> dist(n, 1e9);
    dist[s] = 0;
    
    set<pair<int, int>> st;
    st.insert({0, s});
    
    
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        
        for(auto i: adj[node]){
            int j = i[0];
            int w = i[1];
            
            if(dis + w < dist[j]){
                if(dist[j] != 1e9){
                    st.erase({dist[j], j});
                }
                dist[j] = dis + w;
                st.insert({dist[j], j});
            }
        }
    }
    return dist;
}
