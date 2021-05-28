# include <bits/stdc++.h>

using namespace std;

int MaxSubArraySumBrute(vector<int> Array);
int MaxSubArraySumDP(vector<int> Array);
int get_value(int i, int j, vector<vector<int>> &Memo, vector<int> Array);
int MaxSubArraySumMemoization(vector<int> Array, vector<vector<int>> &Memo);



int main() {
  int size; 
  srand(time(0));
  while(true) {
    // cin >> size;
    size = rand() % 1000 + 1;
    vector<int> Array(size);
    vector<vector<int>> Memo(size, vector<int>(size, -1));
    for (int i = 0; i < size; i++){
      Array[i] = rand() % 1000;
      // cin >> Array[i];
    }
    int brute = MaxSubArraySumBrute(Array);
    int dp = MaxSubArraySumDP(Array);
    int memo = MaxSubArraySumMemoization(Array, Memo);
    if ((brute != dp) || (brute != memo)) {
        cout << "Brute Soln: " << brute << endl;
        cout << "DP Soln: " << dp << endl;
        cout << "Memo Soln: " << memo << endl;
        break;
    }
    cout << "ok " << brute << " " << dp << " " << memo << endl;
  // cout << "Brute Soln: " << MaxSubArraySumBrute(Array) << endl;
  // cout << "Memoization Soln: " << MaxSubArraySumMemoization(Array, Memo) << endl;
  // cout << "DP Soln: " << MaxSubArraySumDP(Array) << endl;
  }
}

int MaxSubArraySumBrute(vector<int> Array) {
  int max_sum = 0;
  for (int i = 0; i < Array.size(); i++) {
    for (int j = i; j < Array.size(); j++) {  // uniquely identify the subarray
      int subarray_len = j - i + 1;
      int subarray_sum = 0;
      for (int ptr = 0; ptr < subarray_len; ptr++)
        subarray_sum += Array[i + ptr];
      max_sum = subarray_sum > max_sum ? subarray_sum : max_sum;
    }
  }
  return max_sum;
}

int MaxSubArraySumDP(vector<int> Array) {
  int size = Array.size();
  vector<vector<int>> Cache(size, vector<int>(size, -1));
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {  // uniquely identify the subarray
      if (i == j)
        Cache[i][j] = Array[i];
      else {
        Cache[i][j] = Cache[i][j - 1] + Array[j];
      }
    }
  }
  int max_sum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {  // uniquely identify the subarray
      int subarray_len = j - i + 1;
      max_sum = Cache[i][j] > max_sum ? Cache[i][j] : max_sum;
    }
  }
  return max_sum;
}


int MaxSubArraySumMemoization(vector<int> Array, vector<vector<int>> &Memo) {
  int max_sum = 0;
  for (int i = 0; i < Array.size(); i++) {
    for (int j = i; j < Array.size(); j++) {  // uniquely identify the subarray
      int subarray_len = j - i + 1;
      int subarray_sum = get_value(i, j, Memo, Array);
      max_sum = subarray_sum > max_sum ? subarray_sum : max_sum;
    }
  }
  return max_sum;
}

int get_value(int i, int j, vector<vector<int>> &Memo, vector<int> Array) {
  if (Memo[i][j] == -1) {
    if (i == j)
      Memo[i][j] = Array[i];
    else
      Memo[i][j] = Array[j] + get_value(i, j - 1, Memo, Array); 
  }
  return Memo[i][j];
}



