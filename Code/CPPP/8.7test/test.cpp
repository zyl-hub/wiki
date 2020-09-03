#include <iostream>
using namespace std;

template <typename T> void Swap(T &a, T &b);

int main() {
  int i = 10;
  int j = 20;
  Swap(i, j);
  cout << i << '\t' << j;
  cout << endl;

  double x = 24.5;
  double y = 81.7;
  Swap(x, y);
  cout << x << '\t' << y;

  return 0;
}

template <typename T> void Swap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}
