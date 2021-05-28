#include<bits/stdc++.h>

using namespace std;

#define NOT_FOUND -1
#define EMPTY -1

class Node {
 public:
  int data_; // the data stored in the node
  Node * next_; // the pointer to next node
  
  Node(int x);
  void Print();
  ~Node();
};

class LinkedList {
 public:
  Node * head_; // the head_ pointer
  int size_;  // size of the list

  LinkedList();
  int Search(int key);
  int get_data(int id);
  void Append(int key);
  void InsertAt(int key, int id);
  void Remove();
  void RemoveAt(int id);
  void Print();
  ~LinkedList();
};

Node get_middle_element(Node* head);

int main() {
    int size, data;
    LinkedList L;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> data;
        L.Append(data);
    }
    L.Print();
    Node temp_head = *(L.head_);
    cout << "temp_head: " << temp_head.next_->next_->data_ << endl; 
    Node middle_element = get_middle_element(L.head_);
    cout << "middle element: " << endl;
    middle_element.Print();
    return 0;
}


Node get_middle_element(Node* head) {
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    while(fast_ptr->next_ != NULL) {
        slow_ptr = slow_ptr->next_;
        if(fast_ptr->next_->next_ != NULL)
            fast_ptr = fast_ptr->next_->next_;
        else
            break;
    }
    return *slow_ptr;
}




/******************* (Node)Function Definitions ********************/
// Constructor
Node::Node(int x) {
  data_ = x;
  next_ = NULL;
}

// prints the node 
void Node::Print() {
  cout << "data = " << data_ << " next = " << next_ << endl;
}

// Destructor
Node::~Node() {
  cout << "Node is destructed " << data_ << endl;
}
/*******************************************************************/

/******************* (LinkedList)Function Definitions ********************/

// Constructor creates a list with one empty node
LinkedList::LinkedList() {
  head_ = NULL;
  size_ = 0;
}

// Insert a node with data_ KEY at the index ID in the list
void LinkedList::InsertAt(int key, int id) {
  if((id > size_) || (id < 0)) {
    cout << "[X]Index out of bound" << endl;
    return;
  }
  Node* infant = new Node(key);
  if(id == 0) {
    infant->next_ = head_;
    head_ = infant;
  }
  else {
    Node* trav = head_;
    int i = 0;
    while ((i <= id - 1) && (trav->next_ != NULL)) {
      trav = trav->next_;
      i++;
    }
    infant->next_ = trav->next_;
    trav->next_ = infant;
  }
  size_++;
}

// append a node at the tail-side(end) of the list
void LinkedList::Append(int key) {
  InsertAt(key, size_);
}

// remove the node located at the index ID
void LinkedList::RemoveAt(int id) {
  if((id >= size_) || (id <= 0)) {
    cout << "[X]Node to be deleted doesn't exist" << endl;
    return;
  }
  else if(size_ == 0)
    head_->data_ = EMPTY;
  else if(id == 0) {
    Node* to_be_killed = head_;
    head_ = head_->next_;
    delete to_be_killed;
  }
  else if(id < size_) { 
    Node* trav = head_;
    int i = 0;
    while (i != id - 1) {
      trav = trav->next_;
      i++;
    }
    Node* to_be_killed = trav->next_;
    trav->next_ = to_be_killed->next_;
    delete to_be_killed;
  }
  size_--;
}

// removes one node from the tail-side(end) of the list
void LinkedList::Remove() {
  RemoveAt(size_ - 1);
}

// returns the location of KEY in the list
int LinkedList::Search(int key) {
  Node* trav = head_;
  int i = 0;
  while (trav != NULL) {
    if(trav->data_ == key)
      return i;
    trav = trav->next_;
    i++;
  }
  cout << key << " not found" << endl;
  return NOT_FOUND;
}

// returns the value stored at the index ID
int LinkedList::get_data(int id) {
  if((id > size_) || (id < 0)) {
    cout << "[X]Index out of bound" << endl;
    return NOT_FOUND;
  }
  Node* trav = head_;
  int i = 0;
  while (id != i) {
    trav = trav->next_;
    i++;
  }
  return trav->data_;
}

// Print the list
void LinkedList::Print() {
  Node* trav = head_;
  int i = 0;
  cout << "[ ";
  while (trav != NULL) {
    cout << trav->data_ << " ";
    trav = trav->next_;
    i++;
  }
  cout << "], size: " << size_ << endl;
}

// destructor
LinkedList::~LinkedList() {
  cout << "List is destructed" << endl;
}

/*******************************************************************/