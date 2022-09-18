/*****
��Ŀ����

��ν����������ָ����С�ڷ�ĸ���Ҳ���Լ�ֵķ��������� n��1 < n < 200�����Ǹ�������ÿ��������
����3λ���������������ֱ���Ϊ���Ӻͷ�ĸ�ܹ���������������������е�����������ϣ���û�У�
�����NO��

��������

��1��Ϊ����������n
���Ϊn���Ǹ��������ո�����

�������

���������������������С������ǰ�棻��������ͬ����ĸС������ǰ�档������֮���ö��ż����
��û�У������NO

��������

8
3 7 11 0 5 13 15 9

�������

3/5,3/7,3/11,3/13,5/7,5/9,5/11,5/13,7/9,7/11,7/13,7/15,9/11,9/13,11/13,11/15,13/15
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
unsigned int arr[MAX_N] = {0};
unsigned int prime[MAX_N]= {0};

void _sort(unsigned int *a, int n)
{
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] < a[j])
            {
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
            }
}

int gen_prime(unsigned num)
{
    int n_prime = 4;
    prime[0] = 2; prime[1] = 3; prime[2] = 5; prime[3] = 7;

    if (prime[n_prime - 1] >= num)
        return n_prime;

    for (int i = prime[n_prime-1] + 2; i <= num; i += 2)
    {
        bool flag = true;
        for (int j = 0; j < n_prime; j++)
            if (i % prime[j] == 0)
            {
                flag = false;
                continue;
            }
        if (flag)
            prime[n_prime++] = i;
    }
    return n_prime;
}

int main()
{
    int n = 0, n_prime = 0;
    bool printed_flag = false;
    bool flag = true;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    _sort(arr, n);
    n_prime = gen_prime(arr[n - 1]);

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            bool flag = false;
            for (int k = 0; k < n_prime; k++)
                if ((!(arr[i] % prime[k])) && (!(arr[j] % prime[k])))
                {
                    flag = true;
                    continue;
                }
            if (flag)
                continue;
            if (printed_flag)
                cout << ",";
            cout << arr[i] << "/" << arr[j];
            printed_flag = true;
        }
    if (!printed_flag)
        cout << "NO";
    cout << endl;
    return 0;
}
