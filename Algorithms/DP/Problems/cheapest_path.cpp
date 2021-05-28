/*
Given a matrix Cost[M][N], where Cost[i][j] denotes the cost of
passing through that cell (i, j). Find out the minimum total cost of
getting from top-left cell to bottom-right cell, i.e. the summation of 
all the cell-costs you cross along the way should be minimized.
*/

# include<bits/stdc++.h>

using namespace std;


vector<vector<int>> get_input(int m, int n);
int MinCostMemoized(int x1, int y1, vector<vector<int>> Cost, vector<vector<int>> &Memo);
int MinCostDP(vector<vector<int>> Cost);

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> Cost = get_input(m, n);
  vector<vector<int>> Memo(m, vector<int>(n, -1));
  cout << "\nMinimum Cost(Memoization) = " << MinCostMemoized(0, 0, Cost, Memo);
  cout << "\nMinimum Cost(DP) = " << MinCostDP(Cost);
}


vector<vector<int>> get_input(int m, int n) {
  vector<vector<int>> Cost(m, vector<int>(n, -1));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << "Enter the cost of cell(" << i << ", " << j << "): ";
      cin >> Cost[i][j];
    }
  }
  return Cost;
}


int MinCostMemoized(int x1, int y1, vector<vector<int>> Cost, vector<vector<int>> &Memo) {
  int m = Cost.size();           // # of Rows
  int n = Cost.front().size();    // # of Columns
  if (Memo[x1][y1] == -1){
    if ((x1 == m - 1) && (y1 == n -1)) {
      Memo[x1][y1] = Cost[x1][y1];
    }
    else if (x1 == m - 1) {
      Memo[x1][y1] = Cost[x1][y1] + MinCostMemoized(x1, y1 + 1, Cost, Memo);
    }
    else if (y1 == n - 1) {
      Memo[x1][y1] = Cost[x1][y1] + MinCostMemoized(x1 + 1, y1, Cost, Memo);
    }
    else {
      Memo[x1][y1] = Cost[x1][y1] + min(MinCostMemoized(x1, y1 + 1, Cost, Memo), MinCostMemoized(x1 + 1, y1, Cost, Memo));
    }
  }
  return Memo[x1][y1];
}

int MinCostDP(vector<vector<int>> Cost) {
  int m = Cost.size();           // # of Rows
  int n = Cost.front().size();    // # of Columns
  vector<vector<int>> Cache(m, vector<int>(n, -1));
  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >=0; j--) {
      if ((i == m - 1) && (j == n -1)) {
        Cache[i][j] = Cost[i][j];
      }
      else if (i == m - 1) {
        Cache[i][j] = Cost[i][j] + Cache[i][j + 1];
      }
      else if (j == n - 1) {
        Cache[i][j] = Cost[i][j] + Cache[i + 1][j];
      }
      else {
        Cache[i][j] = Cost[i][j] + min(Cache[i][j + 1],Cache[i + 1][j]);
      }
    }
  }
  return Cache[0][0];
}