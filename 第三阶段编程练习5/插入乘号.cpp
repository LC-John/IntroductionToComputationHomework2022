/*****
题目描述

给定一个非负整数，用k个乘号将其分割，使得乘积最大。
例如：在整数12345中插入两个乘号，有以下插入法：
1*2*345 1*23*45 1*234*5
12*3*45 12*34*5
123*4*5
其中最大值是123*4*5 = 2460

关于输入

一行两个非负整数，非负整数s（s ≦ 10^9）和乘号的个数k（0 ≦ k < s的位数）。
输入保证，如果按题目要求的乘法操作，不会使int发生溢出。

关于输出

一行一个整数，即乘积的最大值

例子输入

12345 2

例子输出

2460
*****/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 20

int dfs(char *str, int l, int k)    // str字符串，长度l，乘号个数k
{
    int num = 0, ret = 0;
    if (l <= k)     // 若乘号个数大于间隙数
        return -1;  // 则不可能完成插入，直接终止，返回-1
    if (!k)                     // 若没有乘号
    {
        sscanf(str, "%d", &num);    // 则返回当前字符串对应的数字
        return num;
    }
    for (int i = 1; i < l; i++)             // 从第一个空隙开始
    {
        num = num * 10 + str[i - 1] - '0';
        ret = max(ret, num * dfs(str + i, l - i, k - 1));   // 插入乘号，递归搜索
    }
    return ret;
}

int main()
{
    char str[MAX_LEN] = "\0";
    int l = 0, k = 0;
    scanf("%s %d", str, &k);
    l = strlen(str);
    printf("%d\n", dfs(str, l, k));
    return 0;
}
