/*****
��Ŀ����

�ж�ĳ���Ƿ������ꡣ

��������

����ֻ��һ�У�����һ������a(0 < a < 3000)

�������

һ�У������Ԫa�����������Y���������N

��������

2006

�������

N
*****/

#include <iostream>
using namespace std;

bool is_leap(int y)
{
    return ((y % 100) && !(y % 4)) || !(y % 400);
}

int main()
{
    int a = 0;
    cin >> a;
    if (is_leap(a))
        cout << "Y" << endl;
    else
        cout << "N" << endl;
    return 0;
}
