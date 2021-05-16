#include<bits/stdc++.h>

using namespace std;

int find_kth_largest(vector<int> arr, int k);

int main() {
    int k, size;
    cin >> size;
    vector<int> arr(size, 0);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Enter the value of k: ";
    cin >> k;
    cout << k << "th largest: " << find_kth_largest(arr, k) << endl;
    // for(int i = 1; i <= size; i++)
    //     cout << i << "th largest: " << find_kth_largest(arr, i) << endl;
    return 0;
}

// O(n*k) time
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