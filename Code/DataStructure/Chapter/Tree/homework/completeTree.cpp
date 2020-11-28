#include <iostream>
using namespace std;

struct nodeInArray {
    int left = 0;
    int right = 0;
    int isRoot = 1;
};

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

    int flag1 = 0;
    int flag2 = 0;
    for (int i = 1; i < 2 * (n + 1); i++) {
        if (flag1 && isComplete[i] != 0) {
            flag2 = 1;
        }
        if (isComplete[i] == 0) {
            flag1 = 1;
        }
    }

    if (flag1 && flag2) {
        cout << "N";
    } else {
        cout << "Y";
    }

    return 0;
}
