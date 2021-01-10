#include <iostream>
using namespace std;

double test5(double[], const int);
int main() {
  const int ArSize = 10;
  double ar[ArSize] = {0};
  for (int i = 0; i < ArSize; i++) {
    ar[i] = i * i - 2 * i;
  }
  double out = test5(ar, ArSize);
  for (int i = 0; i < ArSize; i++)
    cout << ar[i] << '\t';
  cout << endl;
  cout << out;

  return 0;
}

double test5(double ar[], const int ArSize) {
  double temp = 0;
  for (int i = 0; i < ArSize; i++) {
    if (ar[i] > temp)
      temp = ar[i];
  }
  return temp;
}
