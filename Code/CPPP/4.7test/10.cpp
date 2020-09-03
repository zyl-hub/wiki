#include <array>
#include <iostream>
using namespace std;

int main() {
  array<double, 3> Final;
  cout << "First:";
  cin >> Final[0];
  cout << "Second:";
  cin >> Final[1];
  cout << "Third:";
  cin >> Final[2];
  cout << 3 << " Times" << endl << (Final[0] + Final[1] + Final[2]) / 3;

  return 0;
}
