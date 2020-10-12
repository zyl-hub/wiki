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
        for (int j = 0; j < length; j++) {
            int tempPriority = 0;
            cin >> tempPriority;
            array[j].priority = tempPriority;
        }
        array[pos].isPrint = 1;
        priorityPrinting(array, length);
    }
    return 0;
}

void priorityPrinting(node* array, int length)
{
    int temp = 0;
    while (temp != (length - 1)) {
        int isMax = 1;
        for (int i = temp; i < length; i++) {
            if (array[i].priority > array[temp].priority) {
                isMax = 0;
            }
        }
        if (!isMax) {
            node tempNode;
            tempNode.priority = array[temp].priority;
            tempNode.isPrint = array[temp].isPrint;
            for (int j = temp; j < length - 1; j++) {
                array[j] = array[j + 1];
            }
            array[length - 1] = tempNode;
        }
        if (isMax) {
            temp += 1;
        }
    }
    for (int i = 0; i < length; i++) {
        if (array[i].isPrint == 1) {
            cout << i + 1 << endl;
            return;
        }
    }
}
