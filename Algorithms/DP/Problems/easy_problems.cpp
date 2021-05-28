#include<bits/stdc++.h>

using namespace std;

unsigned get_sum(unsigned num);
unsigned Factorial(unsigned num);
unsigned FactorialIterative(unsigned num);
unsigned power(unsigned num, unsigned exp);
void PrintTableRecursive(unsigned num, int times);

void get_modified(int * array, int current_index, int last_index);

int main() {
  unsigned num, exp;
  int array_size;
  cin >> num;
  cout << "Summation(1 to num) = " << get_sum(num) << endl;
  cout << "Factorial(num) = " << Factorial(num) << endl;
  cout << "FactorialIterative(num) = " << FactorialIterative(num) << endl;
  cout << "Enter exponent: ";
  cin >> exp;
  cout << "Power(num^exp) = " << power(num, exp) << endl;
  cout << "Table of " << num << ": \n";
  PrintTableRecursive(num, 1);

  cout << "\nArray Size: ";
  cin >> array_size;
  int array[array_size];
  cout << "Array: ";
  for (int i = 0; i < array_size; i++) {
    cin >> array[i];
  }
  get_modified(array, 0, array_size - 1);
  cout << "Modified Array: " << endl;
  for (int i = 0; i < array_size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}

unsigned get_sum(unsigned num) {
  if (num < 2) 
    return num;
  return(num + get_sum(num - 1));
}

unsigned Factorial(unsigned num) {
  if (num < 2) 
    return num;
  return(num * Factorial(num - 1));
}

unsigned FactorialIterative(unsigned num) {
  unsigned result = 1;
  for (unsigned i = 1; i <= num; i++) {
    result = result * i;
  }
  return result;
}

unsigned power(unsigned num, unsigned exp) {
  if (exp == 0)
    return 1;
  return (num * power(num, exp - 1));
}

void PrintTableRecursive(unsigned num, int times) {
  if (times <= 10) {
    cout << num << " X " << times << " = " << num * times << endl;
    PrintTableRecursive(num, times + 1);
  }
}



void get_modified(int * array, int current_index, int last_index) {
  if (current_index != 0)
    array[current_index] = array[current_index] + array[current_index - 1]; 
  if (current_index != last_index)
    get_modified(array, current_index + 1, last_index);
}