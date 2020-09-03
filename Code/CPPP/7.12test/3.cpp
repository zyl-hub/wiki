#include <iostream>
using namespace std;

void test3(int[], const int, int);
void test4(int *, int *, int);

int main() {
  const int ArSize = 10;
  int ar[10] = {0};
  int n = 1;
  test3(ar, ArSize, n);
  for (int i = 0; i < ArSize; i++)
    cout << ar[i];
  n = 2;
  test4(&ar[0], &ar[9], n);
  for (int i = 0; i < ArSize; i++)
    cout << ar[i];

  return 0;
}

void test3(int ar[], const int ArSize, int n) {
  for (int i = 0; i < ArSize; i++)
    ar[i] = n;
}

void test4(int *h, int *e, int n) {
  for (int i = 0; i <= (e - h); i++)
    *(h + i) = n;
}
