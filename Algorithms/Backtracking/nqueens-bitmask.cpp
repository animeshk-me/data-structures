#include<bits/stdc++.h>

using namespace std;

    


void take_photo(vector<string> matrix, vector<vector<string>> &overall_solution) {
    overall_solution.push_back(matrix);
}

string get_str(int n) {
    string st = "";
    while(n--)
        st += ".";
    return st;
}

void func(int x, vector<string> &matrix, vector<vector<string>> &overall_solution, int n, vector<bool> &diagonal_main, vector<bool> &diagonal_other, vector<bool> &column) {
    if(x == n) { 
        take_photo(matrix, overall_solution);
        return;
    }
    for(int j = 0; j < n; j++) {
        if(!(column[j] || diagonal_main[x-j+n-1] || diagonal_other[x+j])) {
            matrix[x][j] = 'Q';
            column[j] = true;
            diagonal_main[x-j+n-1] = true;
            diagonal_other[x+j] = true;
            func(x + 1, matrix, overall_solution, n, diagonal_main, diagonal_other, column);
            matrix[x][j] = '.';
            column[j] = false;
            diagonal_main[x-j+n-1] = false;
            diagonal_other[x+j] = false;
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
    vector<bool> diagonal_main(2*n - 1, false);
    vector<bool> diagonal_other(2*n - 1, false);
    vector<bool> column(n, false);
    func(0, matrix, overall_solution, n, diagonal_main, diagonal_other, column);
    return overall_solution;
}
    

int main() {
    int n;
    cout << "Enter the N (for N X N board): ";
    cin >> n;
    vector<bool> diagonal_main(2*n - 1, false);
    vector<bool> diagonal_other(2*n - 1, false);
    vector<bool> column(n, false);
    vector<vector<string>> result_board_configs = solveNQueens(n);
    for(auto &result_board_config : result_board_configs) {
        cout << "[";
        for(auto &row : result_board_config) {
            cout << row << "], [";
        }
        cout << endl;
    } 
}