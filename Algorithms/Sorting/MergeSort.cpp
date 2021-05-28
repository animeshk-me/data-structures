#include<bits/stdc++.h>

using namespace std;

void MergeSort(vector<int> &arr, int l, int h);
void Merge(vector<int> &arr, int l, int mid, int h);
void copy_contents(vector<int> &final, vector<int> &arr, int l, int h);
void print(vector<int> arr);

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for(int i = 0; i < n; i++) cin >> arr[i];
  MergeSort(arr, 0, n - 1);
  print(arr);
  return 0;
}

void print(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << endl;
}

void MergeSort(vector<int> &arr, int l, int h) {
  if (l >= h) return;
  int mid = (l + h) / 2;
  MergeSort(arr, l, mid);
  MergeSort(arr, mid + 1, h);
  // print(arr);
  Merge(arr, l, mid, h);
}

void Merge(vector<int> &arr, int l, int mid, int h) {
  vector<int>final(h - l + 1, 0);
  int k = 0;
  int i = l;
  int j = mid + 1;
  while ((i <= mid) && (j <= h) && (k < arr.size())) {
    if (arr[i] < arr[j]) {
      final[k] = arr[i];
      i++;
    }
    else {
      final[k] = arr[j];
      j++;
    }
    k++;
  }
  print(final);
  copy_contents(final, arr, l, h);
}

void copy_contents(vector<int> &final, vector<int> &arr, int l, int h) {
  for (int i = l; i <= h; i++) {
    arr[i + l] = final[i];
  }
}