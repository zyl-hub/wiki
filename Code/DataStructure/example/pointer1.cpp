#include <iomanip>
#include <iostream>
using namespace std;

int main()
{

  // �˽�һ����Ĳ���ϵͳ�ͱ���������
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

  // ����ֱ��Ѱַ
  //    int x = 123;  // 123ʮ�������Ƕ��٣�
  //    cout << "x=" << x << hex << "  " << x << endl;
  //    return 0;

  // �������Ѱַ
  //int x = 123;
  //int* px;
  //px = &x;

  //cout << "x = " << x << hex << "  " << x << endl;
  //cout << "&x = " << &x << endl;
  //cout << "px = " << px << endl;
  //cout << "*px = " << *px << endl;
  //return 0;

  // ָ���ʼ������
  //int* px;

  //cout << "px = " << px << endl;
  //cout << "*px = " << hex << *px << endl;
  //return 0;

  //��ָ��
  //int* px = NULL;

  //cout << "px = " << px << endl;
  //cout << "*px = " << *px << endl;
  //cout << "using NULL pointer!!!" << endl;
  //return 0;

  // ��̬��һ�ռ��ʹ��
  int *p, *q;

  p = new int(123);
  q = p;
  delete p;
  //    p = q = NULL;
  //
  *p = 10;
  *q = 8;
  return 0;

  // ��̬�����ռ��ʹ��
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
