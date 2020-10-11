#include <iostream>
using namespace std;

void aPlusB(int a, int b);

int main()
{
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;
    aPlusB(a, b);
    return 0;
}

void aPlusB(int a, int b)
{
    cout << a + b;
}
