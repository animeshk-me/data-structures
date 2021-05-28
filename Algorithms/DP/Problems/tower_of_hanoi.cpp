# include<bits/stdc++.h>

using namespace std;

class Peg {
 public:
  vector<int> vec;
  char name;
  Peg(char ch) : name(ch) {}
};

void shift_hanoi(int head, int tail, Peg &Source, Peg &Extra, Peg &Destination);
void shift_top(Peg &Source, Peg &Destination);

int num_of_moves = 0;

int main() {
  int height, head, tail;
  cout << "Enter the height of hanoi: ";
  cin >> height;
  Peg Source('S'), Extra('E'), Destination('D');
  for (int i = height; i > 0; i--) {
    Source.vec.push_back(i);
  }

  head = Source.vec.size() - 1;
  tail = 0;
  shift_hanoi(head, tail, Source, Extra, Destination);
  cout << "Total No. of Moves = "  << num_of_moves << endl;
  return 0;
}

void shift_top(Peg &Source, Peg &Destination) {
  num_of_moves++;
  cout << "Move-#" << num_of_moves << "-  Disc #" << Source.vec.back() << " moved from " << Source.name << " to " << Destination.name << endl;
  Destination.vec.push_back(Source.vec.back());
  Source.vec.pop_back();
}

void shift_hanoi(int head, int tail, Peg &Source, Peg &Extra, Peg &Destination) {
  if (head == tail) {                       // Base Case #1
    shift_top(Source, Destination);
    return;
  }
  if (head - tail == 1) {                   // Base Case #2
    shift_top(Source, Extra);
    shift_top(Source, Destination);
    shift_top(Extra, Destination);
    return;
  }
  shift_hanoi(head, tail + 1, Source, Destination, Extra);
  shift_top(Source, Destination);
  int extra_head = Extra.vec.size() - 1;
  int extra_tail = extra_head - head + tail + 1;
  shift_hanoi(extra_head, extra_tail, Extra, Source, Destination);
}
