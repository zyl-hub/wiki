#include <iostream>
using namespace std;

void trans(double);

int main()
{
    double celTemperature = 0.0;
    cout << "cel Temperature";
    cin >> celTemperature;
    trans(celTemperature);

    return 0;
}

void trans(double n)
{
    cout << n << " cel equals to " << n*1.8 + 20 << " fah" << endl;
}
