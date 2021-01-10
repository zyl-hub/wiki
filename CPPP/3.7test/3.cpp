#include <iostream>
using namespace std;

const double transformParameter = 1.0 / 60;

void trans(int, int, int);

int main() {
  int degree = 0;
  int minArc = 0;
  int secArc = 0;
  cin >> degree >> minArc >> secArc;
  trans(degree, minArc, minArc);

  return 0;
}

void trans(int degree, int minArc, int secArc) {
  cout << degree + minArc * transformParameter +
              secArc * transformParameter * transformParameter;
}
