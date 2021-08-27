

#include<bits/stdc++.h>


using namespace std;

bool DFS(int source, vector<int> adj[], vector<int>&color);

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int time = 0;
    vector<int> color(V, 0);
    cout << DFS(0, adj, color) << endl;
    return 0;
}



bool DFS(int source, vector<int> adj[], vector<int>&color) {
    color[source] = 1;
    for(int neighbour : adj[source]) {
        if(color[neighbour] == 1)
            return true;
        if(color[neighbour] == 0 && DFS(neighbour, adj, color))
            return true;
    }
    color[source] = 2;
    return false;
}