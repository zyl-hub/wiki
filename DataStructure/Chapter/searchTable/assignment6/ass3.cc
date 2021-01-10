// Copyright[2020] <yangbaoquan>
// All rights reserved
#include "include/close_hash_table.hpp"

int main(int argc, char** argv) {
  size_t p, m, n, key;
  cin >> p >> m >> n;
  closeHashTable table(p, m);
  for (size_t i = 0; i < n; i++) {
    cin >> key;
    table.insert(key);
  }
  table.print();
  system("pause");
  return 0;
}
