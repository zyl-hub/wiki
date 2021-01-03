// Copyright[2020]<Baoquan Yang>
// All rights reserved

#ifndef MAIN_MAP_H
#define MAIN_MAP_H
#include "graph.h"
#include <string>
#include <utility>
#include <vector>
using std::string;
using std::vector;
namespace map {
class map {
private:
  size_t length = 0, width = 0;
  vector<size_t> start, end;
  string *m;
  adjListGraph<vector<size_t>, size_t> *graph;

public:
  // The Constructor
  map(size_t _length, size_t _width) {
    length = _length;
    width = _width;
    m = nullptr;
    graph = nullptr;
  }

  // API for instantiating the map
  void initialize();

  // API for setting a position
  void set_position(const string &pos);

  // Generating the map
  void mapper();

  int mindistance() const;

  // The Destructor
  ~map() = default;

private:
  // Instantiate the map
  void initialize(string *_m) { m = _m; }

  // Set the start
  void set_start(vector<size_t> _start) { start = std::move(_start); }

  // Set the end
  void set_end(vector<size_t> _end) { end = std::move(_end); }
};

void map::initialize() {
  string *tmp;
  tmp = new string[width];
  for (size_t i = 0; i < width; i++) {
    cin >> tmp[i];
    // assert tmp[i].length() to be length
  }
  initialize(tmp);
}

void map::set_position(const string &pos) {
  size_t r, c;
  vector<size_t> tmp;
  if (pos == "start") {
    cin >> r >> c;
    if (r > width) {
      return;
    }
    if (c > length) {
      return;
    }
    tmp.push_back(r);
    tmp.push_back(c);
    set_start(tmp);
  }
  if (pos == "end") {
    cin >> r >> c;
    if (r > width) {
      return;
    }
    if (c > length) {
      return;
    }
    tmp.push_back(r);
    tmp.push_back(c);
    set_end(tmp);
  } else
    return;
}

void map::mapper() {
  if (width == 0 || length == 0 || m == nullptr || start.empty() ||
      end.empty()) {
    cout << "Initialization incompletely, mapping failed." << endl;
    return;
  }
  auto *tmpvec = new vector<size_t>[width * length];
  size_t i = 0;
  for (size_t r = 0; r < width; r++) {
    for (size_t c = 0; c < length; c++) {
      tmpvec[i].push_back(r);
      tmpvec[i].push_back(c);
      i++;
    }
  }
  graph = new adjListGraph<vector<size_t>, size_t>(width * length, tmpvec);
  vector<size_t> tmpx, tmpy;
  for (size_t r = 0; r < width; r++) {
    for (size_t c = 0; c < length; c++) {
      tmpx.clear();
      tmpy.clear();
      if (c < length - 1 && (m[r].at(c) == '-' || m[r].at(c) == '.') &&
          (m[r].at(c + 1) == '.' || m[r].at(c + 1) == '-')) {
        tmpx.push_back(r);
        tmpx.push_back(c);
        tmpy.push_back(r);
        tmpy.push_back(c + 1);
        graph->insert(tmpx, tmpy);
      }
      if (r < width - 1 && (m[r].at(c) == '|' || m[r].at(c) == '.') &&
          (m[r + 1].at(c) == '.' || m[r + 1].at(c) == '|')) {
        tmpx.push_back(r);
        tmpx.push_back(c);
        tmpy.push_back(r);
        tmpy.push_back(c + 1);
        graph->insert(tmpx, tmpy);
      }
    }
  }
  cout << "finish" << endl;
}

int map::mindistance() const {
  vector<size_t> tmp;
  tmp.push_back(1);
  tmp.push_back(2);
  return graph->unweightedShortDistance(tmp, end, 9999999);
}
} // namespace map
#endif // MAIN_MAP_H
