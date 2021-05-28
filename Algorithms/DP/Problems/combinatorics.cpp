/*

  _______________________Important Notes_______________________
  --> Find the value of nCr or C(n, r) using TopDownDP(Memoization) and
  BottomUPDP(Dynamic Programming) approaches.
  --> This is the only problem I have encounterd till now, where DP 
  consumes both more space and more time than corresponding Memoization
  solution.

*/

# include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int SelectionMemoized(int n, int r, vector<vector<int>> &Memo);
int SelectionDP(int n, int r);

int main() {
  int n, r, p;
  // cin >> n >> r;
  n = 100;
  r = 40;
  vector<vector<int>> Memo(n + 1, vector<int>(r + 1, -1)); // n + 1 rows, r + 1 columns
  cout << "1 for memoized, 0 for DP: ";
  cin >> p;
  switch(p) {
    case 1:{
      auto start = high_resolution_clock::now(); 
      cout << "C(n, r)(Memoized) = " << SelectionMemoized(n, r, Memo) << endl;
      auto stop = high_resolution_clock::now(); 
      auto duration = duration_cast<microseconds>(stop - start); 
      cout << "Memoized took time: " << fixed << duration.count() << setprecision(5) << endl;
      break;}

    case 0:{
      auto start = high_resolution_clock::now(); 
      cout << "C(n, r)(DP) = " << SelectionDP(n, r) << endl;
      auto stop = high_resolution_clock::now(); 
      auto duration = duration_cast<microseconds>(stop - start); 
      cout << "DP took time: " << fixed << duration.count() << setprecision(5) << endl;
      break;}
  }
  

  return 0;
}


// Memo[i][j] stores the value of C(i, j)
int SelectionMemoized(int n, int r, vector<vector<int>> &Memo) {
  if ((r == 0) || (n == r)) 
    Memo[n][r] = 1;

  if (Memo[n][r] == -1) 
    Memo[n][r] = SelectionMemoized(n - 1, r, Memo) + SelectionMemoized(n -1, r - 1, Memo);

  return Memo[n][r];
}


int SelectionDP(int n, int r) {
  vector<vector<int>> Cache(n + 1, vector<int>(r + 1, -1)); // n + 1 rows, r + 1 columns
  for (int i = 0; i <=n; i++) {
    for (int j = 0; j <= r; j++) {
      if ((j == 0) || (i == j))
        Cache[i][j] = 1;
      else if (i > j)
        Cache[i][j] = Cache[i - 1][j] + Cache[i - 1][j - 1];
    }
  }
  return Cache[n][r];
}