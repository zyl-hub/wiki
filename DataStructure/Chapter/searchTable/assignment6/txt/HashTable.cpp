#include <iostream>
using namespace std;

struct HashTableNode {
    int val = -1;
    int times = 0;
};

int main()
{
    int p = 0;
    int m = 0;
    int n = 0;
    cin >> p;
    cin >> m;
    cin >> n;
    int* data = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    HashTableNode* HashTable = new HashTableNode[m];
    for (int i = 0; i < n; i++) {
        int pos = 0;
        int times = 0;
        pos = data[i] % p;
        while (HashTable[pos].val != -1) {
            pos++;
            times++;
            if (pos == 14 && HashTable[pos].val != -1) {
                pos = 0;
                times++;
            }
        }
        times++;
        HashTable[pos].val = data[i];
        HashTable[pos].times = times;
    }
    for (int i = 0; i < m; i++) {
        cout << i;
        if (i != m - 1)
            cout << ' ';
    }

    cout << endl;

    for (int i = 0; i < m; i++) {
        cout << HashTable[i].val << ' ';
        if (i != m - 1)
            cout << ' ';
    }

    cout << endl;

    for (int i = 0; i < m; i++) {
        cout << HashTable[i].times << ' ';
        if (i != m - 1)
            cout << ' ';
    }

    return 0;
}
