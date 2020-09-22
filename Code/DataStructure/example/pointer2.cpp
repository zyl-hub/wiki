#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    char input[8];
    char pwd[8] = "secret";

    while (1) {
        cout << "Enter your password:";
        cin >> input;

        cout << &pwd << endl;
        cout << &input << endl;
        if (strcmp(pwd, input) == 0) {
            cout << "Welcome!" << endl;
            break;
        } else {
            cout << "Try again!" << endl;
        }
    }
    return 0;
}
