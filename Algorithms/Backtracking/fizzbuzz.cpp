#include<bits/stdc++.h>

using namespace std;


int main() {
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    for(int i = 0 ; i < 100; i++) {
        string text = "";
        if(c1 == 3) {
            text.append("fizz");
            c1 = 0;
        }
        if(c2 == 5) {
            text.append("buzz");
            c2 = 0;
        }
        text = text == "" ? to_string(i) : text;
        cout << text << endl;
        c1++;
        c2++;
    }
    return 0;
}