/*****
题目描述

有n个硬币排成一排，每个硬币上用一个数字标识了它的价值。每次要你从最左边或者最右边拿
出一个硬币。总共拿k次，写一个算法，使能拿到的硬币的价值和最大。

关于输入

输入包含两行，第一行为n， k；
第二行包含n个数字，表示n个硬币的价值。
1 <= k <= n <= 100000
单个硬币的价值大于0且不超过10000.

关于输出

输出可以拿到的k个硬币最大的价值和。

例子输入

6 3
5 4 3 2 1 6

例子输出

15

提示信息

从左边开始连续取两个硬币，右边取一个硬币即可。
*****/

#include <iostream>
using namespace std;

#define MAX_N 100010

int val[MAX_N] = {0};

int main()
{
    int n = 0, k = 0, t = 0;
    int sum_t = 0, min_sum_t = 0, sum = 0;
    cin >> n >> k;
    t = n - k;
    for (int i = 0; i < t; i++)
    {
        cin >> val[i];
        sum_t += val[i];
        min_sum_t += val[i];
        sum += val[i];
    }
    for (int i = t; i < n; i++)
    {
        cin >> val[i];
        sum += val[i];
        sum_t += val[i] - val[i - t];
        if (sum_t < min_sum_t)
            min_sum_t = sum_t;
    }
    cout << sum - min_sum_t;
    return 0;
}
