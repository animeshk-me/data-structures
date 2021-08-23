#include<bits/stdc++.h>

using namespace std;


class MyStack {
  public:
    int max_size;
    int * arr;
    int top;
  public:
    MyStack(int _max_size);
    void push(int _num);
    void pop();
    int peek();
    bool is_empty();
};

int main() {
    MyStack S(5);
    cout << S.max_size << endl;
    S.push(2);
    S.push(564);
    S.push(345);
    cout << S.peek() << endl;    
    S.push(445);
    cout << S.peek() << endl;    
    S.pop();
    cout << S.peek() << endl;    
    S.push(435);
    S.push(135);
    cout << S.peek() << endl;    
    S.pop();
    cout << S.peek() << endl;    
    S.pop();
    cout << S.peek() << endl;    
    S.pop();
    cout << S.peek() << endl;    
    S.pop();
    cout << S.peek() << endl;    
    S.pop();
    cout << S.peek() << endl;    
    return 0;
}



MyStack::MyStack(int _max_size) {
    max_size = _max_size;
    arr = (int *)malloc(sizeof(int) * max_size);
    top = -1;
}

void MyStack::push(int _num) {
    if(top == max_size - 1) {
        cout << "MyStack overflowed\n";
        return;
    }
    top++;
    arr[top] = _num;
}


void MyStack::pop() {
    if(is_empty()) {
        cout << "Can't pop from empty stack\n";
        return;
    }
    top--;
}


int MyStack::peek() {
    if(is_empty()) {
        cout << "Stack empty\n";
        return -1;
    }
    return arr[top];
}

bool MyStack::is_empty() {
    return (top == -1);
}