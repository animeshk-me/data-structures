#include<bits/stdc++.h>

using namespace std;

#define NOT_ROTATED -2

int search(vector<int>& arr, int target);
int get_pivot_index_binary_search(vector<int> &arr, int l, int r);
int binary_search_modified(vector<int> &arr, int l, int r, int target, int pivot);
int get_original_index(int rotated_index, int pivot_idx);
int get_rotated_index(int original_index, int pivot_idx, int size);
void debug_var(string name, int var);

void print_vec(vector<int> arr);
void stress_tester();

int main() {
    stress_tester();
    // int target, size;
    // cin >> size;
    // vector<int> arr(size, 0);
    // for (int i = 0; i < size; i++)
    //     cin >> arr[i];
    // cout << "Enter the value of target: ";
    // cin >> target;
    // cout << "Found at: " << search(arr, target) << endl;
    return 0;
}


int search(vector<int>& arr, int target) {
    int pivot = get_pivot_index_binary_search(arr, 0, arr.size() - 1);
    debug_var("pivot", pivot);
    return binary_search_modified(arr, 0, arr.size() - 1, target, pivot);
}

int binary_search_modified(vector<int> &arr, int l, int r, int target, int pivot) {
    if(r < l)
        return -1;
    int mid = l + (r - l) / 2;
    int mid_rotated = get_rotated_index(mid, pivot, arr.size());
    if(arr[mid_rotated] == target)
        return mid_rotated;
    else if(arr[mid_rotated] > target)
        return binary_search_modified(arr, l, mid - 1, target, pivot);
    else
        return binary_search_modified(arr, mid + 1, r, target, pivot);
}

// return the index in the unrotated_array
int get_original_index(int rotated_index, int pivot_idx) {
    if(rotated_index >= pivot_idx)
        return rotated_index - pivot_idx;
    return rotated_index + pivot_idx;
}

// return the index in the rotated_array
int get_rotated_index(int original_index, int pivot_idx, int size) {
    return (original_index + pivot_idx) % size;
}

int get_pivot_index_binary_search(vector<int> &arr, int l, int r) {
    int mid = l + (r - l) / 2;
    if(arr[mid] < arr[l]) {
        if(mid == l + 1)
            return mid;
        return get_pivot_index_binary_search(arr, l, mid);
    }
    else if(arr[mid] > arr[r]) {
        if(mid == r - 1)
            return r;
        return get_pivot_index_binary_search(arr, mid, r);
    }
    else
        return 0;
}


void debug_var(string name, int var) {
    cout << "[debug] " << name << ": " << var << endl;
}


void stress_tester() {
    srand(time(0));
    for(int u = 0; u < 100; u++) {
        int size = rand() % 100 + 2;
        vector<int> vec(size, 0);
        for (int i = 0; i < size; i++)
            vec[i] = rand() % 2000 - 1000;
        sort(vec.begin(), vec.end());
        int rand_no = rand() % size;
        rotate(vec.begin(), vec.begin()+rand_no, vec.end());
        int rand_idx = rand() % size;
        int target = vec[rand_idx];
        int got_idx = search(vec, target);
        if(got_idx != rand_idx) {
            print_vec(vec);
            debug_var("got_idx", got_idx);
            debug_var("rand_idx", rand_idx);
        }
    }
}

void print_vec(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*

12
20 21 25 26 28 29 12 13 14 15 17 18

*/