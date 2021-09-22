#ifndef _range_hpp
#define _range_hpp

#include <iostream>

class Range {
protected:
  int Val;
  int Max, Min;
  std::string Name;
public:
  Range(int min, int max);
  Range(int nim, int max, std::string name);
  void incVal(void);
  void incVal(int step);
  void repr(std::ostream &s);
  void repr(void);
  void setVal(int val);
  void operator+=(int x) { Val += x; if (Val >= Max) Val = Max -1;};
  void operator+=(Range x) { Val += x.Val; if (Val >= Max) Val = Max -1;};
};

#endif
