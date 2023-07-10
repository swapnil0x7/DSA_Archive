vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
{
    
    vector<int> dist(n, 1e9);
    dist[s] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    
    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        
        for(auto i: adj[node]){
            int j = i[0];
            int w = i[1];
            
            if(dis + w < dist[j]){
                dist[j] = dis + w;
                pq.push({dis+w, j});
            }
        }
    }
    return dist;
    
}
// why Dijkstra's does not work in negative weight weights and negative cycle 👇
// https://www.youtube.com/watch?v=V6H1qAeB-l4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=32
