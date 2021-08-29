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
void union_set(int a, int b, vector<int> &set_name);

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
    for(int i = 0; i < G.V; i++)
        set_name[i] = i;
    sort(G.Edges.begin(), G.Edges.end(), compare_edges);
    for(Edge &edge : G.Edges) {
        if(set_name[edge.src] != set_name[edge.dest]) {
            kruskal_mst.push_back(edge);
            union_set(set_name[edge.src], set_name[edge.dest], set_name);
        }
    }
    return kruskal_mst;
}

bool compare_edges(Edge &E1, Edge &E2)  {
    return E1.weight < E2.weight;
}

void union_set(int a, int b, vector<int> &set_name) {
    for(int i = 0; i < set_name.size(); i++) 
        set_name[i] = set_name[i] == b ? a : set_name[i];
}