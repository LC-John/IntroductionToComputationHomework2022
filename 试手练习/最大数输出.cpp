/*****
��Ŀ����

������������,�����������

��������

����Ϊһ�У�������������

�������

���Ϊ����������

��������

10 20 56

�������

56
*****/

#include <iostream>
using namespace std;

#define MIN_INF 0x80000000

int main()
{
    int _max = MIN_INF, num = 0;
    while (cin >> num)
        if (num > _max)
            _max = num;
    cout << _max << endl;
    return 0;
}
