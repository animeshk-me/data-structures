# include<bits/stdc++.h>

using namespace std;

int MinBills(int n, vector<int> &bills);
int MinBillsMemoized(int n, vector<int> &bills, vector<int> &Memo);

int main() {
  int n;
  vector<int>bills = {1, 5, 10, 20, 100};
  cin >> n;
  // cout << MinBills(n, bills) << endl;

  vector<int>Memo(n+1, -1);
  cout << MinBillsMemoized(n, bills, Memo) << endl;
}

// int MinBills(int n, vector<int> &bills) {
//   if (n <= 0)
//     return 0;
//   int minimum_bills = INFINITY;
//   for (int i = 0; i < bills.size(); i++) {
//     if (n >= bills[i])
//       minimum_bills = min(minimum_bills, MinBills(n - bills[i], bills)+1);
//   }
//   return minimum_bills;
// }


int MinBills(int n, vector<int> &bills) {
  int minimum_bills = INFINITY;
  for (int i = 0; i < bills.size(); i++) {
    if (n == bills[i])
      return 1;
    if (n > bills[i])
      minimum_bills = min(minimum_bills, MinBills(n - bills[i], bills)+1);
  }
  return minimum_bills;
}

int MinBillsMemoized(int n, vector<int> &bills, vector<int> &Memo) {
  if (Memo[n] == -1) {
    int minimum_bills = INFINITY;
    for (int i = 0; i < bills.size(); i++) {
      if (n == bills[i]) {
        Memo[n] = 1;
        return Memo[n];
      }
      if (n > bills[i])
        minimum_bills = min(minimum_bills, MinBillsMemoized(n - bills[i], bills, Memo)+1);
    }
    Memo[n] = minimum_bills;
  }
  return Memo[n];
}

int MinBillsDP(int n, vector<int> &bills, vector<int> &Memo) {
  int minimum_bills = INFINITY;
  for (int i = 0; i < bills.size(); i++) {
    if (n == bills[i]) {
      Memo[n] = 1;
      return Memo[n];
    }
    if (n > bills[i])
      minimum_bills = min(minimum_bills, MinBillsMemoized(n - bills[i], bills, Memo)+1);
  }
  Memo[n] = minimum_bills;

  return Memo[n];
}