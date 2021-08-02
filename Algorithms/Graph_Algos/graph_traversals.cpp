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
    bool is_visited;
    int distance;
  Block() {
      this->node = NULL;
      this->is_visited = false;
      this->distance = INFINITY;
  }
  void append(int vertex_id);
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
  void breadth_first_search(int source_id);
  void print();
};

int main() {
    UnDirectedGraph G2;
    // G2.add_edge(1, 2);
    // G2.add_edge(2, 3);
    // G2.add_edge(3, 5);
    // G2.add_edge(1, 4);
    // G2.add_edge(4, 5);
    // G2.add_edge(7, 4);
    // G2.add_edge(7, 6);
    // G2.add_edge(6, 11);
    // G2.add_edge(11, 10);
    // G2.add_edge(8, 10);
    // G2.add_edge(8, 9);
    // G2.add_edge(8, 7);
    G2.add_edge(1, 2);
    G2.add_edge(1, 7);
    G2.add_edge(1, 4);
    G2.add_edge(1, 5);
    G2.add_edge(1, 6);
    G2.add_edge(7, 2);
    G2.add_edge(7, 8);
    G2.add_edge(2, 3);
    G2.add_edge(6, 10);
    G2.add_edge(5, 9);
    G2.add_edge(4, 9);
    cout << "Number of edges in G2: " << G2.num_edges << endl;
    G2.print();
    G2.breadth_first_search(1);
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


void UnDirectedGraph::breadth_first_search(int source_id) {
    queue<int> pending_queue;
    pending_queue.push(source_id);
    while(!(pending_queue.empty())) {
        int vertex_id = pending_queue.front();
        pending_queue.pop();
        if (vertices[vertex_id]->is_visited)
            continue;
        vertices[vertex_id]->is_visited = true;
        cout << vertex_id << " ";
        Node * temp = vertices[vertex_id]->node;
        while(temp != NULL) {
            if (!(vertices[temp->id]->is_visited)) 
                pending_queue.push(temp->id);
            temp = temp->next;
        }
    }
}