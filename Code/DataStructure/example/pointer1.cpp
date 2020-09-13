#include <iomanip>
#include <iostream>
using namespace std;

int main()
{

  // 了解一下你的操作系统和编译器特性
  //cout << "sizeof(int *) = " << sizeof(int*) << endl;
  //cout << "sizeof(double *) = " << sizeof(double*) << endl;
  //cout << endl;
  //cout << "sizeof(int) = " << sizeof(int) << endl;
  //cout << "sizeof(long int) = " << sizeof(long int) << endl;
  //cout << "sizeof(long long int) = " << sizeof(long long int) << endl;
  //cout << "sizeof(double) = " << sizeof(double) << endl;
  //cout << endl;
  //cout << "sizeof(bool) = " << sizeof(bool) << endl;
  //cout << "sizeof(char) = " << sizeof(char) << endl;
  //cout << endl;

  // 变量直接寻址
  //    int x = 123;  // 123十六进制是多少？
  //    cout << "x=" << x << hex << "  " << x << endl;
  //    return 0;

  // 变量间接寻址
  //int x = 123;
  //int* px;
  //px = &x;

  //cout << "x = " << x << hex << "  " << x << endl;
  //cout << "&x = " << &x << endl;
  //cout << "px = " << px << endl;
  //cout << "*px = " << *px << endl;
  //return 0;

  // 指针初始化问题
  //int* px;

  //cout << "px = " << px << endl;
  //cout << "*px = " << hex << *px << endl;
  //return 0;

  //空指针
  //int* px = NULL;

  //cout << "px = " << px << endl;
  //cout << "*px = " << *px << endl;
  //cout << "using NULL pointer!!!" << endl;
  //return 0;

  // 动态单一空间的使用
  int *p, *q;

  p = new int(123);
  q = p;
  delete p;
  //    p = q = NULL;
  //
  *p = 10;
  *q = 8;
  return 0;

  // 动态连续空间的使用
  //    int *p = new int[10];
  //    for(int i = 0; i< 10; ++i) p[i]=i;
  //
  //    delete []p;
  //    //p = NULL;
  //
  //    p[0] = 123;
  //
  //    return 0;
}
