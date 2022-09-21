/*****
题目描述

Geeker对计算机和数学非常感兴趣，刚学完计概的他有一天突发奇想能不能编段小程序验证下哥
德巴赫猜想，即对于任意给定的偶数m（m>=6且不超出int范围），验证其能够表示成2个奇素数
之和。注意，1被认为既不是素数，也不是合数。

关于输入

一个偶数m，m的取值范围6 <= m <= 10000

关于输出

2个和是m的奇素数，它们之间用空格分隔。如果有多组满足，则每组之间需要换行（2个奇素数输
出时候小的在前面，大的在后面）。每组之间没有重复，存在多个组满足的情况下按第一个奇数
从小到大排列，见例子输出

例子输入

40

例子输出

3 37
11 29
17 23
*****/

#include <iostream>
using namespace std;

#define MAX_M 10010
bool is_prime[MAX_M] = {false};     // 存储各个数字是否是素数的数组；若i是素数，则is_prime[i]为真，否则为假

void check_prime(int m)             // 生成is_prime数组
{
    for (int i = 2; i <= m; i++)    // 初始化数组都为真（从2开始）
        is_prime[i] = true;

    for (int i = 2; i * 2 <= m; i++)            // 从i=2起
        for (int j = 2 * i; j <= m; j += i)     // 将i的倍数（除了i本身）
            is_prime[j] = false;                // 在is_prime数组中都标记为false
}

int main()
{
    int m = 0;
    cin >> m;
    check_prime(m);
    for (int i = 3; i * 2 <= m; i += 2)
        if (is_prime[i] && is_prime[m - i])
            cout << i << " " << m - i << endl;
    return 0;
}
