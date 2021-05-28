# include <bits/stdc++.h>

using namespace std;

int MinCostBrute(int source, int destination, int * height);
int MinCostTopDownDP(int source, int destination, int * height, vector<int> &Memo);
int MinCostBottomUpDP(int source, int destination, int * height);


int main() {
  int n;
  cin >> n;
  int height[n];
  for (int i = 0; i < n; i++) {
    cin >> height[i];
  }
  cout << "Minimum Cost(Brute) = " << MinCostBrute(0, n - 1, height) << endl;

  vector<int> Memo(n, -1);
  cout << "Minimum Cost(Memoized) = " << MinCostTopDownDP(0, n - 1, height, Memo) << endl;
  cout << "Minimum Cost(DP) = " << MinCostBottomUpDP(0, n - 1, height) << endl;
  return 0;
}

int MinCostBrute(int source, int destination, int * height) {
  if (source < destination) {

    int route1_min_value = MinCostBrute(source + 1, destination, height) + abs(height[source] - height[source + 1]);

    int route2_min_value = MinCostBrute(source + 2, destination, height) + abs(height[source] - height[source + 2]);

    return min(route1_min_value, route2_min_value);
  }
  return 0;
}

int MinCostTopDownDP(int source, int destination, int * height, vector<int> &Memo) { // Memoized
  if (source < destination) {

    if (Memo[source] == -1) {
      
      if (source == destination - 1)
        return abs(height[source] - height[destination]);

      int route1_min_value = MinCostTopDownDP(source + 1, destination, height, Memo) + abs(height[source] - height[source + 1]);

      int route2_min_value = MinCostTopDownDP(source + 2, destination, height, Memo) + abs(height[source] - height[source + 2]);

      Memo[source] = min(route1_min_value, route2_min_value);
    }
    return Memo[source];    
  }
  return 0;
}

int MinCostBottomUpDP(int source, int destination, int * height) {
  vector<int> Cache(destination + 1);
  Cache[destination] = 0;
  Cache[destination - 1] = abs(height[destination - 1] - height[destination]);
  for (int i = destination - 2; i >= source; i--) {
    int route1_min_value = Cache[i + 1] + abs(height[i] - height[i + 1]);
    int route2_min_value = Cache[i + 2] + abs(height[i] - height[i + 2]);
    Cache[i] = min(route1_min_value, route2_min_value);
  }
  return Cache[source];
}
