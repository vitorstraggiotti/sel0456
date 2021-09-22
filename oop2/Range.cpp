#include <iostream>

using namespace std;

#include "Range.hpp"

Range::Range(int min, int max) {
  Val = Min = min;
  Max = max;
  Name = string {"Default"};
}

Range::Range(int min, int max, string name) {
  Val = Min = min;
  Max = max;
  Name = name;
}

void Range::incVal(void) {
  Val += 1;
  if (Val >= Max) {
    Val = Max - 1;
  }
}

void Range::incVal(int step) {
  Val += step;
  if (Val >= Max) {
    Val = Max - 1;
  }
}

void Range::repr(ostream &s) {
  s << "Range object: " << Name << " [" << Min << ", " << Max << "[ = " << Val << endl;
}

void Range::repr(void) {
  cout << "Range object: " << Name << " [" << Min << ", " << Max << "[ = " << Val << endl;
}

void Range::setVal(int val) {
  Val = val;
  if (Val < Min)
    Val = Min;
  if (Val >= Max)
    Val = Max - 1;
}

