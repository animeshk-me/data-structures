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
    int min_cost = INFINITY;
    for (int i = 1; i <= 2; i++) {
      int this_route_min = MinCostBrute(source + i, destination, height) + abs(height[source] - height[source + i]);
      min_cost = min(min_cost, this_route_min);
    }
    return min_cost;
  }
  return 0;
}

int MinCostTopDownDP(int source, int destination, int * height, vector<int> &Memo) { // Memoized
  if (source < destination) {

    if (Memo[source] == -1) {
      
      if (source == destination - 1)
        Memo[source] = abs(height[source] - height[destination]);
      else {
        int min_cost = INFINITY;
        for (int i = 1; i <= 2; i++) {
          int this_route_min = MinCostTopDownDP(source + i, destination, height, Memo) + abs(height[source] - height[source + i]);
          min_cost = min(min_cost, this_route_min);
        }
        Memo[source] = min_cost;
      }
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


// int MinCostTopDownDP(int source, int destination, int * height, vector<int> &Memo) { // Memoized
//   if (source < destination) {
 
//     if (Memo[source] == -1) {
      
//       if (source == destination - 1)
//         Memo[source] = abs(height[source] - height[destination]);
//       int min_cost = INFINITY;
//       for (int i = 1; i <= 2; i++) {
//         int this_route_min = MinCostTopDownDP(source + i, destination, height, Memo) + abs(height[source] - height[source + i]);
//         min_cost = min(min_cost, this_route_min);
//       }
//       Memo[source] = min_cost;
//     }
//     return Memo[source];    
//   }
//   return 0;
// }