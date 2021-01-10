#include <iostream>
using namespace std;

void trans(double);

int main()
{
    double a = 0.0;

    cin >> a;
    trans(a);

    return 0;
}

void trans(double n)
{
    cout << n << " long equals " << n*220 << " 码 ";
}
