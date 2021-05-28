#include<bits/stdc++.h>


using namespace std;

vector<int> get_path_brute(int x, int y, vector<vector<int>> Grid);
void print(vector<int> path);
// long get_path_memoized(long n, vector<long> &Memo);
// long get_path_DP(long n);

#define OFF_LIMIT -1


vector<int> main() {
    int m = 10;
    int n = 20;
    vector<vector<int>> Grid(m, vector<int>(n, -1));
    // vector<long> Memo(n + 1, INVALID);
    // cout << "#ways with DP: " << get_path_DP(n) << endl;
    // cout << "#ways with Memoization: " << get_path_memoized(n, Memo) << endl;
    cout << "#ways with Brute Force: ";
    print(get_path_brute(0, 0, Grid));
    return 0;
}

vector<int> get_path_brute(int x, int y, vector<vector<int>> Grid) {
    if(Grid[x][y] == OFF_LIMIT)
        return ;
    
}

void print(vector<int> path) {
    for (int i = 0;i < path.size(); i++)
        cout << path[i] << " ";
    cout << "\n"
}


// long get_path_memoized(long n, vector<long> &Memo) {
//     if(Memo[n] == INVALID) {
//         long ways = 0;
//         if(n < 1)
//             ways += 1;
//         if(n >= 1)
//             ways += get_path_memoized(n - 1, Memo);
//         if(n >= 2)
//             ways += get_path_memoized(n - 2, Memo);
//         if(n >= 3)
//             ways += get_path_memoized(n - 3, Memo);
//         Memo[n] = ways;
//     }
//     return Memo[n];
// }


// long get_path_DP(long n) {
//     vector<long> Cache(n + 1, 0);
//     Cache[0] = 1;
//     for (int i = 1; i < Cache.size(); i++) {
//         Cache[i] += Cache[i - 1];
//         if(i >= 2)
//             Cache[i] += Cache[i - 2];
//         if(i >= 3)
//             Cache[i] += Cache[i - 3];
//     }
//     return Cache[n];
// }
