#include <iostream>
using namespace std;

void trans(int);

int main()
{
    int age = 0;
    
    cout << "Your age: ";
    cin >> age;
    trans(age);

    return 0;
}

void trans(int n)
{
    cout << "equals to " << n*12 << " month" << endl;
}

