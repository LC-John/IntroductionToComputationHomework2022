/*****
��Ŀ����

���������������ϣ�������������ʱ����Ԫ�ش�С�����˳��������Զ��ż����
ע�⣺�����ļ����п������ظ�Ԫ�أ�������Ľ����в������ظ�Ԫ�ء����û�н���������� NULL
����
����A��1,3,5,6,10,6,8,11
����B: 2,4,8,6,10,6,12,13
��ô�����Ϊ��
6,8,10

��������

2�У�ÿ�б�ʾһ�����ϵ�Ԫ�����У�Ԫ��֮���Զ��ż�����ٶ�ÿ�����ϲ�����200��Ԫ�ء�

�������

�������ϵĽ�������Ԫ�ش�С����������Զ��ż�������û�н���������� NULL

��������

1,3,5,6,10,6,8,11
2,4,8,6,10,6,12,13

�������

6,8,10

��ʾ��Ϣ

������Ԫ�صĸ������Լ���취ȷ��
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
#define MASK 0x7fffffff

int num1[MAX_N] = {0}, cnt1 = 0;
int num2[MAX_N] = {0}, cnt2 = 0;

int main()
{
    int n = 0;
    char c = '\0';
    bool flag = true;
    while (cin >> n)
    {
        cin.get(c);
        num1[cnt1++] = n;
        if (c != ',')
            break;
    }
    sort(num1, num1 + cnt1);
    for (int i = 1; i < cnt1; i++)
        if (num1[i] == num1[i - 1])
            num1[i - 1] = MASK;

    while (cin >> n)
    {
        cin.get(c);
        num2[cnt2++] = n;
        if (c != ',')
            break;
    }
    sort(num2, num2 + cnt2);

    for (int i = 0; i < cnt2; i++)
        for (int j = 0; j < cnt1; j++)
        {
            if (num2[i] == num1[j])
            {
                if (flag)
                    flag = false;
                else
                    cout << ",";
                cout << num1[j];
                num1[j] = MASK;
            }
        }
    if (flag)
        cout << "NULL";
    cout << endl;

    return 0;
}
