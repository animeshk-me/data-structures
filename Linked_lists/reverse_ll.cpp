#include<bits/stdc++.h>

using namespace std;

class ListNode {
 public:
  int data;
  ListNode * nptr;
 
  // functions
  ListNode(int x); 
  ListNode(int x, ListNode*next);
  void show();
};

class List {
 public:
  ListNode * head;
 
  // functions
  List(int x);
  List();
  void insert(int x);
  void show();
  void delete_index(int idx);
  void delete_element(int element);
  List reverse();
  int get_mid();
};

int main() {
  List L(12);
  L.insert(13);
  // L.insert(123);
  // L.insert(23);
  // L.insert(56);
  // L.insert(1453);
  // L.insert(133);
  // L.show();
  // L.delete_element(56);
  // L.show();

  // L.delete_element(126);
  // L.show();
  // L.delete_element(133);
  // L.show();
  // L.delete_index(2);
  // L.show();
  // L.delete_index(4);
  L.show();
  // List Reversed = L.reverse();
  // cout << "After Reversal -" << endl;
  // Reversed.show();
  cout << "Mid Index = " << L.get_mid() << endl;
  return 0;  
}



List::List(int x) {
  head = new ListNode(x);
}

List::List() {
  head = NULL;
}

void List::insert(int x) {
  ListNode * ptr = head;
  while(ptr->nptr != NULL) ptr = ptr->nptr;
  ptr->nptr = new ListNode(x);
}

void List::show() {
  ListNode * ptr = head;
  cout << "List => ";
  while(ptr != NULL) {
    ptr->show();
    ptr = ptr->nptr;
  }
  cout << endl;
}

void List::delete_element(int element) {
  ListNode * ptr = head;
  while(ptr->nptr != NULL) {
    if (ptr->nptr->data == element) {
      ptr->nptr = ptr->nptr->nptr;
      cout << endl << element << " deleted successfully!!\n";
      return;
    }
    ptr = ptr->nptr;
  }
  cout << "Element to be deleted not found! :(\n";
}

void List::delete_index(int idx) {
  ListNode * ptr = head;
  int i = 0;
  while(ptr->nptr != NULL) {
    if ((i+1) == idx) {
      cout << endl << "Element " << ptr->nptr->data << " at index " << i+1 << " deleted successfully!!\n";
      ptr->nptr = ptr->nptr->nptr;
      return;
    }
    ptr = ptr->nptr;
    i++;
  }
  cout << "Index out of bound! :(\n";
}

List List::reverse() {
  List Reversed_list;
  if (head != NULL) {
    ListNode * ptr = NULL;
    ListNode * temp = head;
    ListNode * temp2;
    while(temp != NULL) {
      temp2 = temp;
      temp = temp->nptr;
      temp2->nptr = ptr;
      ptr = temp2;
    }
    Reversed_list.head = temp2;
  }
  return Reversed_list;
}

int List::get_mid() {
  int i = 0;
  if (head != NULL) {
    ListNode * fast_ptr = head;
    ListNode * slow_ptr = head;
    while((fast_ptr->nptr != NULL) && (fast_ptr->nptr->nptr != NULL)) {
      slow_ptr = slow_ptr->nptr;
      fast_ptr = fast_ptr->nptr->nptr;
      i++;
    }
  }
  return i;
}

ListNode::ListNode(int x) {
  data = x;
  nptr = NULL;
}
ListNode::ListNode(int x, ListNode*next) {
  data = x;
  nptr = next;
}
void ListNode::show() {
  cout << data << " ";
}

