#include<bits/stdc++.h>

using namespace std;

class Node {
  public:   
    int val;
    Node * next;
  public:
    Node(int _num) {
        val = _num;
        next = NULL;
    }
};


class MyQueue {
  public:
    Node *front;
    Node *rear;
  public:
    MyQueue();
    void push(int _num);
    void pop();
    int peek();
    bool is_empty();
};

int main() {
    MyQueue S;
    // S.push(2);
    // S.push(564);
    // S.push(345);
    // cout << S.peek() << endl;    2
    // S.push(445);
    // cout << S.peek() << endl;    2
    // S.pop();
    // cout << S.peek() << endl;    564
    // S.push(435);
    // S.push(135);
    // cout << S.peek() << endl;    564
    // S.pop();
    // cout << S.peek() << endl;    345
    // S.pop();
    // cout << S.peek() << endl;    445
    // S.pop();
    // cout << S.peek() << endl;    435
    // S.pop();
    // cout << S.peek() << endl;    135
    // S.pop();
    // cout << S.peek() << endl;    
    S.push(2);
    S.push(4);
    cout << S.peek() << endl;
    S.pop();
    cout << S.peek() << endl;
    S.pop();
    cout << S.peek() << endl;
    S.pop();
    
    return 0;
}



MyQueue::MyQueue() {
    front = NULL;
    rear = NULL;
}

void MyQueue::push(int _num) {
    Node * new_node = new Node(_num);
    if(front)
        front->next = new_node;
    front = new_node;
    rear = rear == NULL ? front : rear;
}


void MyQueue::pop() {
    if(is_empty()) {
        cout << "Can't pop from empty Queue\n";
        return;
    }
    Node* to_be_deleted = rear;
    if(rear == front) {
        rear = NULL;
        front = NULL;
    } else {
        rear = rear->next;
    }
    free(to_be_deleted);
}


int MyQueue::peek() {
    if(is_empty()) {
        cout << "Queue empty\n";
        return -1;
    }
    return rear->val;
}

bool MyQueue::is_empty() {
    return (rear == NULL);
}