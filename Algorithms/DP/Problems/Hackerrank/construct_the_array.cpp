#include<bits/stdc++.h>

using namespace std;

long countArray(long i, long n, long k);
long countArrayMemo(long i, long n, long k, vector<int> &Memo);

int main() {
  long n, k, x;
  cin >> n >> k >> x;
  cout << countArray(n - 2, n, k) << endl;
  vector<int> Memo(n, -1);
  cout << countArrayMemo(n - 2, n, k, Memo) << endl;
  return 0;
}

long countArray(long i, long n, long k) {
  if (i == 0)
    return 1;
  long val = (countArray(i - 1, n, k))*(k - 1);
  if (i == (n - 2))
    val = val - 1; 
  return val;
}


long countArrayMemo(long i, long n, long k, vector<int> &Memo) {
  if (Memo[i] == -1)  {
    if (i == 0)
      Memo[i] = 1;
    else { 
      long val = (countArrayMemo(i - 1, n, k, Memo))*(k - 1);
      if (i == (n - 2))
        val = val - 1; 
      Memo[i] = val;
    }
  }
  return Memo[i];
}