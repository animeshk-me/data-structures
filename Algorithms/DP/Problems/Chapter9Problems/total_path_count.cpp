#include<bits/stdc++.h>

using namespace std;

int TotalPathCountBrute(int start_i, int start_j, int width, int height) ;
int TotalPathCountDP(int start_i, int start_j, int width, int height);
int TotalPathCountMemoized(int start_i, int start_j, int width, int height, vector<vector<int>> Memo) ;

int main() {
  int width, height;
  cout << "Enter the width and height of the matrix: ";
  cin >> width >> height;
  cout << "Total Number of paths from top-left to bottom-right(Brute Force): " << TotalPathCountBrute(0, 0, width, height) << endl;
  cout << "Total Number of paths from top-left to bottom-right(DP Solution): " << TotalPathCountDP(0, 0, width, height) << endl;
  return 0;
  vector<vector<int>> Memo(height, vector<int>(width, 1));
  cout << "Total Number of paths from top-left to bottom-right(Memoized Solution): " << TotalPathCountMemoized(0, 0, width, height, Memo) << endl;
  return 0;
}

int TotalPathCountBrute(int start_i, int start_j, int width, int height) {
  if ((start_i == height - 1) && (start_j == width - 1))
    return 0;
  if (start_j == width - 1)
    return 1;
  if (start_i == height - 1)
    return 1;
  return TotalPathCountBrute(start_i + 1, start_j, width, height) + TotalPathCountBrute(start_i, start_j + 1, width, height);
}

int TotalPathCountDP(int start_i, int start_j, int width, int height) {
  vector<vector<int>> Cache(height, vector<int>(width, 1));
  // our goal is to initialize the last row and last column with 1
  Cache[height - 1][width - 1] = 0; // bottom right cell
  for (int i = height - 2; i >= 0; i--) {
    for (int j = width - 2; j >= 0; j--)
      Cache[i][j] = Cache[i][j+1] + Cache[i+1][j];
  }
  return Cache[start_i][start_j];
}

int TotalPathCountMemoized(int start_i, int start_j, int width, int height, vector<vector<int>> Memo) {
  if ((start_i == height - 1) && (start_j == width - 1))
    Memo[start_i][start_j] = 0;
  else if (start_j == width - 1)
    Memo[start_i][start_j] = 1;
  else if (start_i == height - 1)
    Memo[start_i][start_j] = 1;
  else
    Memo[start_i][start_j] =  TotalPathCountMemoized(start_i + 1, start_j, width, height, Memo) + TotalPathCountMemoized(start_i, start_j + 1, width, height, Memo);
  return Memo[start_i][start_j];
}