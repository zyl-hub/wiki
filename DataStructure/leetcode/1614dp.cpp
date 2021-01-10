#include <iostream>
using namespace std;
const int DISCOUNT = 1000000007;

int numWays(int n);

int main()
{
  cout << numWays(92);

  return 0;
}

int numWays(int n)
{
  if (n <= 1)
    return 1;
  if (n == 2)
    return 2;
  int prevp = 1;
  int prev = 2;
  int sum = 0;
  for (int i = 3; i <= n; i++) {
    sum = (prevp + prev) % DISCOUNT;
    prevp = prev;
    prev = sum;
  }
  return sum;
}
