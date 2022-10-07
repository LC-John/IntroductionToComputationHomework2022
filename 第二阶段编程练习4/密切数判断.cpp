/*****
题目描述

任意给定两个正整数，如果这两个数的质因数均相同，那么这两个数称为密切数。例如 6 和 12，
其质因数均是 2 和 3；因此，6 和 12 是一对密切数。请判断任意给定的两个正整数是否为一对
密切数。若是，输出YES，若不是，输出NO 。

关于输入

输入两个正整数，用逗号间隔

关于输出

若是密切数，输出YES；
若不是，输出NO；

例子输入

18,12

例子输出

YES
*****/

#include <iostream>
using namespace std;

#define MAX_NUM 100000

int prime[MAX_NUM] = {2, 3, 5, 7};
int n_prime = 4;

/** 产生素数 **/
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

    /** 读入数据，产生素数 **/
    cin >> a >> c >> b;
    if (a < b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    generate_prime(b);

    for (int i = 0; i < n_prime; i++)
        if ((bool)(a % prime[i]) ^ (bool)(b % prime[i]))    // 异或
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}
