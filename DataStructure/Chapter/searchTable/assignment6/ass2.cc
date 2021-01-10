// Copyright[2020] <yangbaoquan>
// All rights reserved
#include "include/bsTree.hpp"

int main(int argc, char** argv) {
  BSTree tree;
  size_t n, key;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> key;
    tree.insert(key);
  }
  system("pause");
  return 0;
}
