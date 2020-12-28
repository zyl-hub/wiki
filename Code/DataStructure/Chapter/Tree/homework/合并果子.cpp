#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int answer = 0;
    int count = 0;
    cin >> n;
    int* fruits = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }
    sort(fruits, fruits + n);
    for (int i = 0; i < n - 1; i++) {
        if (fruits[i] != 0) {
            answer = answer + fruits[i] + fruits[i + 1];
            fruits[i + 1] = fruits[i] + fruits[i + 1];
            fruits[i] = 0;
            sort(fruits, fruits + n);
        }
    }
    cout << answer;
}
