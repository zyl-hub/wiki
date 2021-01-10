#include <iostream>
using namespace std;

void line1();
void line2();

int main()
{
    line1();
    line1();
    line2();
    line2();

    return 0;
}

void line1()
{
    cout << "Three blind mice" << endl;
}

void line2()
{
    cout << "See how they run" << endl;
}
