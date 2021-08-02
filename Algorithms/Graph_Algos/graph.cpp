#include<bits/stdc++.h>

using namespace std;

// Respresents a single node of the linked list w.r.to a vertex in the adjancency list
class Node {
  public:
    int id;
    Node * next;
  Node(int id) {
      this->id = id;
      this->next = NULL;
  }
};



// Reprsents a single node of the adjancency list
class Block {
  public:
    Node* node;
  Block() {
      this->node = NULL;
  }
  void append(int vertex_id);
  void print();
};

// Represents a Single DirectedGraph
class DirectedGraph {
  public:
    int num_edges;
    vector<Block*> vertices;
  DirectedGraph() {
      num_edges = 0; 
  }
  void add_edge(int vertex_id1, int vertex_id2);    // vertex1 --> vertex2
  void print();
};

// Represents a Single UnDirectedGraph
class UnDirectedGraph {
  public:
    int num_edges;
    vector<Block*> vertices;
  UnDirectedGraph() {
      num_edges = 0; 
  }
  void add_edge(int vertex_id1, int vertex_id2);    // vertex1 --> vertex2
  void print();
};

int main() {
    DirectedGraph G;
    G.add_edge(1, 2);
    G.add_edge(2, 3);
    G.add_edge(2, 4);
    G.add_edge(2, 13);
    G.add_edge(4, 3);
    G.add_edge(4, 5);
    G.add_edge(6, 5);
    G.add_edge(6, 8);
    G.add_edge(7, 6);
    G.add_edge(12, 13);
    G.add_edge(12, 10);
    G.add_edge(12, 11);
    G.add_edge(11, 12);
    G.add_edge(10, 9);
    G.add_edge(8, 9);
    cout << "Number of edges in G: " << G.num_edges << endl;
    G.print();

    UnDirectedGraph G2;
    G2.add_edge(1, 2);
    G2.add_edge(2, 3);
    G2.add_edge(3, 5);
    G2.add_edge(1, 4);
    G2.add_edge(4, 5);
    G2.add_edge(7, 4);
    G2.add_edge(7, 6);
    G2.add_edge(6, 11);
    G2.add_edge(11, 10);
    G2.add_edge(8, 10);
    G2.add_edge(8, 9);
    G2.add_edge(8, 7);
    cout << "Number of edges in G2: " << G2.num_edges << endl;
    G2.print();
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
    if(node == NULL) { 
        cout << " -> (/)\n";
        return;
    }
    Node * temp = node;
    while(temp->next != NULL) {
        cout << " -> " << temp->id;
        temp = temp->next;
    }
    cout << " -> " << temp->id << endl;
}

void DirectedGraph::add_edge(int vertex_id1, int vertex_id2) {
    int max_vertex_id = max(vertex_id1, vertex_id2);
    for (int i = vertices.size(); i <= max_vertex_id; i++)
        vertices.push_back(new Block());
    vertices[vertex_id1]->append(vertex_id2);
    num_edges += 1;
}


void DirectedGraph::print() {
    for(int i = 0; i < vertices.size(); i++) {
        cout << "List[" << i << "]:";
        vertices[i]->print();
    }
}

void UnDirectedGraph::add_edge(int vertex_id1, int vertex_id2) {
    int max_vertex_id = max(vertex_id1, vertex_id2);
    for (int i = vertices.size(); i <= max_vertex_id; i++)
        vertices.push_back(new Block());
    vertices[vertex_id1]->append(vertex_id2);
    vertices[vertex_id2]->append(vertex_id1);
    num_edges += 1;
}


void UnDirectedGraph::print() {
    for(int i = 0; i < vertices.size(); i++) {
        cout << "List[" << i << "]:";
        vertices[i]->print();
    }
}