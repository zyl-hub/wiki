#include <iostream>
using namespace std;

struct node {
    node* lson;
    node* rson;
};

struct leftAndRight {
    int l;
    int r;
};

void Ordertree(node* nodeArray);

int main()
{
    int num = 0;
    cin >> num;
    node* nodeArray = new node[num];
    leftAndRight* lrnode = new leftAndRight[num];
    for (int i = 0; i < num; i++) {
        int templson = 0;
        int temprson = 0;
        cin >> templson;
        cin >> temprson;
        lrnode[i].l = templson;
        lrnode[i].r = temprson;
    }
    for (int i = 0; i < num; i++) {
        nodeArray[i].lson = &nodeArray[lrnode[i].l];
        nodeArray[i].rson = &nodeArray[lrnode[i].r];
    }





    return 0;
}
void Ordertree(node* nodeArray){
    if (nodeArray==NULL) return;
    Ordertree(nodeArray->lson);
    Ordertree(nodeArray->rson);
}
