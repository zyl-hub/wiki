#include <iostream>
using namespace std;

void displayTime(int, int);

int main()
{
    int hours = 0;
    int minutes = 0;
    cout << "Input hours: ";
    cin >> hours;
    cout << "Input minutes: ";
    cin >> minutes;

    displayTime(hours, minutes);
    return 0;
}

void displayTime(int hours, int minutes)
{
    cout << hours <<":"<< minutes;
}
