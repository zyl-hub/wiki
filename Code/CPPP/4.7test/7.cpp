#include <iostream>
using namespace std;

struct Pizza {
  char company[20];
  double size;
  double weight;
};

//注意值传递和引用传递
void PizzaInfo(Pizza &);
void PizzaInfo(Pizza *);
void PizzaShowInfo(Pizza);
void PizzaShowInfo(Pizza *);

int main() {
  Pizza testPizza;
  PizzaInfo(testPizza);
  PizzaShowInfo(testPizza);
  Pizza *big = new Pizza;
  PizzaInfo(big);
  PizzaShowInfo(big);
  delete big;

  return 0;
}

void PizzaInfo(Pizza &n) {
  cout << "company:";
  cin >> n.company;
  cout << "size:";
  cin >> n.size;
  cout << "weight:";
  cin >> n.weight;
}

void PizzaInfo(Pizza *n) {
  cout << "size:";
  cin >> n->size;
  cout << "company:";
  cin >> n->company;
  cout << "weight:";
  cin >> n->weight;
}

void PizzaShowInfo(Pizza n) {
  cout << "company:";
  cout << n.company << endl;
  cout << "size:";
  cout << n.size << endl;
  cout << "weight:";
  cout << n.weight << endl;
}

void PizzaShowInfo(Pizza *n) {
  cout << "company:";
  cout << n->company << endl;
  cout << "size:";
  cout << n->size << endl;
  cout << "weight:";
  cout << n->weight << endl;
}
