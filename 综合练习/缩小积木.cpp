/*****
题目描述

考完计算概论B后,阿福开始浪的飞起.最近阿福发现一个有趣的游戏.在他的面前有n个积木，从左至右每
个积木的高度为Hi，其中Hi为正整数，1 ≤ i ≤ n, 现在他想要用高度较小的积木来重新搭建该图形，
同时还要保持原图形中相邻积木高度的相对关系。
即新积木堆的高度Ti需要满足：
若Hi ≥ Hi+1，则Ti ≥ Ti+1
若Hi ≤ Hi+1，则Ti ≤ Ti+1
请问新积木堆的高度总和最小是多少？

关于输入

两行
第一行一个正整数，表示积木的个数n (n ≤ 1000000)
第二行包含n正整数，表示从左至右各积木的高度Hi (Hi ≤ 100000)，相邻两数用空格隔开

关于输出

一个整数，表示经缩小后所需的最小积木高度之和

例子输入

5
1 10 2 7 7

例子输出

8

提示信息

样例[1 10 2 7 7]经过缩小后的结果为[1 2 1 2 2]
*****/

#include <iostream>
#include <algorithm>
using namespace std;

/**
思路

首先，很容易想到，如果找到所有“谷”（谷的左右两侧都比谷大），那么就可以从谷向两侧扩展填充缩小后的高度。
而反过来想，任何一个位置的缩小后的高度要么是从该位置起向左的最长递减序列长度，要么是向右的（取二者较大值）。
那么问题就转化为求取每个位置的从左到右的最长递增序列长度和从右到左的最长递增序列长度。
用inc[i]记录以h[i]结尾的从左到右的最长递增序列长度，显然inc[0] = 1。
那么根据h[i]和h[i-1]的关系，有如下递推：

1. h[i] > h[i-1]，那么递增序列长度加一，inc[i] = inc[i-1] + 1；
2. h[i] < h[i-1]，那么递增序列长度为1，inc[i] = 1；
3. h[i] = h[i-1]，那么递增序列长度不变，inc[i] = inc[i-1]。

反过来可以用相同的方法求取从右到左的递增序列长度数组dec。
h[i]缩小后的高度就应该是max(inc[i], dec[i])。
**/

#define MAX_N 1001000

int h[MAX_N] = {0}, n = 0;
int increase[MAX_N] = {0}, decrease[MAX_N] = {0};

void compute_increasing(int* inc, int* h)
{
    inc[0] = 1;
    for (int i = 1; i < n; i++)
        if (h[i] > h[i - 1])
            inc[i] = inc[i - 1] + 1;
        else if (h[i] < h[i - 1])
            inc[i] = 1;
        else
            inc[i] = inc[i - 1];
}

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    compute_increasing(increase, h);
    reverse(h, h + n);
    compute_increasing(decrease, h);
    reverse(decrease, decrease + n);
    for (int i = 0; i < n; i++)
        ans += max(increase[i], decrease[i]);
    cout << ans << endl;
    return 0;
}
