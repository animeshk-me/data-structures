# include<bits/stdc++.h>

using namespace std;


void BubbleSortIterative(int * arr, int array_size);
void BubbleSortRecursive(int * arr, int array_size);

int main() {
  int array_size, recursive;
  srand(time(0));
  array_size = rand() % 1000;
  // cin >> array_size;
  int arr[array_size];
  for (int i = 0; i < array_size; i++) {
    // cin >> arr[i];
    arr[i] = rand() % 1000;
  }
  cout << "1 for Recursive, 0 for iterative: ";
  cin >> recursive;
  switch (recursive) {
    case 0:
      cout << "Iterative implementation of Bubble Sort: ";
      BubbleSortIterative(arr, array_size);
      break;
  
    case 1:
      cout << "\nRecursive implementation of Bubble Sort: ";
      BubbleSortRecursive(arr, array_size);
      break;

    default:
      break;                  
  }

  for (int i = 0; i < array_size; i++) {
    cout << arr[i] << " ";
  }  
  cout << endl;
  return 0;
}

void BubbleSortIterative(int * arr, int array_size) {
  for (int inert_numbers = 0; inert_numbers < array_size; inert_numbers++) {
    for (int ptr = 0; ptr < array_size - inert_numbers - 1; ptr++) {
      if (arr[ptr] > arr[ptr + 1])
        swap(arr[ptr], arr[ptr + 1]);
    }
  }
}


/*
___________________________NOTES ON Bubble Sort___________________________
1. The Actual loop which does sorting is the inner loop, which traverses
  through the whole array, rearranging the consecutive elements, intensly 
  craving for max_element and at the end of this iteration the max_element
  is pushed at the end of the array.

2. After the Above process gets completed, and still some unsorted elements
  exist in the left part of the array, we do the same process again and this
  time, we don't consider the max_element we got from last iteration, thus
  this max_number acts as an "inert_number".

3. At the end of every iteration as Point(1), number of inert_numbers
  increase by 1, and we will keep reducing our traversal range of processes
  similar to Point(1), until we make all the elements 'inert'.

4. Therefore, the outer loop counts for the number_of_inert_numbers, i.e.
  the number of inner loops(Point(1) traversals) executed till now.

*/

// Lets take a recursive approach to the same problem.


void BubbleSortRecursive(int * array, int array_size) {
  if (array_size > 1) {
    for (int i = 0; i < array_size; i++) {
    if (array[i] > array[i + 1])
      swap(array[i], array[i + 1]);
    }
    BubbleSortRecursive(array, array_size - 1);
  }
}