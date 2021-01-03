#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    char** arr = NULL;
    arr = new char*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new char[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    return 0;
}
