#include <iostream>

using namespace std;

void swap4(int *, int *);
void swap5(int *, int *);

int main()
{
    int x = 4, y = 6;

    swap4(&x,&y);

    cout << "x=" <<  x << " y=" << y << endl;

    return 0;
}

void swap4(int *a,int *b)
{
    int *temp;
    temp = a;
    a = b;
    b = temp;
}

void swap5(int *a, int *b)
{
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}
