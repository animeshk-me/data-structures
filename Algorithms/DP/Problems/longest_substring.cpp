/*
Q. Given a string of digits, find length of the longest 
substring such that sum of digits of the first half of 
the substring is same as the sum of digits of the 
second half.
*/

# include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int get_result_bruteForce(vector<int> arr);
int get_result_DP(vector<int> arr);

int main() {

  int len;
  // cin >> len;
  srand(time(0));
  len = rand() % 1000;
  vector<int> arr(len);
  for (int i = 0; i < len; i++) {
    // cin >> arr[i];
    arr[i] = rand() % 1000;
    }
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }


  auto start = high_resolution_clock::now();
  cout << "Length of the longest such substring is(brute2): " << get_result_bruteForce(arr) << endl;
  auto stop = high_resolution_clock::now(); 
  auto duration = duration_cast<microseconds>(stop - start); 
  cout << "Brute took time: " << fixed << duration.count() << setprecision(5) << endl; 


  start = high_resolution_clock::now(); 
  cout << "Length of the longest such substring is(DP): " << get_result_DP(arr) << endl;
  stop = high_resolution_clock::now(); 
  duration = duration_cast<microseconds>(stop - start); 
  cout << "DP took time: " << fixed << duration.count() << setprecision(5) << endl; 
  return 0;
}


int get_result_bruteForce(vector<int> arr) {
  int max_length = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j += 2) {
      int substring_length = j - i + 1;   // by default even
      if (max_length < substring_length) {
        int right_sum = 0;
        int left_sum = 0; 
        for (int ptr = 0; ptr < substring_length/2; ptr++) {
          left_sum += arr[i + ptr];
        }
        for (int ptr = substring_length/2; ptr < substring_length; ptr++) {
          right_sum += arr[i + ptr];
        }
        max_length = left_sum == right_sum ? substring_length : max_length; 
      }
    }
  }
  return max_length;
}


int get_result_DP(vector<int> arr) {
  vector<vector<int>> SumCache(arr.size(), vector<int>(arr.size(), -1));
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size(); j++) {
      if (i == j) 
        SumCache[i][j] = arr[i];
      else if (i < j) 
        SumCache[i][j] = SumCache[i][j - 1] + arr[j];
    }
  }
  int max_length = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j += 2) {
      int substring_length = j - i + 1;   // by default even
      if (max_length < substring_length) {
        int left_sum = SumCache[i][i + (substring_length / 2) - 1];
        int right_sum = SumCache[i + (substring_length / 2)][i + substring_length - 1];
        max_length = left_sum == right_sum ? substring_length : max_length; 
      }
    }
  }
  return max_length;
}