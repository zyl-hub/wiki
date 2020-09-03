#include <cstring>
#include <iostream>
#include <stdexcept>
using namespace std;

int replace(char *, char, char);

int main() {
  char str[] = "ranger";
  char c1 = 'r';
  char c2 = 'l';
  int count = replace(str, c1, c2);
  cout << count << endl;
  cout << str;

  return 0;
}

int replace(char *str, char c1, char c2) {
  int count = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == c1) {
      str[i] = c2;
      count++;
    }
  }
  return count;
}
