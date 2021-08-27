#include<bits/stdc++.h>


using namespace std;

void DFS(int node, vector<int> adj[], int &time, vector<int> &color, vector<int> &parent, vector<int> &discovery_time,  vector<int> &finishing_time) {
    time++;
    color[node] = 1;
    discovery_time[node] = time;
    for(int neighbour : adj[node]) {
        if(color[neighbour] == 0)  {
            parent[neighbour] = node;
            DFS(neighbour, adj, time, color, parent, discovery_time, finishing_time);
        }
    }    
    time++;
    color[node] = 2;
    finishing_time[node] = time;
}

void print_vec(string name, vector<int> arr) {
    cout << name << " array:";
    for(int val : arr)
        cout << val << " ";
    cout << endl;
}



int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
		adj[v].push_back(u);
    }
    int time = 0;
    vector<int> color(V, 0);
    vector<int> parent(V, -1);
    vector<int> discovery_time(V, (int)INFINITY);
    vector<int> finishing_time(V, (int)INFINITY);
    DFS(0, adj, time, color, parent, discovery_time, finishing_time);
    cout << "time: " << time << endl;
    print_vec("color", color);
    print_vec("parent", parent);
    print_vec("discovert_time", discovery_time);
    print_vec("finishing_time", finishing_time);
    return 0;
}