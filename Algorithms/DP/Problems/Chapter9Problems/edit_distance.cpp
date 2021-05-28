#include<bits/stdc++.h>

using namespace std;

int EditDistanceBrute(string str1, string str2, int ptr1, int ptr2);
int EditDistanceDP(string str1, string str2, int ptr1, int ptr2);
int EditDistanceMemoized(string str1, string str2, int ptr1, int ptr2, vector<vector<int>> Memo);

int main() {
  string str1, str2;
  cout << "Enter the first string: ";
  getline(cin, str1);
  cout << "Enter the second string: ";
  getline(cin, str2);
  cout << "Edit Distance(Brute): " << EditDistanceBrute(str1, str2, 0, 0) << endl;
  cout << "Edit Distance(DP): " << EditDistanceDP(str1, str2, 0, 0) << endl;
  vector<vector<int>> Memo(str1.length() + 1, vector<int>(str2.length() + 1, -1));
  cout << "Edit Distance(Memoized): " << EditDistanceMemoized(str1, str2, 0, 0, Memo) << endl;
  return 0;
}

int EditDistanceBrute(string str1, string str2, int ptr1, int ptr2) {
  if (ptr1 == str1.length()) 
    return (str2.length() - ptr2);    
  if (ptr2 == str2.length()) 
    return (str1.length() - ptr1);   
  if (str1[ptr1] == str2[ptr2])
    return EditDistanceBrute(str1, str2, ptr1 + 1, ptr2 + 1);
  int insert_cost = EditDistanceBrute(str1, str2, ptr1, ptr2 + 1);// insert 
  int remove_cost = EditDistanceBrute(str1, str2, ptr1 + 1, ptr2); 
  int replace_cost = EditDistanceBrute(str1, str2, ptr1 + 1, ptr2 + 1);
  return min(min(insert_cost, remove_cost), replace_cost) + 1; 
}


int EditDistanceDP(string str1, string str2, int ptr1, int ptr2) {
  vector<vector<int>> Cache(str1.length() + 1, vector<int>(str2.length() + 1, -1));
  for (int i = 0; i < Cache.size(); i++) {
    for (int j = 0; j < Cache[0].size(); j++) {
      if (i == Cache.size() - 1)
        Cache[i][j] = str2.length() - j ;
      else if (j == Cache[0].size() - 1)
        Cache[i][j] = str1.length() - i;  
    }
  }
  for (int i = Cache.size() - 2; i >= 0; i--) {
    for (int j = Cache[0].size() - 2; j >= 0; j--) {
      if (str1[i] == str2[j])
        Cache[i][j] = Cache[i+1][j+1];
      else
        Cache[i][j] = min(min(Cache[i][j+1], Cache[i+1][j]), Cache[i+1][j+1]) + 1;
    }
  }
  return Cache[ptr1][ptr2];
}

int EditDistanceMemoized(string str1, string str2, int ptr1, int ptr2, vector<vector<int>> Memo) {
  if (Memo[ptr1][ptr2] == -1) {
    if (ptr1 == str1.length()) 
      Memo[ptr1][ptr2] = (str2.length() - ptr2);    
    else if (ptr2 == str2.length()) 
      Memo[ptr1][ptr2] = (str1.length() - ptr1);    
    else if (str1[ptr1] == str2[ptr2])
      Memo[ptr1][ptr2] = EditDistanceMemoized(str1, str2, ptr1 + 1, ptr2 + 1, Memo);
    else {
      int insert_cost = EditDistanceMemoized(str1, str2, ptr1, ptr2 + 1, Memo);
      int remove_cost = EditDistanceMemoized(str1, str2, ptr1 + 1, ptr2, Memo); 
      int replace_cost = EditDistanceMemoized(str1, str2, ptr1 + 1, ptr2 + 1, Memo);
      Memo[ptr1][ptr2] = min(min(insert_cost, remove_cost), replace_cost) + 1; 
    }
  }
  return Memo[ptr1][ptr2]; 
}