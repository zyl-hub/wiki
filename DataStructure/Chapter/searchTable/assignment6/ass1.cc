#include "include/hfTree.hpp"

int main(int argc, char** argv) {
  size_t n = 0;
  cin >> n;
  int* w = new int[n];
  int* arr = new int[n];
  for (size_t i = 0; i < n; i++) {
    cin >> w[i];
    arr[i] = i + 1;
  }
  myclass::hfTree<int> tree(arr, w, n);
  myclass::hfTree<int>::hfCode* result;
  result = new myclass::hfTree<int>::hfCode[n];

  tree.getCode(result);
  int sum = 0;
  for (size_t i = 0; i < n; ++i) {
    cout << w[i] << ' ' << result[i].code << endl;
    sum += w[i] * result[i].code.length();
  }
  cout << sum << endl;
  system("pause");
  return 0;
}