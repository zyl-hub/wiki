#include <iostream>
using namespace std;

struct node {
    int priority = 0;
    bool isPrint = 0;
};

void priorityPrinting(node* array, int length);

int main()
{
    int testDataSetNumber = 0;
    cin >> testDataSetNumber;
    for (int i = 0; i < testDataSetNumber; i++) {
        int length = 0;
        int pos = 0;
        cin >> length;
        cin >> pos;
        node* array = new node[length];
        for (int k = 0; k < length; k++) {
            int tempPriority = 0;
            cin >> tempPriority;
            array[k].priority = tempPriority;
        }
        array[pos - 1].isPrint = 1;
    }
    return 0;
}

void priorityPrinting(node* array, int length)
{
    int temp = 0;
    bool flag = 1;
    while (flag) {
        int isMax = 1;
        for (int j = temp; j < length; j++) {
            //if (array[j].priority > array[temp].priority) {
                //int isMax = 0;
            //}
        }
        if (!isMax) {
            node tempNode;
            tempNode.priority = array[temp].priority;
            tempNode.isPrint = array[temp].isPrint;
        }
    }
}
