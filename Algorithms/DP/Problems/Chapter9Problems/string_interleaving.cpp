#include<bits/stdc++.h>

using namespace std;

bool IsInterleaved(string s1, string s2, string str, int s1_i, int s2_i, int str_i);
bool IsInterleavedMemoized(string s1, string s2, string str, int s1_i, int s2_i, int str_i, vector<vector<vector<int>>>&Memo);

int main() {
  string s1, s2, str;
  cout << "Enter the string 1: ";
  getline(cin, s1);
  cout << "Enter the string 2: ";
  getline(cin, s2);
  while(1) {
    cout << "Enter the string to check interleaving: ";
    getline(cin, str);
    cout << "The fact that entered string is interleaving of first two is " << IsInterleaved(s1, s2, str, 0, 0, 0) << endl;

    vector<vector<vector<int>>> Memo(s1.size() + 1, vector<vector<int>>(s2.size() + 1,vector<int>(str.size() + 1, -1)));
    cout << "The fact that entered string is interleaving of first two is " << IsInterleavedMemoized(s1, s2, str, 0, 0, 0, Memo) << endl;

  }
  return 0;
}

bool IsInterleaved(string s1, string s2, string str, int s1_i, int s2_i, int str_i) {
  if ((s1_i < s1.size()) && (str_i < str.size())) { // 0-x-0
    if (s2_i == s2.size()) {                // 0-1-0
      if (str[str_i] == s1[s1_i])
        return IsInterleaved(s1, s2, str, s1_i+1, s2_i, str_i+1);
      return false;
    } else {                                // 0-0-0
      bool first = false;
      bool second = false;
      if (str[str_i] == s1[s1_i])
        first = IsInterleaved(s1, s2, str, s1_i+1, s2_i, str_i+1);
      if (str[str_i] == s2[s2_i])
        second = IsInterleaved(s1, s2, str, s1_i, s2_i+1, str_i+1);
      return (first || second);
    }                         
  }
  if (s1.size() == s1_i) {                  // 1-x-x
    if ((s2_i == s2.size()) && (str_i == str.size()))  // 1-1-1
      return true;
    if ((s2_i < s2.size()) && (str_i < str.size())) { // 1-0-0
      if (str[str_i] == s2[s2_i]) 
        return IsInterleaved(s1, s2, str, s1_i, s2_i+1, str_i+1);
    }
  }
  return false;
}


bool IsInterleavedMemoized(string s1, string s2, string str, int s1_i, int s2_i, int str_i, vector<vector<vector<int>>> &Memo) {
  if (Memo[s1_i][s2_i][str_i] == -1) {
    if ((s1_i < s1.size()) && (str_i < str.size())) { // 0-x-0
      if (s2_i == s2.size()) {                // 0-1-0
        if (str[str_i] == s1[s1_i])
          Memo[s1_i][s2_i][str_i] = IsInterleavedMemoized(s1, s2, str, s1_i+1, s2_i, str_i+1, Memo);
        else
          Memo[s1_i][s2_i][str_i] = 0;
      } else {                                // 0-0-0
        bool first = 0;
        bool second = 0;
        if (str[str_i] == s1[s1_i])
          first = IsInterleavedMemoized(s1, s2, str, s1_i+1, s2_i, str_i+1, Memo);
        if (str[str_i] == s2[s2_i])
          second = IsInterleavedMemoized(s1, s2, str, s1_i, s2_i+1, str_i+1, Memo);
        Memo[s1_i][s2_i][str_i] = (first || second);
      }                         
    }
    else if (s1.size() == s1_i) {                  // 1-x-x
      if ((s2_i == s2.size()) && (str_i == str.size()))  // 1-1-1
        Memo[s1_i][s2_i][str_i] = 1;
      else if ((s2_i < s2.size()) && (str_i < str.size())) { // 1-0-0
        if (str[str_i] == s2[s2_i]) 
          Memo[s1_i][s2_i][str_i] = IsInterleavedMemoized(s1, s2, str, s1_i, s2_i+1, str_i+1, Memo);
      }
      else
        Memo[s1_i][s2_i][str_i] = 0;
    }
    else
      Memo[s1_i][s2_i][str_i] = 0;
  }                                                                                                   
  return Memo[s1_i][s2_i][str_i];
}