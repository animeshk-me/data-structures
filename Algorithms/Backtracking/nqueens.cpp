#include<bits/stdc++.h>

using namespace std;

    
bool is_possible(int x, int y, vector<string> &matrix, int n) {
    int i, j;
    i = x;
    j = y;
    while(i >= 0 && j >= 0) {
        if(matrix[i][j] == 'Q')
            return false;
        i--;
        j--;
    }    
    i = x;
    j = y;
    while(i >= 0 && j < n) {
        if(matrix[i][j] == 'Q')
            return false;
        i--;
        j++;
    }
    for(i = x; i >= 0; i--) {
        if(matrix[i][y] == 'Q')
            return false;
    }
    return true;
}



void take_photo(vector<string> matrix, vector<vector<string>> &overall_solution) {
    overall_solution.push_back(matrix);
}

string get_str(int n) {
    string st = "";
    while(n--)
        st += ".";
    return st;
}

void func(int x, vector<string> &matrix, vector<vector<string>> &overall_solution, int n) {
    if(x == n) { 
        take_photo(matrix, overall_solution);
        return;
    }
    for(int j = 0; j < n; j++) {
        if(is_possible(x, j, matrix, n)) {
            matrix[x][j] = 'Q';
            func(x + 1, matrix, overall_solution, n);
            matrix[x][j] = '.'; // backtrack
        }
    }    
    return;
}

    
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> overall_solution;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> matrix(n);
    int n_curr = 0;
    for(int i = 0; i < n; i++) 
        matrix[i] = get_str(n);
    func(0, matrix, overall_solution, n);
    return overall_solution;
}
    

int main() {
    int n;
    cout << "Enter the N (for N X N board): ";
    cin >> n;
    vector<vector<string>> result_board_configs = solveNQueens(n);
    for(auto &result_board_config : result_board_configs) {
        cout << "[";
        for(auto &row : result_board_config) {
            cout << row << "], [";
        }
        cout << endl;
    } 
}