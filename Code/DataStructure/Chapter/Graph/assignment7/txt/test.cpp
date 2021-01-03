#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    int roadlength;
};
queue<node> road;

int main()
{
    int n, m, x1, y1, x2, y2;
    char arr[105][105];
    bool pass[105][105] = { false };
    int xx[4] = { 1, 0, 0, -1 }; //下、右、左、上
    int yy[4] = { 0, 1, -1, 0 };
    int re = -1;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    char tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    node s;
    s.x = x1;
    s.y = y1;
    s.roadlength = 0;
    road.push(s);
    pass[x1][y1] = true;
    while (!road.empty()) {
        node old = road.front();
        road.pop();
        for (int i = 0; i < 4; ++i) {
            if (i == 0 || i == 3) {
                if (arr[old.x][old.y] == '-')
                    continue;
            }
            if (i == 1 || i == 2) {
                if (arr[old.x][old.y] == '|')
                    continue;
            }
            node now;
            now.x = old.x + xx[i];
            now.y = old.y + yy[i];
            now.roadlength = old.roadlength + 1;
            if (now.x < 1 || now.y < 1 || now.x > n || now.y > m || pass[now.x][now.y] || arr[now.x][now.y] == '*')
                continue;
            if (i == 0 || i == 3) {
                if (arr[now.x][now.y] == '-')
                    continue;
            }
            if (i == 1 || i == 2) {
                if (arr[now.x][now.y] == '|')
                    continue;
            }
            road.push(now);
            pass[now.x][now.y] = true;
            if (now.x == x2 && now.y == y2) {
                cout << now.roadlength;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
