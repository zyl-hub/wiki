// Copyright[2020]<Baoquan Yang>
// All rights reserved

#include "include/map.h"

int main(int argc, char **argv) {
  size_t length, width;
  cin >> width >> length;
  map::map mymap(length, width);
  cout << "1ok" << endl;
  mymap.set_position("start");
  cout << "2ok" << endl;
  mymap.set_position("end");
  cout << "3ok" << endl;
  mymap.initialize();
  cout << "4ok" << endl;
  mymap.mapper();
  cout << mymap.mindistance() << endl;
  // cout << "hello, world" << endl;
  return 0;
}