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


int get_min_key_node(vector<int> &key, vector<int> &mst_set);
void PrimsMST(vector<pair<int,int>> adj[], int &V);
void PrimsMSTEfficient(vector<pair<int,int>> adj[], int &V);

int main() {
    int V, E;
    int u, v, w;
    cin >> V >> E;
    vector<pair<int,int>> adj[V];
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    PrimsMSTEfficient(adj, V);

    return 0;
}

// V*logV + E*logV
void PrimsMSTEfficient(vector<pair<int,int>> adj[], int &V) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<int> mst_set(V, 0);

    key[0] = 0; // source vertex
    priority_queue<pair<int,int>, vector<pair<int,int>>, PriorityComparator> Q;

    Q.push({0, key[0]});
    while(!Q.empty()) {    // Read Note
        pair<int,int> u = Q.top();
        Q.pop();                    // log V
        int curr_node = u.first;
        if(mst_set[curr_node])
            continue;
        cout << "popped : " << curr_node << " " << key[curr_node] << " " << u.second << endl;
        mst_set[curr_node] = 1;
        for(auto neighbour : adj[curr_node]) {
            int neighbour_node = neighbour.first;
            int weight = neighbour.second;
            if(mst_set[neighbour_node] == 0 && key[neighbour_node] > weight) {
                parent[neighbour_node] = curr_node;
                key[neighbour_node] = weight;
                Q.push({neighbour_node, key[neighbour_node]}); // log V
            }
        }
    }
    for(auto val : parent) cout << val << " ";
    cout << endl;

}

/*
Please note that the while loop of priority_queue in efficient solution of Prim's algoirthm actually runs
more than V times. The reason is because the priority_queue of C++ STL doesn't support decrease key operation.
That is, when we re-push a vertex into the key, there is a new copy of it gets created with the newly updated
value. This means this same vertex has multiple copies in the priority queue which can be popped out. This is why
we make sure just after poppping that what we have popped, is it already there in the MST or not. If its already there,
that'd mean that it is just an older copy of the save vertex which had been selected in the MST long ago.

*/


// Brute Force implementation of Prim's algorithm(O(V^2 + E))
void PrimsMST(vector<pair<int,int>> adj[], int &V) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<int> mst_set(V, 0);

    key[0] = 0; // source vertex
    int t = V;
    while(t--) {
        int curr_node = get_min_key_node(key, mst_set);
        cout << "popped : " << curr_node << " " << key[curr_node] << endl;
        mst_set[curr_node] = 1;
        for(auto neighbour : adj[curr_node]) {
            int neighbour_node = neighbour.first;
            int weight = neighbour.second;
            if(mst_set[neighbour_node] == 0 && key[neighbour_node] > weight) {
                parent[neighbour_node] = curr_node;
                key[neighbour_node] = weight;
            }
        }
    }
    for(auto val : parent) cout << val << " ";
    cout << endl;

}

// O(V)
int get_min_key_node(vector<int> &key, vector<int> &mst_set) {
    int min_key = INT_MAX;
    int min_node;
    for(int i = 0; i < key.size(); i++) {
        if(mst_set[i] == 0 && key[i] < min_key) {
            min_key = key[i];
            min_node = i;
        }
    }
    return min_node;
}