// The intuition behine prim's algorithm is a greedy approach to select the minimum wt. edges in every iteration. (watch TUF video)

int spanningTree(int n, vector<vector<int>> adj[])
{
    vector<int> visited(n, 0);
    
    vector<pair<int,int>> mst;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    
    // vector<pair<int,int>> mst;         list for printing one of the possible mst
    
    int sum = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        
        if(visited[node] == 1) continue;
        //add to the mst-list here if asked
        visited[node] = 1;
        sum+=wt;
        
        for(auto it: adj[node]){
            int j = it[0];
            int w = it[1];
            
            if(!visited[j]){
                pq.push({w, j});
            }
        }
    }
    return sum;
}
