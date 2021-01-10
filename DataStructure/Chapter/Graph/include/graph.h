// Copyright[2020]<Baoquan Yang>
// All rights reserved

#ifndef MAIN_GRAPH_H
#define MAIN_GRAPH_H
#include <cstdlib>
#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;

template <typename TypeOfVer, typename TypeOfEdge> class graph {
public:
  virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
  virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
  virtual bool exist(TypeOfVer x, TypeOfVer y) const = 0;
  int numOfVer() const { return Vers; }
  int numOfEdge() const { return Edges; }

protected:
  size_t Vers, Edges;
};

template <typename TypeOfVer, typename TypeOfEdge>
class adjListGraph : public graph<TypeOfVer, TypeOfEdge>,
                     public std::error_code {
public:
  // The Constructor
  adjListGraph(size_t vSize, const TypeOfVer d[]);

  // Connect an edge between node x and node y
  void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w = 1);

  // Delete the edge between node x and node y
  void remove(TypeOfVer x, TypeOfVer y);

  // Determine whether there is an edge between node x and node y
  bool exist(TypeOfVer x, TypeOfVer y) const;

  // Find the minimum distance between two nodes
  TypeOfEdge unweightedShortDistance(TypeOfVer start, TypeOfVer end,
                                     TypeOfEdge noEdge) const;

  // The Destructor
  ~adjListGraph();

private:
  // Structure representing an edge
  // end: End of edge
  // weight: Edge weight
  struct edgeNode {
    size_t end;
    TypeOfEdge weight;
    edgeNode *next;

    edgeNode(size_t e, TypeOfEdge w, edgeNode *n = nullptr) {
      end = e;
      weight = w;
      next = n;
    }
  };

  // Structure representing a node
  struct verNode {
    TypeOfVer ver;
    edgeNode *head;
    explicit verNode(edgeNode *h = nullptr) { head = h; }
  };

  // Pointer for storage node
  verNode *verList;

  // Number of nodes and edges
  size_t Vers, Edges;

  // Locate a node
  int find(TypeOfVer v) const {
    for (size_t i = 0; i < Vers; ++i) {
      if (verList[i].ver == v)
        return i;
    }
  }
};

template <typename TypeOfVer, typename TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(size_t vSize,
                                                  const TypeOfVer *d) {
  Vers = vSize;
  Edges = 0;
  verList = new verNode[vSize];
  for (size_t i = 0; i < Vers; ++i)
    verList[i].ver = d[i];
}

template <typename TypeOfVer, typename TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph() {
  edgeNode *p;
  for (size_t i = 0; i < Vers; i++) {
    p = verList[i].head;
    while (p != nullptr) {
      verList[i].head = p->next;
      delete p;
      p = verList[i].head;
    }
  }
}

template <typename TypeOfVer, typename TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y,
                                                 TypeOfEdge w) {
  int u = find(x), v = find(y);
  verList[u].head = new edgeNode(v, w, verList[u].head);
  ++Edges;
}

template <typename TypeOfVer, typename TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y) {
  int u = find(x), v = find(y);
  edgeNode *p = verList[u].head, *q;
  if (p == nullptr)
    return;
  if (p->end == v) {
    verList[u].head = p->next;
    delete p;
    --Edges;
    return;
  }
  while (p->next != nullptr && p->next->end != v) {
    p = p->next;
  }
  if (p->next != nullptr) {
    q = p->next;
    p->next = q->next;
    delete q;
    --Edges;
  }
}

template <typename TypeOfVer, typename TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x,
                                                TypeOfVer y) const {
  int u = find(x), v = find(y);
  edgeNode *p = verList[u].head;

  while (p != nullptr && p->end != v)
    p = p->next;
  if (p == nullptr)
    return false;
  else
    return true;
}

template <typename TypeOfVer, typename TypeOfEdge>
TypeOfEdge adjListGraph<TypeOfVer, TypeOfEdge>::unweightedShortDistance(
    TypeOfVer start, TypeOfVer end, TypeOfEdge noEdge) const {
  queue<int> q;
  auto *distance = new TypeOfEdge[Vers];
  int *prev = new int[Vers];
  int u, sNo;
  edgeNode *p;
  for (size_t i = 0; i < Vers; i++)
    distance[i] = noEdge;
  sNo = find(start);
  distance[sNo] = 0;
  q.push(sNo);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (p = verList[u].head; p != nullptr; p = p->next) {
      if (distance[p->end] == noEdge) {
        distance[p->end] = distance[u] + 1;
        prev[p->end] = u;
        q.push(p->end);
      }
    }
  }
  return distance[find(end)];
}
#endif // MAIN_GRAPH_H
