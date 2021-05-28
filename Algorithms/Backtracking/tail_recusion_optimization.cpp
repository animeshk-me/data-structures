#include<bits/stdc++.h>

using namespace std;

int fib(int n, int a);

int main() {
    int n;
    // cin >> n;
    for(int i = 0; i < 20; i++)
        cout << "fib(" << i << ") = " << fib(i, 0) << endl;
    return 0;
}

int fib(int n, int a) {
    if(n == 0 || n == 1)
        return n + a;
    a += fib(n - 2, 0);
    return fib(n - 1, a); 
}