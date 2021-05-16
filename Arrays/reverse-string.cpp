#include<bits/stdc++.h>

using namespace std;

void reverse_string(vector<char> &s);
void reverse_st(vector<char> &s, int start, int end);
void reverse_st_brute(vector<char>&s, int start, int end);


int main() {
    int size;
    cin >> size;
    vector<char> s(size);
    for(int i = 0; i < size; i++)
        cin >> s[i];
    reverse_string(s);
    for(int i = 0; i < size; i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}

void reverse_string(vector<char> &s) {
    reverse_st_brute(s, 0, s.size() - 1);
}

// O(n) space; O(n) time
void reverse_st_brute(vector<char>&s, int start, int end) {
    vector<char> dest(s.size());
    for(int i = start; i <= end; i++) 
        dest[end - i] = s[i];
    for(int i = start; i <= end; i++) 
        s[i] = dest[i];
}

// in place array/string reversal ==> T(n) = T(n - 1) + O(n)  ==> T(n) = O(n^2)
void reverse_st(vector<char> &s, int start, int end) {
    if(end == start + 1) {
        swap(s[start], s[end]);
        return;
    }
    int start_node = s[start];
    reverse_st(s, start + 1, end);
    for (int i = start; i < end; i++)
        s[i] = s[i + 1];
    s[end] = start_node;
}

// under construction
void reverse_st_iterative(vector<char> &s, int start, int end) {
    int ptr = start;
    int start_node;
    while(ptr != end - 1) {
        start_node = s[ptr];
        
    }
}