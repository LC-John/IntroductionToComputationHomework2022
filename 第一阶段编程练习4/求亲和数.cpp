/*****
题目描述

遥远的古代，人们发现某些自然数之间有特殊的关系：如果两个数a和b，a的所有除本
身以外的因数之和等于b,b的所有除本身以外的因数之和等于a,则称a,b是一对亲和数。
例如：220和284就是一对亲和数
220的真因子包括：1,2,4,5,10,11,20,22,44,55,110.
1+2+4+5+10+ 11 + 20 + 22 + 44 + 55 +110 =284
284的真因数:1 + 2 + 4 + 71 + 142 = 220
那么 220和284就是一对亲和数.

关于输入

一个正整数n，1<=n<=100000。

关于输出

所有亲和数对"a b"，满足a和b均小于等于n。
每个亲和数对占一行，两个数之间用一个空格隔开，较小数在前，较大数在后。
对于多个亲和数对，以较小数递增的顺序输出它们。

例子输入

1500

例子输出

220 284
1184 1210
*****/

#include <iostream>
#include <cmath>
using namespace std;

int factor_sum(int num)
{
    int sum = - num, _sqrt = int(sqrt(num));
    for (int i = 1; i < _sqrt; i++)
        if (num % i == 0)
            sum += i + num / i; // 加速
    if (_sqrt * _sqrt == num)   // 特判平方根
        sum += _sqrt;
    return sum;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 200; i <= n; i++)
    {
        int c = factor_sum(i);
        if (c > i && c <= n && factor_sum(c) == i)
            cout << i << " " << c << endl;
    }
    return 0;
}
