#include <iostream>
using namespace std;

struct node {
    int Val;
    node* leftSon = 0;
    node* rightSon = 0;
    node* parent = 0;
};

void insertNode(int Val, node* t);

int main()
{
    int n = 0;
    cin >> n;
    int* treeVal = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> treeVal[i];
    }
    node* root = new node;
    node* t = root;
    node* parent = 0;
    root->Val = treeVal[0];
    int Done = 0;
    for (int i = 0; i < n; i++) {
        int isleft = 0;
        int isright = 0;
        while (!Done) {
            if (treeVal[i] < t->Val) {
                parent = t;
                t = t->leftSon;
                isleft = 1;
                isright = 0;
            } else {
                parent = t;
                t = t->rightSon;
                isleft = 0;
                isright = 1;
            }
            if (t == 0) {
                Done = 1;
            }
        }
        Done = 0;
        t = new node;
        t->Val = treeVal[i];
        if (isleft && i>=1) {
            parent->leftSon = t;
        }
        if (isright && i>=1) {
            parent->rightSon = t;
        }
        t->parent = parent;
        if(i!=0){
            cout << t->parent->Val<<endl;
        }
        else {
        cout << "-1"<<endl;
        }
        t = root;
    }
    return 0;
}
