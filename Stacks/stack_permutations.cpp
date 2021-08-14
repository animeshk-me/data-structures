//Stack Permutations (Check if an array is stack permutation of other)

#include<bits/stdc++.h>

using namespace std;

bool is_stack_permutation(vector<int> input, vector<int> output);
void debug(int var, string varname);



int main() {
    int size;
    cin >> size;
    vector<int> input(size);
    vector<int> output(size);
    for(int i = 0; i < size; i++)
        cin >> input[i];
    while(1) {
        for(int i = 0; i < size; i++)
            cin >> output[i];
        cout << is_stack_permutation(input, output) << endl;
    }
    return 0;
}

bool is_stack_permutation(vector<int> input, vector<int> output) {
    int output_id = 0;
    int input_id = 0;
    stack<int> temp_stack;

    while(output_id < output.size()) {
        if((!temp_stack.empty()) && (output[output_id] == temp_stack.top())) 
            temp_stack.pop();
        else {
            while(input[input_id] != output[output_id]) {
                temp_stack.push(input[input_id++]);
                if(input_id >= input.size())
                    return false;
            }
            input_id++;
        }
        output_id++;
    }
    return true;
}


void debug(int var, string varname) {
    cout << varname << ": " << var << endl;
}