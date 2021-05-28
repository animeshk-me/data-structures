#include<bits/stdc++.h>

using namespace std;

void Print(vector <int> A);
void QuickSort(vector<int> &A, int l, int r);
int Partition(vector<int> &A, int l, int r);


int main() {
    srand(time(0));
    int size;
    size = rand() % 1000;
    vector<int> A(size);
    for (int i = 0; i < size; i++) 
        A[i] = rand() % 20000;
    Print(A);
    QuickSort(A, 0, size - 1);
    Print(A);
    return 0;
}

void Print(vector <int> A) {
    cout << "Size: " << A.size() << endl;
    for (int i = 0; i < A.size(); i++) 
        cout << A[i] << " ";
    cout << endl;    
}

void QuickSort(vector<int> &A, int l, int r) {
    if(l >= r)
        return;
    int m = Partition(A, l, r);
    QuickSort(A, l, m - 1);
    QuickSort(A, m + 1, r);
}

int Partition(vector<int> &A, int l, int r) {
    int pivot = l;
    int j = l;  // no small window in the beginning
    int i = l + 1; // pointer pointing at the next element from start
    while (i <= r) {
        if(A[i] <= A[pivot]) {
            iter_swap(A.begin()+i, A.begin()+j+1);
            j++;
        }
        i++;
    }
    iter_swap(A.begin()+j, A.begin()+pivot);
    return j;
}
