#include<bits/stdc++.h>


using namespace std;

vector<int> scatter_palindromes(vector<string> &strings);
bool is_scatter(string &st, int i, int j);
int get_num_scatter_palindromes(string st);

int main() {
	vector<string> strings;
	int n;
	string str;
	cin >> n;
	while(n--) {
		cin >> str;
		strings.push_back(str);
	}
	vector<int> res = scatter_palindromes(strings);
	for(int n : res) cout << n << " ";
	cout << endl;
	return 0;
}


vector<int> scatter_palindromes(vector<string> &strings) {
	vector<int> return_arr;
	for (string st : strings)
		return_arr.push_back(get_num_scatter_palindromes(st));
	return return_arr;
}


int get_num_scatter_palindromes(string st) {
	int num = 0;
	for(int i = 0; i < st.size(); i++) {
		for(int j = i; j < st.size(); j++)
			num = is_scatter(st, i, j) ? num + 1 : num;
	}
	return num;
}

bool is_scatter(string &st, int i, int j) {
	map<char, int> hashmap;
	for(int k = i; k <= j; k++) {
		if(hashmap.count(st[k]) == 0)
			hashmap.insert({st[k], 0});
		hashmap[st[k]]++;
	}
	bool odd_seen = false;
	for(auto it : hashmap) {
		if(it.second % 2 != 0) {
			if(odd_seen)
				return false;
			odd_seen = true;
		}
	}
	for(int k = i; k <= j; k++) cout << st[k];
	cout << endl;
	return true;
}