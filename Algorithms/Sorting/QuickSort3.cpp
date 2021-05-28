// Randomized implementation of quick sort (3way) to further improve quicksort in case of equal elements.

#include<bits/stdc++.h>

using namespace std;

void Print(vector <int> A);
void QuickSort3Rand(vector<int> &A, int l, int r);
vector<int> Partition3(vector<int> &A, int l, int r);
vector<int> Partition3Rand(vector<int> &A, int l, int r);
void HandleLessThan(vector<int> &A, int &j, int &k, int i, int l);
void HandleEqualTo(vector<int> &A, int &j, int &k, int i, int l);

int main() {
    srand(time(0));
    int size;
    // size = 10;
    size = rand() % 40000;
    // cin >> size;
    vector<int> A(size);
    // A = {1, 4, 5, 7, 9, 4, 3, 1, 4, 1};
    for (int i = 0; i < size; i++) 
        A[i] = rand() % 10000;
        // cin >> A[i];
    // Print(A);
    QuickSort3Rand(A, 0, size - 1);
    Print(A);
    return 0;
}

void Print(vector <int> A) {
    cout << A.size() << endl;
    for (int i = 0; i < A.size(); i++) 
        cout << A[i] << " ";
    cout << endl;    
}

void QuickSort3Rand(vector<int> &A, int l, int r) {
    if(l >= r)
        return;
    vector<int> m = Partition3Rand(A, l, r);
    QuickSort3Rand(A, l, m[0] - 1);
    QuickSort3Rand(A, m[1] + 1, r);
}

vector<int> Partition3Rand(vector<int> &A, int l, int r) {
    srand(time(0));
    // int rand_pivot = 4;
    int rand_pivot = (rand() % (r+1-l)) + l;
    // cout << "(" << l << "," << rand_pivot << "," << r <<") ";
    iter_swap(A.begin()+rand_pivot, A.begin()+l);
    return Partition3(A, l, r);
}

// 3 way partitioning
vector<int> Partition3(vector<int> &A, int l, int r) {
    int pivot = l;
    int j = l;  // no small window in the beginning
    int k = l;  // no equal window in the beginning
    int i = l + 1; // pointer pointing at the next element from start
    while (i <= r) {
        if(A[i] < A[pivot]) 
            HandleLessThan(A, j, k, i, l);
        else if(A[i] == A[pivot]) 
            HandleEqualTo(A, j, k, i, l);
        i++;
    }
    iter_swap(A.begin()+j, A.begin()+pivot);
    vector<int> return_val = {j, k};
    return return_val;
}

void HandleLessThan(vector<int> &A, int &j, int &k, int i, int l) {
    iter_swap(A.begin()+j+1, A.begin()+i);
    j++;
    if(k != l) {
        iter_swap(A.begin()+k+1, A.begin()+i);
        k++;
    }
}

void HandleEqualTo(vector<int> &A, int &j, int &k, int i, int l) {
    if(k == l) {
        iter_swap(A.begin()+j+1, A.begin()+i);
        k = j + 1;
    } else {
        iter_swap(A.begin()+k+1, A.begin()+i);
        k++;
    }
}