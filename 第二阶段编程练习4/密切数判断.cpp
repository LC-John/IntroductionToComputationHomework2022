/*****
��Ŀ����

������������������������������������������ͬ����ô����������Ϊ������������ 6 �� 12��
������������ 2 �� 3����ˣ�6 �� 12 ��һ�������������ж���������������������Ƿ�Ϊһ��
�����������ǣ����YES�������ǣ����NO ��

��������

�����������������ö��ż��

�������

���������������YES��
�����ǣ����NO��

��������

18,12

�������

YES
*****/

#include <iostream>
using namespace std;

#define MAX_NUM 100000

int prime[MAX_NUM] = {2, 3, 5, 7};
int n_prime = 4;

/** �������� **/
void generate_prime(int max_num)
{
    bool flag = false;
    for (int i = prime[n_prime - 1]; i <= max_num; i += 2)
    {
        flag = true;
        for (int j = 0; j < n_prime; j++)
            if (!(i % prime[j]))
            {
                flag = false;
                break;
            }
        if (flag)
            prime[n_prime++] = i;
    }
}

int main()
{
    int a = 0, b = 0;
    char c = '\0';

    /** �������ݣ��������� **/
    cin >> a >> c >> b;
    if (a < b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    generate_prime(b);

    for (int i = 0; i < n_prime; i++)
        if ((bool)(a % prime[i]) ^ (bool)(b % prime[i]))    // ���
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}
