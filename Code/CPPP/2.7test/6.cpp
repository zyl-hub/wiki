#include <iostream>
using namespace std;

void trans(double);

int main()
{
    double lightYear = 0.0;
    cin >> lightYear;
    trans(lightYear);

    return 0;
}

void trans(double n)
{
    cout << n <<" lightYears equals to "<<n*63240 << " astronomical units" << endl;
}
