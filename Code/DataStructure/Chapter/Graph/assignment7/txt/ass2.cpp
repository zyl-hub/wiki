#include <iostream>
using namespace std;

template <class Ver, class Edge>
class Graph {
private:
    int Vers, Edges;
    struct edgeNode {
        int end;
        Edge weight;
        edgeNode* next;
        edgeNode(int e, Edge w, edgeNode* n = NULL)
        {
            end = e;
            weight = w;
            next = n;
        }
    };
    struct verNode {
        Ver ver;
        edgeNode* head;
        verNode(edgeNode* h = NULL) { head = h; }
    };
    verNode* verList;
    int find(Ver v) const
    {
        for (int i = 0; i < Vers; ++i)
            if (verList[i].ver == v)
                return i;
    }
    void dfs(int start, int M, int& top, bool visited[], int st[], int& count) const;

public:
    Graph(int vSize);
    void insert(Ver x, Ver y, Edge w);
    void dfs(int start, int M) const;
    ~Graph();
};

template <class Ver, class Edge>
Graph<Ver, Edge>::Graph(int vSize)
{
    Vers = vSize;
    Edges = 0;
    verList = new verNode[vSize];
    for (int i = 0; i < Vers; ++i)
        verList[i].ver = i + 1;
}
template <class Ver, class Edge>
void Graph<Ver, Edge>::insert(Ver x, Ver y, Edge w)
{
    int u = find(x), v = find(y);
    verList[u].head = new edgeNode(v, w, verList[u].head);
    ++Edges;
}
template <class Ver, class Edge>
void Graph<Ver, Edge>::dfs(int start, int M) const
{
    bool* visited = new bool[Vers];
    int *stack = new int[M], top = 0, count = 0;
    for (int i = 0; i < Vers; ++i)
        visited[i] = false;
    dfs(start - 1, M, top, visited, stack, count);
    cout << count;
}

template <class Ver, class Edge>
void Graph<Ver, Edge>::dfs(int start, int M, int& top, bool visited[], int st[], int& count) const
{
    edgeNode* p = verList[start].head;
    visited[start] = true;
    st[top++] = start;
    if (top == M + 1)
        count++;
    else {
        while (p != NULL) {
            if (!visited[p->end])
                dfs(p->end, M, top, visited, st, count);
            p = p->next;
        }
    }
    visited[start] = false;
    --top;
}

template <class Ver, class Edge>
Graph<Ver, Edge>::~Graph()
{
    int i;
    edgeNode* p;
    for (i = 0; i < Vers; ++i)
        while ((p = verList[i].head) != NULL) {
            verList[i].head = p->next;
            delete p;
        }
    delete[] verList;
}

int main()
{
    int n, m, start, M;
    cin >> n >> m >> start >> M;
    Graph<int, int> A(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        A.insert(x, y, 1);
    }
    A.dfs(start, M);
}
