# include<bits/stdc++.h>

using namespace std;

vector<vector<int>> get_input(vector<vector<int>> cost_from_to, int num_of_stations);
void PrintCost(vector<vector<int>> array);
vector<int> MinimumCostToDestinationIterativeDP(vector<vector<int>> Cost_from_to);
int MinTravelCostMemoized(int source, int destination, vector<vector<int>>Cost, vector<vector<int>> &Memo);
int MinTravelCostDP(int source, int destination, vector<vector<int>>Cost);
int get_cost_of_route(int source, int intermediate, int destination, vector<vector<int>> Cost, vector<vector<int>> &Memo);

int main() {
  int num_of_stations;
  cin >> num_of_stations;
  vector<vector<int>> cost_from_to;
  vector<int> MinCost;
  cost_from_to = get_input(cost_from_to, num_of_stations);
  PrintCost(cost_from_to);
  MinCost = MinimumCostToDestinationIterativeDP(cost_from_to);
  int i = 0;
  for (auto it = MinCost.begin(); it != MinCost.end(); it++, i++) {
    cout << "MinCost From Station " << i << " = " << *it << endl;
  }
  cout << MinTravelCostDP(0, 4, cost_from_to) << endl;
  vector<vector<int>> Memo(cost_from_to.size(), vector<int> (cost_from_to.size(), -1));
  cout << MinTravelCostMemoized(0, 4, cost_from_to, Memo) << endl;
  return 0;
}


vector<int> MinimumCostToDestinationIterativeDP(vector<vector<int>> Cost_from_to) {
  int n = Cost_from_to.size();
  vector<int> MinimumCost(n);
  MinimumCost[n - 1] = 0;
  MinimumCost[n - 2] = Cost_from_to[n - 2][n - 1];
  for (int i = n - 3; i >= 0; i--) {
    int min_cost = Cost_from_to[i][n - 1];
    for (int j = i + 1; j < n; j++) {
      min_cost = min(min_cost, Cost_from_to[i][j] + MinimumCost[j]);
    }
    MinimumCost[i] = min_cost;
  }
  return MinimumCost;
}


int MinTravelCostMemoized(int source, int destination, vector<vector<int>>Cost, vector<vector<int>> &Memo) {
  if ((source == destination) || ((source + 1) == destination)) {
    Memo[source][destination] = Cost[source][destination];
  }

  else if (Memo[source][destination] == -1) {
    int min_cost = Cost[source][destination];
    for (int i = source + 1; i < destination; i++) {
      int temp_cost = get_cost_of_route(source, i, destination, Cost, Memo);
      min_cost = min(min_cost, temp_cost); 
    }
    Memo[source][destination] = min_cost;
  }
  return Memo[source][destination];
}

int MinTravelCostDP(int source, int destination, vector<vector<int>>Cost) {
  int total_stations = Cost.size();
  vector<vector<int>> Cache(total_stations, vector<int> (total_stations, -1));  
  for (int i = destination; i >= source; i--) {
    for (int j = source; j <= destination; j++){
      if ((i == j) || (i + 1 == j))
        Cache[i][j] = Cost[i][j];
      else if (i < j) {
        Cache[i][j] = Cost[i][j];
        for (int ptr = i + 1; ptr <= j; ptr++) {
          Cache[i][j] = min(Cache[i][ptr] + Cache[ptr][j], Cache[i][j]);
        }
      }
    }
  }
  PrintCost(Cache);cout << endl;
  return Cache[source][destination];
}


int get_cost_of_route(int source, int intermediate, int destination, vector<vector<int>> Cost, vector<vector<int>> &Memo) {
  return (MinTravelCostMemoized(source, intermediate, Cost, Memo) + MinTravelCostMemoized(intermediate, destination, Cost, Memo));
}


vector<vector<int>> get_input(vector<vector<int>> cost_from_to, int num_of_stations) {
  int temp;
  vector<vector<int>> final_array;
  for (int i = 0; i < num_of_stations; i++) {
    vector<int> temp_array;
    for (int j = 0; j < num_of_stations; j++) {
      if (i < j) {
        cout << "Enter cost from " << i << " to " << j << ": ";
        cin >> temp;
        temp_array.push_back(temp);
      } else {
        temp_array.push_back(0);
      }
    }
    final_array.push_back(temp_array);
  }
  cout << endl;
  return final_array;
}


void PrintCost(vector<vector<int>> array) {
  int i = 0;
  cout << "          ";
  for (int i = 0; i < array.size(); i++) {
    cout << i << "      ";
  }
  cout << endl;  
  for (auto it = array.begin(); it != array.end(); it++, i++) {
    cout << "From " << i << "|   ";
    for (auto i = it->begin(); i != it->end(); i++) {
      cout << *i << "      ";
    }
    cout << endl; 
  }
  cout << endl;
}