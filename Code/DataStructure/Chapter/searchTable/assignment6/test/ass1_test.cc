#include <cstdlib>
#include <iostream>
#include <string>
#define MAX_INT 32767
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace myclass {
template <typename T>
class hfTree {
 private:
  struct Node {
    T data;
    int weight;
    int parent, left, right;
  };
  Node* elem;
  int length;

 public:
  struct hfCode {
    T data;
    string code;
  };
  hfTree(const T* x, const int* w, int size);
  void getCode(hfCode result[]);
  ~hfTree() { delete[] elem; }
};

template <typename T>
hfTree<T>::hfTree(const T* v, const int* w, int size) {
  int min1, min2;
  int x, y;

  length = 2 * size;
  elem = new Node[length];
  for (size_t i = size; i < length; ++i) {
    elem[i].weight = w[i - size];
    elem[i].data = v[i - size];
    elem[i].parent = elem[i].left = elem[i].right = 0;
  }
  for (size_t i = size - 1; i > 0; --i) {
    min1 = min2 = MAX_INT;
    x = y = 0;
    for (size_t j = i + 1; j < length; ++j) {
      if (elem[j].parent == 0) {
        if (elem[j].weight < min1) {
          min2 = min1;
          min1 = elem[j].weight;
          x = y;
          y = j;
        } else if (elem[j].weight < min2) {
          min2 = elem[j].weight;
          x = j;
        }
      }
    }
    elem[i].weight = min1 + min2;
    elem[i].left = x;
    elem[i].right = y;
    elem[i].parent = 0;
    elem[x].parent = i;
    elem[y].parent = i;
  }
}
template <typename T>
void hfTree<T>::getCode(hfCode result[]) {
  int size = length / 2;
  int p, s;
  for (size_t i = size; i < length; ++i) {
    result[i - size].data = elem[i].data;
    result[i - size].code = "";
    p = elem[i].parent;
    s = i;
    while (p) {
      if (elem[p].left == s) {
        result[i - size].code = '0' + result[i - size].code;
      } else {
        result[i - size].code = '1' + result[i - size].code;
      }
      s = p;
      p = elem[p].parent;
    }
  }
}
}  // namespace myclass

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
    sum += w[i] * result[i].code.length();
  }
  cout << sum << endl;
  return 0;
}