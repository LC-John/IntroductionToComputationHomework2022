/*****
题目描述

给定一组正整数，其中的最大值和最小值分别为max和min，其中的
一个数x到max和min的距离差D定义为
abs(abs(x-max) - abs(x-min))。
其中，abs()表示求一个数的绝对值

关于输入

输入第一行为整数n，剩余n行每行一个正整数。(n<=10000)

关于输出

输出仅一行，它的值为使得距离差D最小的x。

例子输入

5
3
1
7
5
9

例子输出

5

提示信息

函数abs()定义在stdlib.h中。
*****/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 10100
#define MAX_INT 0x7fffffff
#define MIN_INT 0x80000000

int v[MAX_N] = {0};

int calc_d(int x, int max_v, int min_v)
{
    return abs(abs(x - max_v) - abs(x - min_v));
}

int main()
{
    int n = 0, max_v = MIN_INT, min_v = MAX_INT;
    int min_d = MAX_INT, ans = 0, d = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        max_v = max(max_v, v[i]);
        min_v = min(min_v, v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        d = calc_d(v[i], max_v, min_v);
        if (d < min_d)
        {
            ans = v[i];
            min_d = d;
        }
    }
    cout << ans << endl;
    return 0;
}
