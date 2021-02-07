/**
 * @author Animesh Kumar
 * @email 24animesh11@gmail.com
 * @create date 07-02-2021
 * @modify date 07-02-2021
 * @desc Dynamic array implementation
 */

#include<bits/stdc++.h>

using namespace std;

#define EMPTY -1

// They Dynamic Array class
class Array {
 private:
  int * arr_; // the array
  int size_;  // #elements currently present in arr_[]
  int capacity_;   // full capacity_ of the arr_[]
  void DoubleArray();

 public:
  Array();
  Array(int * init_arr, int init_size);
  int get_value(int id);
  int get_size();
  int get_capacity();
  void Add(int data);
  void Remove();
  void RemoveAt(int id);
  void Print();
  void ShrinkCapacity();
};

int main() {
  Array A;
  A.Add(3);
  A.Add(1);
  A.Add(4);
  A.Add(1);
  A.Add(5);
  A.Print();
  A.Remove();
  A.Print();
  A.Add(9);
  A.Add(19);
  A.Print();
  A.RemoveAt(1);
  A.Print();
  A.Add(6);
  A.Print();
  A.RemoveAt(2);
  A.Print();

  int init_arr[] = {2, 7, 1, 8, 2, 8, 1, 8, 2, 8};
  Array B(init_arr, 10);
  B.Print();
  B.Remove();
  B.Print();
  B.Add(2718);
  B.Print();
  cout << "B[2]: " << B.get_value(2) << endl;
  return 0;
}

/************************** Function Definitions ***************************/

// basic constructor
Array::Array() {
  arr_ = new int[1];
  capacity_ = 1;
  size_ = 0;
  arr_[0] = EMPTY;
}

// constructor to create a dynamic array using a static array init_arr[]
Array::Array(int * init_arr, int init_size) {
  arr_ = init_arr;
  size_ = init_size;
  capacity_ = init_size;
}

// returns the value stored in cell at index ID
int Array::get_value(int id) {
  if(id >= size_) {
    cout << "[X]Index out of bound" << endl;
    return EMPTY;
  }
  return arr_[id];
}

// returns the size_ of the dynamic array
int Array::get_size() {
  return size_;
}

// returns the full capacity of the dynamic array right now
int Array::get_capacity() {
  return capacity_;
}

// appends the DATA at the end of the dynamic array
void Array::Add(int data) {
  if(capacity_ == size_) 
    DoubleArray();
  arr_[size_] = data;
  size_++;
}

// doubles the capacity of the dynamic array
void Array::DoubleArray() {
  int * new_arr = new int[capacity_ * 2];
  for (int i = 0; i < (capacity_ * 2); i++) {
    if (i < capacity_)
      new_arr[i] = arr_[i];
    else
      new_arr[i] = EMPTY;
  }
  delete[] arr_;
  arr_ = new_arr;
  capacity_ *= 2;
}

// removes the element at the end of the dynamic array
void Array::Remove() {
  if(size_ < 1) {
    cout << "[X]Nothing to delete" << endl;
    return;
  }
  arr_[size_ - 1] = EMPTY;
  size_--; 
}

// removes the element present at the index ID of the dynamic array
void Array::RemoveAt(int id) {
  if(id >= size_) {
    cout << "[X]Index out of bound" << endl;
    return;
  } 
  for (int i = id + 1; i < size_; i++)
    arr_[i - 1] = arr_[i];
  arr_[size_ - 1] = -1;
  size_--;
}

// reduces the capacity_ to match the size_
void Array::ShrinkCapacity() {
  int * new_arr = new int[size_];
  for (int i = 0; i < size_; i++)
    new_arr[i] = arr_[i];
  delete[] arr_;
  arr_ = new_arr;
  capacity_ = size_;
}

// prints the dynamic array contents
void Array::Print() {
  cout << "[ ";
  for (int i = 0; i < size_; i++)
    cout << arr_[i] << " ";
  cout << "], size: " << size_ << ", capacity: " << capacity_ << endl;
}

/***************************************************************************/