#include<bits/stdc++.h>

using namespace std;

int find_kth_largest(vector<int> arr, int k);
int find_kth_smallest(vector<int> arr, int k);
int find_kth_smallest_quick(vector<int> arr, int k);
void QuickSortModifiedRand(vector<int> &A, int l, int r, int k);
int Partition(vector<int> &A, int l, int r);
int PartitionRand(vector<int> &A, int l, int r);

int main() {
    int k, size;
    cin >> size;
    vector<int> arr(size, 0);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Enter the value of k: ";
    // cin >> k;
    // cout << k << "th largest: " << find_kth_smallest_quick(arr, k) << endl;
    for(int i = 1; i <= size; i++)
        cout << i << "th largest: " << find_kth_smallest_quick(arr, i) << endl;
    return 0;
}

// O(n*k) time bruteforce
int find_kth_largest(vector<int> arr, int k) {
    int end = arr.size();
    while(k != 0) {
        end--;
        for(int i = 0; i < end; i++) {
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        k--;
    }
    return arr[end];
}

// O(n*k) time bruteforce
int find_kth_smallest(vector<int> arr, int k) {
    int end = arr.size();
    while(k != 0) {
        end--;
        for(int i = 0; i < end; i++) {
            if(arr[i] < arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        k--;
    }
    return arr[end];
}

/**********************************************************************************/

// the famous quick select algorithm with randomised pivoting gives guaranteed O(n) running time complexity and O(1) space
int find_kth_smallest_quick(vector<int> arr, int k) {
    QuickSortModifiedRand(arr, 0, arr.size() - 1, k);
    return arr[k - 1];
}

void QuickSortModifiedRand(vector<int> &A, int l, int r, int k) {
    if(l >= r)
        return;
    int m = PartitionRand(A, l, r);
    if (m == k - 1)
        return;
    else if (m < k - 1)
        QuickSortModifiedRand(A, m + 1, r, k);
    else
        QuickSortModifiedRand(A, l, m - 1, k);
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

int PartitionRand(vector<int> &A, int l, int r) {
    srand(time(0));
    int rand_pivot = (rand() % (r+1-l)) + l;
    iter_swap(A.begin()+rand_pivot, A.begin()+l);
    return Partition(A, l, r);
}


/**********************************************************************************/
