#include <iostream>
using namespace std;
//notice here should be 1.0/12
const double Parameter = 1.0/12;

void trans(int);

int main()
{
    int height = 0;
    cout << "Your height:";
    cin >> height;
    trans(height);

    return 0;
}

void trans(int n)
{
    cout << "Height is " << n*Parameter << " inches";
}
