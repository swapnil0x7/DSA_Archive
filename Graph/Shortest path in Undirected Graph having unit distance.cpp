vector<int> shortestPath(vector<vector<int>>& arr, int n,int m, int src){
        vector<int>adj[n];
        
        for(auto v: arr){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto j: adj[node]){
                if(dist[node] + 1 < dist[j]){
                    dist[j] = dist[node] + 1;
                    q.push(j);
                }
            }
        }
        
        vector<int> ans(n, -1);
        
        for(int i=0;i<n;i++){
            if(dist[i] != 1e9)  ans[i] = dist[i];
        }
        
        return ans;
    }
