#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
  char pwd[8] = "secret", input[8];

  while (1) {
    cout << "Enter your password:";
    cin >> input;
    //for (int i = 0; i < 8; i++) {
      //cout << pwd[i];
    //}

    if (strcmp(pwd, input) == 0) {
      cout << "Welcome!" << endl;
      break;
    } else {
      cout << "Try again!" << endl;
    }
  }
  return 0;
}
