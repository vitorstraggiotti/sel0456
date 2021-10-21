#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

class Item {
public:
  std::string data;
  int key;
  Item(const char *_data, int _key): data { _data}, key(_key) {}
};

std::vector<Item> items = {
  {"john", 2},
  {"bill", 3},
  {"joe", 1},
  {"sara", 5},
  {"foo", 4}
};

void print_items(const std::vector<Item>items) {
  for (auto & e: items) {
    std::cout << "-->" << e.key << ": " << e.data << "\n";
  }
}

bool compareItem(Item& a, Item& b) {
  return (a.key < b.key);
}

int main(void) {
  std::cout << "--> Unordered:\n";
  print_items(items);
  std::sort(items.begin(), items.end(), compareItem);
  std::cout << "--> Sorted:\n";
  print_items(items);

  return 0;
}
