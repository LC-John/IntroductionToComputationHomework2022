/*****
��Ŀ����

�������� s �� w ���ж� s ������ w �е�һ�γ��ֵ�λ�á�

��������

����ֻ��һ�У���һ���� s �͵ڶ������� w ������֮����һ���ո�ָ���ÿ���ַ����ĳ��ȶ�С��50���������뱣֤sһ����w��һ���Ӵ���

�������

���Ҳֻ��һ�У�s �� w �г��ֵ�λ�á�

��������

it waiter

�������

2
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100

int main()
{
    char s[MAX_LEN] = "\0", w[MAX_LEN] = "\0";
    cin >> s >> w;
    cout << strstr(w, s) - w;   // strstrֱ��Ѱ���Ӵ�
    return 0;
}
