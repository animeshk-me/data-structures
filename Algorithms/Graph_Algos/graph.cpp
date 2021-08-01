#include<bits/stdc++.h>

using namespace std;


// Reprsents a single node of the adjancency list
class Node {
  public:
    int id;
    Node * next;
  Node(int id) {
      id = id;
      next = NULL;
  }
};


class Block {
  public:
    Node* node;
  Block() {
      node = NULL;
  }
  void append(int vertex_id);
  void print();
};

// Represents a Single Graph
class Graph {
  public:
    int num_edges;
    vector<Block*> vertices;
  Graph() {
      num_edges = 0; 
  }
  void add_edge(int vertex_id1, int vertex_id2);    // vertex1 --> vertex2
  bool remove_edge(int vertex_id1, int vertex_id2);    // vertex1 -!-> vertex2
  void print();
};


int main() {
    Graph G;
    G.add_edge(1, 4);
    G.add_edge(2, 4);
    G.add_edge(3, 5);
    G.add_edge(4, 7);
    G.print();
    return 0;
}


void Block::append(int vertex_id) {
    if(node == NULL) {
        node = new Node(vertex_id);
        return;
    }
    Node * temp = node;
    while(temp->next != NULL) 
        temp = temp->next;
    temp->next = new Node(vertex_id);
}

void Block::print() {
    cout << "hel";
    if(node == NULL) 
        cout << "(/)";
    Node * temp = node;
    while(temp->next != NULL) 
        cout << " " << temp->id;
        temp = temp->next;
    cout << endl;
}

void Graph::add_edge(int vertex_id1, int vertex_id2) {
    int max_vertex_id = max(vertex_id1, vertex_id2);
    for (int i = vertices.size(); i <= max_vertex_id; i++)
        vertices.push_back(new Block());
    cout << "void \n";
    vertices[vertex_id1]->append(vertex_id2);
    num_edges += 1;
}


bool Graph::remove_edge(int vertex_id1, int vertex_id2) {
    return true;
}

void Graph::print() {
    for(int i = 0; i < vertices.size(); i++) {
        cout << "List[" << i << "]:" << endl;
        vertices[i]->print();
    }
}