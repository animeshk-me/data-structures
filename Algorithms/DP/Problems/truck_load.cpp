#include<bits/stdc++.h>
using namespace std;

#define CAPACITY_EXCEEDED -1 // when capacity C is exceeded by an operation

int get_max_num_of_containers(vector<int> weights, int end, int C);
int get_max_num_of_containers_DP(vector<int> weights, int end, int C, vector<vector<int>> &Memo);


int main() {
    int k, C;
    cout << "Enter k and C values: ";
    cin >> k >> C;
    vector<int> weights(k, 0);
    cout << "Enter k weights: ";
    for (int i = 0; i < k; i++)
        cin >> weights[i];
    cout << "Maximum number of containers(Recursive Solution): " << get_max_num_of_containers(weights, k - 1, C) << endl;
    vector<vector<int>> Memo(k, vector<int>(C+1, -1));
    cout << "Maximum number of containers(DP Solution(Memoization)): " << get_max_num_of_containers_DP(weights, k - 1, C, Memo) << endl;
    return 0;
}

// returns the max #containers that will be taken if weights[end] element is taken/not_taken
int get_max_num_of_containers(vector<int> weights, int end, int C) {
    if(C < 0)
        return CAPACITY_EXCEEDED; 
    if (C == 0 || end < 0)
        return 0;
    if(end == 0) {
        if(C >= weights[end])
            return 1; // taken
        return 0; // not taken
    }
    int taken = get_max_num_of_containers(weights, end - 1, C - weights[end]);
    if(taken != CAPACITY_EXCEEDED)
        taken++;
    int not_taken = get_max_num_of_containers(weights, end - 1, C); 
    // cout << "idx = " << end << "; C = " << C << "; taken = " << taken << "; not taken = " << not_taken << endl;
    return max(taken, not_taken);
}

// memoized version of get_max_num_of_containers
int get_max_num_of_containers_DP(vector<int> weights, int end, int C, vector<vector<int>> &Memo) {
    if(C < 0)
        return CAPACITY_EXCEEDED; 
    if (C == 0 || end < 0)
        return 0;
    if(Memo[end][C] == -1) {
        if(end == 0) {
            if(C >= weights[end])
                Memo[end][C] = 1; // taken
            else
                Memo[end][C] = 0; // not taken
        }
        int taken = get_max_num_of_containers_DP(weights, end - 1, C - weights[end], Memo);
        if(taken != CAPACITY_EXCEEDED)
            taken++;
        int not_taken = get_max_num_of_containers_DP(weights, end - 1, C, Memo); 
        // cout << "idx = " << end << "; C = " << C << "; taken = " << taken << "; not taken = " << not_taken << endl;
        Memo[end][C] = max(taken, not_taken);
    }
    return Memo[end][C];
}


/***************** Sample Inputs ***************

1.  Enter k and C values: 5 10
    Enter k weights: 4 5 2 1 7         ====>output = 3

2.  Enter k and C values: 8 25
    Enter k weights: 3 9 6 13 7 1 4 5      ====>output = 5

*/