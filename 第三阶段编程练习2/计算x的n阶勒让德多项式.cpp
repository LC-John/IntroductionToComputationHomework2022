/*****
��Ŀ����

n�����õ¶���ʽ�Ĺ�ʽ����

��������

����������������һ����n��ֵ���ڶ�����x��ֵ

�������

���һ�������Ǻ���ֵ
�������������������ֵ��

��������

2 5

�������

7
*****/

#include <iostream>
#include <cmath>
using namespace std;

double legendre(int n, int x)
{
    if (!n)
        return 1;
    if (n == 1)
        return x;
    return ((2 * n - 1) * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x)) / n;
}

int main()
{
    int n = 0, x = 0;
    cin >> n >> x;
    cout << ceil(legendre(n, x)) << endl;   // ӭ�ϲ������� = =
    return 0;
}
