/*****
题目描述

给丁一对正整数[p,q]，其中，p小于q 且q不大于100000
请按从小到大的顺序输出p和q之间的素数序列，以逗号间隔。输出的素数 a 需满足如下二个条件：
（1）p<=a<=q；
（2）a 的逆序 b 也必须是素数，且 a<=b,同时，p<=b<=q
例如，p=2, q=50,则输出：
2,3,5,7,11,13
注意：13的逆序31也是素数，且都在[2,50]的范围内，13小于31，故只输出 13.
如果没有满足条件的序列，则输出 NULL

关于输入

两个正整数，由逗号间隔，分别表示 p 和 q

关于输出

输出符合条件的素数序列，其间以逗号间隔；如果没有满足条件的序列，则输出 NULL

例子输入

10,50

例子输出

11,13
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_NUM 100100

bool is_prime[MAX_NUM] = {false};

void gen_prime(int q)
{
    memset(is_prime, 0xff, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= q; i++)
        if (is_prime[i])
            for (int j = i + i; j <= q; j += i)
                is_prime[j] = false;
}

int rev_num(int n)
{
    int ret = 0;
    while (n)
    {
        ret = ret * 10 + (n % 10);
        n /= 10;
    }
    return ret;
}

int main()
{
    int p = 0, q = 0;
    char c = '\0';
    bool flag = false;
    cin >> p >> c >> q;
    gen_prime(q);
    for (int i = p, j = p; i <= q; i++)
    {
        j = rev_num(i);
        if (is_prime[i] && is_prime[j] && i <= j && j <= q)
        {
            if (flag)
                cout << c;
            else
                flag = true;
            cout << i;
        }
    }
    if (flag)
        cout << endl;
    else
        cout << "NULL" << endl;
    return 0;
}
