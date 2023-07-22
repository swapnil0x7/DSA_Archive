int Solution::solve(int A, vector<vector<int> > &B, int src, int dest) {
    int n = (B.size() > A) ? B.size() : A;

    vector<int> adj[2*n];
    int x = A;

    for(auto v: B){
        if(v[2] == 2){
            adj[v[0]].push_back(x);
            adj[x].push_back(v[0]);
            adj[x].push_back(v[1]);
            adj[v[1]].push_back(x);
            x++;
        }
        else{
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
    }

    queue<int>q;
    q.push(src);
    
    vector<int> dist(2*n, 1e9);
    dist[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node == dest) return dist[dest];

        for(auto j: adj[node]){
            if(dist[j] > dist[node] + 1){
                dist[j] = dist[node] + 1;
                q.push(j);
            }
        }
    }
    return -1;
}
