# include<bits/stdc++.h>
using namespace std;

int TotalNumberOfWaysMemoized(int x1, int y1, vector<vector<int>> Array);
int TotalNumberOfWaysDP(int x1, int y1, vector<vector<int>> Array);

int main() {
  int num;
  clock_t start, end;
  cin >> num;
  vector<vector<int>> Array(num, vector<int>(num, -1));

  start = clock();
  cout << "Memoized Solution: " << TotalNumberOfWaysMemoized(0, 0, Array) << endl;
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Memoized took time: " << fixed  
         << time_taken << setprecision(5) << endl; 

  start = clock();
  cout << "DP Solution: " << TotalNumberOfWaysDP(0, 0, Array) << endl;
  end = clock();
  time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "DP took time: " << fixed  
         << time_taken << setprecision(5) << endl; 
  return 0;
}


int TotalNumberOfWaysMemoized(int x1, int y1, vector<vector<int>> Array) {
  if (Array[x1][y1] == -1) {
    int N = Array.size();
    if ((x1 == N - 1) || (y1 == N - 1)) {
      Array[x1][y1] = 1;
    } else {
    Array[x1][y1] = TotalNumberOfWaysMemoized(x1, y1 + 1, Array) + TotalNumberOfWaysMemoized(x1 + 1, y1, Array);
    }
  }
  return Array[x1][y1];  
}


int TotalNumberOfWaysDP(int x1, int y1, vector<vector<int>> Array) {
  int N = Array.size();
  for (int i = 0; i < N; i++) {
    Array[i][N - 1] = 1;          // right most column
    Array[N - 1][i] = 1;          // bottom most row
  } 
  for (int i = N - 2; i >= 0; i--) {
    for (int j = N - 2; j >= 0; j--) {
      Array[i][j] = Array[i + 1][j] + Array[i][j + 1];
    }
  }
  return Array[x1][y1];  
}

