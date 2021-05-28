#include<bits/stdc++.h>
using namespace std;


struct node {
  int data;
  struct node * nptr;
};

struct node * Append(struct node * head, int location, int num);
void PrintIterative(struct node * head);
void PrintRecursive(struct node * head);
void PrintRecursiveBackwards(struct node * head);

int main() {
  struct node * head = NULL;
  head = Append(head, 0, 10);
  head = Append(head, 1, 190);
  head = Append(head, 2, 132);
  head = Append(head, 1, 123);
  head = Append(head, 1, 234);
  head = Append(head, 2, 1223);
  head = Append(head, 3, 122);
  head = Append(head, 6, 49);
  PrintIterative(head);
  PrintRecursive(head);
  PrintRecursiveBackwards(head);
  return 0;
}

struct node * Append(struct node * head, int location, int num) {
  struct node * temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num;
  if(head != NULL) {
    struct node * ptr = head;
    int index = 0;
    while((index + 1) != location) {
      index++;
      ptr = ptr->nptr;
    }
    temp->nptr = ptr->nptr;
    ptr->nptr = temp;
  } else {
    temp -> nptr = NULL;
    head = temp;
  }
  return head;
}

void PrintIterative(struct node * head) {
  struct node * ptr = head;
  while(ptr->nptr != NULL) {
      cout << ptr->data << " ";
      ptr = ptr->nptr;
  }
  cout << ptr->data << endl;
}

void PrintRecursive(struct node * head) {
  if (head == NULL){
    cout << endl;
    return;
  }
  cout << head->data << " ";
  PrintRecursive(head->nptr);
}

void PrintRecursiveBackwards(struct node * head) {
  if (head != NULL) {
    PrintRecursiveBackwards(head->nptr);
    cout << " " << head->data;
  }
}