/*****
��Ŀ����

���������ѧҩѧԺ��С���ڼƸſ���ѧϰ��������֮����������Ũ�����Ȥ����ÿ�β�������
�ƶ����ڵ�0��1��ǰ���£�����֪����һ����������ת������һ��������������С��������

��������

���빲���У�
��һ��Ϊһ������n (0 < n <= 200)���������������λ��
�ڶ���Ϊ��һ������������ÿһλ
������Ϊ�ڶ�������������ÿһλ

�������

�������һ����������ת��Ϊ�ڶ����������������ٲ�����������𰸲����ڣ������-1

��������

7
1 1 0 1 0 0 1
0 1 1 0 0 1 1

�������

4
*****/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 1000

int pos1[MAX_N] = {0}, n1 = 0;
int pos2[MAX_N] = {0}, n2 = 0;

int main()
{
    int n = 0, d = 0;
    cin >> n;
    /* Positions of 1's in each binary sequence */
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        if (d)
            pos1[n1++] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        if (d)
            pos2[n2++] = i;
    }

    d = 0;
    /* The numbers of 1's are not equal */
    if (n1 != n2)
        cout << -1;
    else
    {
        /* Move the 1's */
        for (int i = 0; i < n1; i++)
            d += abs(pos1[i] - pos2[i]);
        cout << d;
    }
    return 0;
}
