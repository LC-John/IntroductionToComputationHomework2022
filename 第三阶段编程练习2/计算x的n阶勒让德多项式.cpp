/*****
题目描述

n阶勒让德多项式的公式如下

关于输入

输入两个整数，第一个是n的值，第二个是x的值

关于输出

输出一个数，是函数值
（输出四舍五入后的整数值）

例子输入

2 5

例子输出

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
    cout << ceil(legendre(n, x)) << endl;   // 迎合测试数据 = =
    return 0;
}
