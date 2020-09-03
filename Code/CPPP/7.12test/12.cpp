#include <iostream>
using namespace std;

struct applicant {
  char name[30];
  int creditRatings[3] = {1, 2, 3};
};

void showInfo(applicant);
void showInfo(applicant *);
void f1(applicant *a);
const char *f2(const applicant *a1, const applicant *a2);
void (*p1)(applicant *) = f1;
const char *(*p2)(const applicant *a1, const applicant *a2) = *f2;

int main() {
  applicant testShowInfo;
  cin >> testShowInfo.name;
  showInfo(testShowInfo);
  cout << endl;
  showInfo(&testShowInfo);
  return 0;
}

void showInfo(applicant n) {
  cout << n.name;
  cout << '\t';
  for (int i = 0; i < 3; i++) {
    cout << n.creditRatings[i] << '\t';
  }
}

void showInfo(applicant *n) {
  cout << n->name;
  cout << '\t';
  for (int i = 0; i < 3; i++) {
    cout << n->creditRatings[i] << '\t';
  }
}
