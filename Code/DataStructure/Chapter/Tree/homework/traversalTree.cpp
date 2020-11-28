#include <iostream>
#include <iterator>
using namespace std;

struct nodeInArray {
    int left = 0;
    int right = 0;
    int isRoot = 1;
};
void sequenceTraversal(nodeInArray* nodeArray, int n, int root);
void preOrder(nodeInArray* nodeArray, int root);
void midOrder(nodeInArray* nodeArray, int root);
void postOrder(nodeInArray* nodeArray, int root);

int main()
{
    int n = 0;
    int root = 0;
    cin >> n;
    nodeInArray* nodeArray = new nodeInArray[n + 1];

    for (int i = 1; i < n + 1; i++) {
        cin >> nodeArray[i].left;
        cin >> nodeArray[i].right;
    }

    for (int i = 1; i < n + 1; i++) {
        if (nodeArray[i].left != 0) {
            nodeArray[nodeArray[i].left].isRoot = 0;
        }
        if (nodeArray[i].right != 0) {
            nodeArray[nodeArray[i].right].isRoot = 0;
        }
    }

    for (int i = 1; i < n + 1; i++) {
        if (nodeArray[i].isRoot == 1) {
            root = i;
        }
    }
    preOrder(nodeArray, root);
    cout << endl;
    midOrder(nodeArray, root);
    cout << endl;
    postOrder(nodeArray, root);
    cout << endl;
    sequenceTraversal(nodeArray, n, root);

    return 0;
}

void sequenceTraversal(nodeInArray* nodeArray, int n, int root)
{
    int* isComplete = new int[2 * n + 1];
    isComplete[1] = root;
    for (int i = 1; i < n + 1; i++) {
        if (isComplete[i] != 0) {
            isComplete[2 * i] = nodeArray[isComplete[i]].left;
            isComplete[2 * i + 1] = nodeArray[isComplete[i]].right;
        } else {
            isComplete[2 * i] = 0;
            isComplete[2 * i + 1] = 0;
        }
    }
    for (int i = 1; i < 2 * n + 1; i++) {
        if (isComplete[i] != 0) {
            cout << isComplete[i] << " ";
        }
    }
}

void preOrder(nodeInArray* nodeArray, int root)
{
    if (root == 0)
        return;
    cout << root << " ";
    preOrder(nodeArray, nodeArray[root].left);
    preOrder(nodeArray, nodeArray[root].right);
}

void midOrder(nodeInArray* nodeArray, int root)
{
    if (root == 0)
        return;
    midOrder(nodeArray, nodeArray[root].left);
    cout << root << " ";
    midOrder(nodeArray, nodeArray[root].right);
}
void postOrder(nodeInArray* nodeArray, int root)
{
    if (root == 0)
        return;
    postOrder(nodeArray, nodeArray[root].left);
    postOrder(nodeArray, nodeArray[root].right);
    cout << root << " ";
}
