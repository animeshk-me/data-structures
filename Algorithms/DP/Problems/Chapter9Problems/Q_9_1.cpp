#include<bits/stdc++.h>

using namespace std;

int NumberOfUniqueRoutes(int i, int j, int x, int y);
int NumberOfUniqueRoutesDP(int i, int j, int x, int y);
int NumberOfUniqueRoutesMemoized(int i, int j, int x, int y, vector<vector<int>> Memo);

int main() {
  int x, y;
  // int i, j;
  cin >> x >> y;
  cout << "Brute force: Total Number of unique routes =" << NumberOfUniqueRoutes(0, 0, x, y) << endl;
  cout << "DP Solution: Total Number of unique routes =" << NumberOfUniqueRoutesDP(0, 0, x, y) << endl;
  
  vector<vector<int>> Memo(x+1, vector<int>(y+1, -1));  
  cout << "Memoized Solution: Total Number of unique routes =" << NumberOfUniqueRoutesMemoized(0, 0, x, y, Memo) << endl;
  return 0;
}

int NumberOfUniqueRoutes(int i, int j, int x, int y) {
  if ((i == x) || (j == y))
    return 1;
  
  return (NumberOfUniqueRoutes(i + 1, j, x, y) + NumberOfUniqueRoutes(i, j + 1, x, y));
}

int NumberOfUniqueRoutesMemoized(int i, int j, int x, int y, vector<vector<int>> Memo) {
  if (Memo[i][j] == -1) {
    if ((i == x) || (j == y))
      Memo[i][j] = 1;
    else
      Memo[i][j] = (NumberOfUniqueRoutesMemoized(i + 1, j, x, y, Memo) + NumberOfUniqueRoutesMemoized(i, j + 1, x, y, Memo));
  }
  return Memo[i][j];
}

int NumberOfUniqueRoutesDP(int start_i, int start_j, int x, int y) {
  vector<vector<int>> Cache(x+1, vector<int>(y+1, -1));  
  for (int i = 0; i < Cache.size(); i++) {
    for (int j = 0; j < Cache[0].size(); j++) {
      if ((i == x) || (j == y))
        Cache[i][j] = 1;
    }
  }
  for (int i = Cache.size() - 2; i >= 0; i--) {
    for (int j = Cache[0].size() - 2; j >= 0; j--) {
      Cache[i][j] = Cache[i + 1][j] + Cache[i][j + 1];
    }
  }
  return Cache[start_i][start_j];
}