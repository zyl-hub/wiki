#include <iostream>
using namespace std;

long long int find(int n, int k, long long int* Ar);

int main()
{
  int n = 0;
  int k = 0;
  long long int kMax = 0;

  cout << "Input n, k: ";
  cin >> n >> k;
  long long int* Ar = new long long int[n];
  cout << "Input Array: ";
  for (int i = 0; i < n; i++) {
    cin >> Ar[i];
  }

  kMax = find(n, k, Ar);
  cout << kMax;
  return 0;
}

long long int find(int n, int k, long long int* Ar)
{
  for (int i = 0; i < k; i++) {
    for (int tempLen = n; tempLen > 1; tempLen--) {
      if (Ar[tempLen - 1] > Ar[tempLen - 2]) {
        long long int temp;
        temp = Ar[tempLen - 2];
        Ar[tempLen - 2] = Ar[tempLen - 1];
        Ar[tempLen - 1] = temp;
      }
    }
  }
  return Ar[k - 1];
}
