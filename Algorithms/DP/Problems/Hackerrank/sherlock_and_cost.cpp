# include<bits/stdc++.h>

using namespace std;

int MaxArrayCost(vector<int>B, int b_ptr, int &a);

int main() {
  int b_size;
  cin >> b_size;
  vector<int>B(b_size, 0);
  for (int i = 0; i < b_size; i++) {
    cin >> B[i];
  }
  int a = B[0];
  cout << "The Max Array Cost for the corresponding A array: " << MaxArrayCost(B, 0, a) << endl;
}

int MaxArrayCost(vector<int>B, int b_ptr, int &a) {
  int max = 0;
  if (b_ptr == B.size() - 2) {
    for (int i = B[b_ptr + 1]; i >= 1; i--) {
      for (int j = B[b_ptr]; j >= 1; j--) {
        if (abs(i-j) > max) {
          max = abs(i-j);
          a = j;
        }
      }
    }
    return max;
  }
  int a_perm = a;
  int b_first = B[b_ptr];
  int b_temp = B[b_ptr];
  int val = MaxArrayCost(B, b_ptr + 1, a);
  while (b_temp >= 1) {
    // a = a_perm; 
    int wannabe_max = abs(a - b_temp); 
    if (wannabe_max > max) {
      max = wannabe_max;
      b_first = b_temp;
    }
    b_temp--;
  }
  a = b_first;
  return max + val;
}

// int MaxArrayCost(vector<int>B, int b_ptr, int &a) {
//   int max = 0;
//   // if (b_ptr == B.size() - 2) {
//   //   for (int i = B[b_ptr + 1]; i >= 1; i--) {
//   //     for (int j = B[b_ptr]; j >= 1; j--) {
//   //       if (abs(i-j) > max) {
//   //         max = abs(i-j);
//   //         a = j;
//   //       }
//   //     }
//   //   }
//   //   return max;
//   // }
//   int a_perm = a;
//   int b_first = B[b_ptr];
//   int b_temp = B[b_ptr];
  
//   int val = MaxArrayCost(B, b_ptr + 1, a);
//   while (b_temp >= 1) {
//     int wannabe_max = abs(a - b_temp); 
//     if (wannabe_max > max) {
//       max = wannabe_max;
//       b_first = b_temp;
//     }
//     b_temp--;
//   }
//   a = b_first;
//   return max + val;
// }