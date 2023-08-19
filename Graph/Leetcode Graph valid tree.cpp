// link - https://www.codingninjas.com/studio/problems/graph-valid-tree_1376618?leftPanelTab=0

#include <bits/stdc++.h> 

bool isCycle(int node, int parent, vector<int> adj[], vector<int> &visited){
    visited[node] = 1;

    for(auto j: adj[node]){
        if(!visited[j]){
            if(isCycle(j, node, adj, visited) == true)
                return true;
        }
        else if(j != parent)
            return true;
    }
    return false;
}

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    vector<int> adj[n];
    for(auto e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> visited(n, 0);

    int components = 0;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            components++;
            if(components > 1) return false;
            
            if(isCycle(i, -1, adj, visited) == true)
                return false;
        }
    }
    return true;
}
