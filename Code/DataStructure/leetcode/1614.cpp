#include <iostream>
#include <locale>
using namespace std;

int numWays(int n);

int main()
{
    cout << numWays(43);
    return 0;
}

int numWays(int n)
{

    if (n == 0 || n == 1)
        return 1;
    else
        return (numWays(n - 1) + numWays(n - 2)) % 1000000007;
}
