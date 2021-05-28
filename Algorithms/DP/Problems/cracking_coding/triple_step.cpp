#include<bits/stdc++.h>


using namespace std;

long get_number_of_ways(long n);
long get_num_ways_memoized(long n, vector<long> &Memo);
long get_num_ways_DP(long n);

#define INVALID -1


int main() {
    long n;
    cout << "Enter the number of steps: ";
    cin >> n;
    vector<long> Memo(n + 1, INVALID);
    cout << "#ways with DP: " << get_num_ways_DP(n) << endl;
    cout << "#ways with Memoization: " << get_num_ways_memoized(n, Memo) << endl;
    cout << "#ways with Brute Force: " << get_number_of_ways(n) << endl;
    return 0;
}

long get_number_of_ways(long n) {
    long ways = 0;          
    if (n < 1)
        ways += 1;  // Base Case, i.e. n = 0 will have 1 ways to reach to n = 0
    if(n >= 1)
        ways += get_number_of_ways(n - 1);
    if(n >= 2)
        ways += get_number_of_ways(n - 2);
    if(n >= 3)
        ways += get_number_of_ways(n - 3);
    return ways;
}


long get_num_ways_memoized(long n, vector<long> &Memo) {
    if(Memo[n] == INVALID) {
        long ways = 0;
        if(n < 1)
            ways += 1;
        if(n >= 1)
            ways += get_num_ways_memoized(n - 1, Memo);
        if(n >= 2)
            ways += get_num_ways_memoized(n - 2, Memo);
        if(n >= 3)
            ways += get_num_ways_memoized(n - 3, Memo);
        Memo[n] = ways;
    }
    return Memo[n];
}


long get_num_ways_DP(long n) {
    vector<long> Cache(n + 1, 0);
    Cache[0] = 1;
    for (int i = 1; i < Cache.size(); i++) {
        Cache[i] += Cache[i - 1];
        if(i >= 2)
            Cache[i] += Cache[i - 2];
        if(i >= 3)
            Cache[i] += Cache[i - 3];
    }
    return Cache[n];
}
