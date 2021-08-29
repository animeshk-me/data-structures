#include<bits/stdc++.h>

using namespace std;


class PriorityComparator {
  public:
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
        // In case of MIN-Heap the numbers are store like 5-->4-->2-->1, that is, the min value is stored at the
        // end of the array, this is why we say p1 > p2 is what we want to see in the container. We keep that condition
        // always, which we want the container to normally follow.
        // In case of MAX-Heap the numbers in the container will be like 1-->2-->4, while writing the comparator class
        // we'll say p1 < p2. Because this is the state we want the container to normally be into !
    }
};

void dijkstra(vector<pair<int,int>> adj[], int &V);

int main() {
    int V, E;
    int u, v, w;
    cin >> V >> E;
    vector<pair<int,int>> adj[V];
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    dijkstra(adj, V);

    return 0;
}

void dijkstra(vector<pair<int,int>> adj[], int &V) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    key[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, PriorityComparator> Q;
    for(int i = 0; i < V; i++) Q.push({i, key[i]});

    int i = V;
    while(!Q.empty() && i--) {
        int curr_node = Q.top().first;
        Q.pop();
        for(auto neigh : adj[curr_node]) {
            int neigh_node = neigh.first;
            int weight = neigh.second;
            if(weight + key[curr_node] < key[neigh_node]) {
                parent[neigh_node] = curr_node;
                key[neigh_node] = weight + key[curr_node];
                Q.push({neigh_node, key[neigh_node]});
            }
        }
    }
    for(int k : key) cout << k << " ";
    cout << endl;
}