/**
 * @author Animesh Kumar
 * @email 24animesh11@gmail.com
 * @create date 09-02-2021
 * @modify date 09-02-2021
 * @desc Singly linked list implementation
 */

#include<bits/stdc++.h>

using namespace std;

#define NOT_FOUND -1
#define EMPTY -1

// The class reperesenting a single node
class Node {
 public:
  int data_; // the data stored in the node
  Node * next_; // the pointer to next node
  
  Node(int x);
  void Print();
  ~Node();
};

// They class representing a linked list
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

int main() {
  LinkedList List;
  List.Append(3);
  List.Append(6);
  List.Append(9);
  List.Append(2);
  List.Append(33);
  List.Append(71);
  List.Print();
  List.InsertAt(23, 2);
  List.Print();
  List.Remove();
  List.Print();
  List.InsertAt(12, 4);
  List.Print();
  int key = 6;
  int c = List.get_data(key);
  if(c != NOT_FOUND)
    cout << "List[" << key << "]: " << c << endl;
  c = List.Search(key);
  if(c != NOT_FOUND)
    cout << "Key found at " << c << endl;
  List.RemoveAt(4);
  List.Print();
  cout << "List size = " << List.size_ << endl;
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

/******************* (Node)Function Definitions ********************/

// Constructor creates a list with one empty node
LinkedList::LinkedList() {
  head_ = new Node(EMPTY); // representing empty node
  head_->next_ = NULL;
  size_ = 0;
}

// Insert a node with data_ KEY at the index ID in the list
void LinkedList::InsertAt(int key, int id) {
  if((id > size_) || (id < 0)) {
    cout << "[X]Index out of bound" << endl;
    return;
  }
  else if(size_ == 0)
    head_->data_ = key;
  else if(id <= size_) { 
    Node* infant = new Node(key);
    Node* trav = head_;
    int i = 0;
    while (i != id - 1) {
      if(trav->next_ == NULL)
        break;
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
  if((id >= size_) || (id < 0)) {
    cout << "[X]Index out of bound" << endl;
    return;
  }
  else if(size_ == 0)
    head_->data_ = 0;
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