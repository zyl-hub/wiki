#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class HashTable {
 private:
  int *_HashTable;
  size_t *_num;
  size_t _p;
  size_t _size;

 public:
  HashTable(size_t p, size_t m) : _p(p), _size(m) {
    _HashTable = new int[m];
    _num = new size_t[m];
    for (size_t i = 0; i < m; i++) {
      _HashTable[i] = -1;
      _num[i] = 0;
    }
  }
  ~HashTable() { delete[] _HashTable; }
  void insert(size_t num);
  void print() const;
};

void HashTable::insert(size_t num) {
  size_t tmp = num % _p;
  size_t sum = 0;
  bool flag;
  for (size_t i = 0; i < _size; i++) {
    flag = false;
    if (tmp == i && _HashTable[i] == -1) {
      _HashTable[i] = num;
      sum++;
      _num[i] = sum;
      break;
    } else if (tmp == i && _HashTable[i] != -1) {
      sum++;
      for (size_t j = i + 1; j < _size; j++) {
        sum++;
        if (_HashTable[j] == -1) {
          _HashTable[j] = num;
          flag = true;
          _num[j] = sum;
          break;
        }
      }
      if (!flag) {
        for (size_t j = 0; j < i; j++) {
          sum++;
          if (_HashTable[j] == -1) {
            _HashTable[j] = num;
            flag = true;
            _num[j] = sum;
            break;
          }
        }
      }
      break;
    }
  }
}

void HashTable::print() const {
  for (size_t i = 0; i < _size; i++) {
    cout << i;
    if (i != _size - 1) {
      cout << ' ';
    }
  }
  cout << endl;
  for (size_t i = 0; i < _size; i++) {
    cout << _HashTable[i];
    if (i != _size - 1) {
      cout << ' ';
    }
  }
  cout << endl;
  for (size_t i = 0; i < _size; i++) {
    cout << _num[i];
    if (i != _size - 1) {
      cout << ' ';
    }
  }
  cout << endl;
}

int main(int argc, char **argv) {
  size_t p, m, n, key;
  cin >> p >> m >> n;
  HashTable table(p, m);
  for (size_t i = 0; i < n; i++) {
    cin >> key;
    table.insert(key);
  }
  table.print();
  return 0;
}
