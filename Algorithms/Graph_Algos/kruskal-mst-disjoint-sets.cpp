#include<bits/stdc++.h>


using namespace std;


class Edge {
  public:
    int src;
    int dest;
    int weight;

    Edge(int _src, int _dest, int _weight) {
        src = _src;
        dest = _dest;
        weight = _weight;
    }
};

class Graph {
  public:
    vector<Edge> Edges;
    int V;

    Graph(int _V) {
        V = _V;
        Edges = {};
    }
};


bool compare_edges(Edge &E1, Edge &E2);
vector<Edge> KruskalMST(Graph &G);

void make_set(int x, vector<int>&parent, vector<int>&rank);
int find_set(int x, vector<int>&parent);
void union_sets(int x, int y, vector<int> &parent, vector<int> &rank);

int main() {
    int V, E;
    int u, v, w;
    cin >> V >> E;
    Graph G(V);
    Edge Edge1(0, 0, 0);
    for(int i = 0; i < E; i++) {
        cin >> Edge1.src >> Edge1.dest >> Edge1.weight;
        G.Edges.push_back(Edge1);
    }
    vector<Edge> kruskal_mst = KruskalMST(G);
    for(auto Edge : kruskal_mst) {
        cout << Edge.src << "-->" << Edge.dest << " w: " << Edge.weight << endl;
    }
    return 0;
}



vector<Edge> KruskalMST(Graph &G) {
    vector<Edge> kruskal_mst;
    vector<int> set_name(G.V);
    vector<int> parent(G.V);    // for disjoint set
    vector<int> rank(G.V);      // for disjoint set

    for(int i = 0; i < G.V; i++)
        make_set(i, parent, rank);
    sort(G.Edges.begin(), G.Edges.end(), compare_edges); // O(ElogE)
    for(Edge &edge : G.Edges) {
        if(find_set(edge.src, parent) != find_set(edge.dest, parent)) {
            kruskal_mst.push_back(edge);
            union_sets(edge.src, edge.dest, parent, rank);
        }
    }
    return kruskal_mst;
}

/********************* Disjoin Set Forest Data Structure ************************/

void make_set(int x, vector<int>&parent, vector<int>&rank) {
    parent[x] = x;
    rank[x] = 0;
}

// A two pass function. Goes from leaf to root(ultimate parent) and comes back to leaf making every node on
// the find-path pointing to the ultimate parent(root). This is called path compression.
int find_set(int x, vector<int>&parent) {
    if(x != parent[x]) 
        parent[x] = find_set(parent[x], parent);  // path compression step
    return parent[x];
}

void union_sets(int x, int y, vector<int> &parent, vector<int> &rank) {
    int root1 = find_set(x, parent);
    int root2 = find_set(y, parent);
    if(rank[root1] > rank[root2])
        parent[root2] = root1;
    else if(rank[root1] < rank[root2])
        parent[root1] = root2;
    else {
        parent[root2] = root1;
        rank[root1]++;
    }    
}

/***************************************************************************/


bool compare_edges(Edge &E1, Edge &E2)  {
    return E1.weight < E2.weight;
}