/*

Qn: A player can score only 3, 5 or 10 points in one move, Find the
  Total number of ways of scoring a given score N.

*/

# include<bits/stdc++.h>

using namespace std;

int NumberOfWaysMemoized(int num, vector<int> &Memo);
int NumberOfWaysDP(int num);

int main() {

  int num;
  cin >> num;
  vector<int> Memo(num + 1, -1);
  cout << "Memoized soln: " << NumberOfWaysMemoized(num, Memo) << endl;
  cout << "DP soln: " << NumberOfWaysDP(num) << endl;
  return 0;
}

int NumberOfWaysMemoized(int num, vector<int> &Memo) {
  if (num < 0)
    return 0;
  if (Memo[num] == -1) {
    if (num == 0)
      Memo[num] = 1;
    else {
      Memo[num] = NumberOfWaysMemoized(num - 3, Memo) + NumberOfWaysMemoized(num - 5, Memo) + NumberOfWaysMemoized(num - 10, Memo);
    }
  }
  return Memo[num];
}

int NumberOfWaysDP(int num) {
  vector<int> Cache(num + 1);
  for (int i = 0; i <= num; i++) {
    if (i == 0) 
      Cache[i] = 1;
    else if (i < 3)
      Cache[i] = 0;
    else if (i < 5)
      Cache[i] = Cache[i - 3];
    else if (i < 10)
      Cache[i] = Cache[i - 3] + Cache[i - 5];
    else 
      Cache[i] = Cache[i - 3] + Cache[i - 5] + Cache[i - 10];
  }
  return Cache[num];
}