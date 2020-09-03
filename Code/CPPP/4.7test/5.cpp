#include <iostream>
using namespace std;

struct CandyBar {
  char name[20];
  double weight;
  int Calorie;
};

void printCandy(CandyBar);
int main() {

  // CandyBar snack{"Mocha Munch", 2.3, 500};
  // cout << snack.name << endl << snack.weight << endl << snack.Calorie;

  CandyBar batch[3];
  batch[0] = {"Mocha Munch", 2.3, 500};
  batch[1] = {"Mocha Munch", 2.3, 500};
  batch[2] = {"Mocha Munch", 2.3, 500};
  CandyBar *batchNew = new CandyBar[3];
  delete[] batchNew;
  for (int i = 0; i < 2; i++) {
    printCandy(batch[i]);
  }

  return 0;
}
void printCandy(CandyBar n) {
  cout << n.name << endl << n.weight << endl << n.Calorie;
}
