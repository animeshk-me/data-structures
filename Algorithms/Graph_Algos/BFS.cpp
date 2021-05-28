#include<bits/stdc++.h>

using namespace std;

// One Block in the Adjacency list

class Block;
class Graph;
class Node;

// The Graph
class Graph {
 public:
  int V;
  int E;
  vector<Node> Vertex;
  
  Graph(int v, int e);
  void AddEdge(int i, int j);
  void Display();
};

// A node of the Graph
class Node {
 public:
  int id;
  int level;
  bool is_visited;
  Block* Adj;

  Node() {}
  Node(int i);
  void Insert(int i);
};

class Block {
 public:
  Node node;
  Block* next;
  Block(int i, Block* n) {
    node.id = i;
    next = n;
  }
};

Node::Node(int i) {
  id = i;
  level = 0;
  is_visited = false;
}

void Node::Insert(int i) {
  Block* temp = Adj;
  while(temp->next != NULL)
    temp = temp->next;
  Block* b = new Block(i, NULL);
  temp->next = b;
}

Graph::Graph(int v, int e) {
  V = v;
  E = e;
  Vertex.resize(v);  
}

void Graph::AddEdge(int i, int j) {
  int max_i = max(i, j);
  if (max_i >= V) {
    V = max_i + 1;
    Vertex.resize(V);
  }
  Vertex[i].Insert(j);
  Vertex[j].Insert(i); 
  E += 2;
}

void Graph::Display() {
  for (int i = 0; i < Vertex.size(); i++) {
    cout << i << " ---> ";
    Block* temp = Vertex[i].Adj;
    while(temp->next != NULL) {
      cout << temp->node.id << " ";
      temp = temp->next;
    }
    cout << endl;
  }
}

int main() {
  int u, v;
  Graph G(8, 9);
  for (int i = 0; i < G.E; i++) {
    cin >> u >> v;
    G.AddEdge(u, v);
  }
  G.Display();
  return 0;
}