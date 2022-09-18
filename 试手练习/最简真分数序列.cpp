/*****
题目描述

所谓最简真分数是指分子小于分母，且不能约分的分数。给定 n（1 < n < 200）个非负整数（每个整数不
超过3位），哪两个整数分别作为分子和分母能够构成最简真分数。输出所有的最简真分数组合；若没有，
则输出NO。

关于输入

第1行为正整数个数n
其后为n个非负整数，空格间隔。

关于输出

输出所有最简真分数，分子小的排在前面；若分子相同，分母小的排在前面。各分数之间用逗号间隔。
若没有，则输出NO

例子输入

8
3 7 11 0 5 13 15 9

例子输出

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
