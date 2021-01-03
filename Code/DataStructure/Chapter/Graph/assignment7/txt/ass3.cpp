#include <iostream>
using namespace std;

template <class Ver, class Edge>
class Graph
{
private:
    int Vers, Edges;
    struct edgeNode
    {
        int end;
        Edge weight;
        edgeNode* next;
        edgeNode(int e, Edge w, edgeNode* n = NULL) { end = e; weight = w; next = n; }
    };
    struct verNode
    {
        Ver ver;
        edgeNode* head;
        int inNum, outNum;
        verNode(edgeNode* h = NULL, int inN = 0, int outN = 0) { head = h; inNum = inN; outNum = outN;}
    };
    verNode* verList;
    int find(Ver v)const
    {
        for (int i = 0; i < Vers; ++i)
            if (verList[i].ver == v) return i;
        return -1;
    }
public:
    Graph(int vSize);
    void insert(Ver x, Ver y, Edge w);
    void deleteEdg(int x);
    int answer();
    ~Graph();
};

template <class Ver, class Edge>
Graph<Ver, Edge>::Graph(int vSize)
{
    Vers = vSize; Edges = 0;
    verList = new verNode[vSize];
    for (int i = 0; i < Vers; ++i) verList[i].ver = i + 1;
}
template <class Ver, class Edge>
void Graph<Ver, Edge>::insert(Ver x, Ver y, Edge w)
{
    int u = find(x), v = find(y);
    verList[u].outNum++;
    verList[v].inNum++;
    verList[u].head = new edgeNode(v, w, verList[u].head);
    ++Edges;
}

// 删除指向verList[i]的所有出边
template <class Ver, class Edge>
void Graph<Ver, Edge>::deleteEdg(int i){
    edgeNode* p = verList[i].head;
    while (p != NULL) {
        verList[i].head = p -> next;
        verList[p -> end].inNum--;
        delete p;
        Edges--;
        p = verList[i].head;
    }
}

template <class Ver, class Edge>
int Graph<Ver, Edge>::answer(){
    int semester = 1;
    while (Edges > 0) {
        for (int i = 0; i < Vers; ++i){
            // 课程已经完成
            if (verList[i].ver < 0) continue;
            // 课程的先修课全部完成
            else if (verList[i].inNum == 0){
                deleteEdg(i);
                verList[i].ver = -1;
            }
        }
        semester++;
    }
    
    return semester;
}

template <class Ver, class Edge>
Graph<Ver, Edge>::~Graph()
{
    int i;
    edgeNode* p;
    for (i = 0; i < Vers; ++i)
        while ((p = verList[i].head) != NULL)
        {
            verList[i].head = p->next;
            delete p;
        }
    delete[] verList;
}

int main()
{
    int n, m, semester = 1;
    cin >> n >> m;
    if (m != 0) {
        Graph<int, int> A(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            A.insert(y, x, 1);
        }
        semester = A.answer();
    }
    cout << semester;
    return 0;
}
