#include<bits/stdc++.h>

using namespace std;

class Heap {
  public:
    vector<int> A;
    int size
    int length;     // 0 <= size <= length
    void MaxHeapify();
  private:
    int get_left_id();
    int get_right_id();
}


int main() {


    return 0;
}

void MaxHeapify() {

}

void heapify(int id) {
    int left_child, right_child;
    left_child = 2 * id;
    right_child = left_child + 1;
    heapify(left_child);
    heapify(right_child);
    
}
