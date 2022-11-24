/*****
题目描述

N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …,
TK，则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

关于输入

输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。第一行有n个整数，用空格分隔，第i个整数
Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。

关于输出

输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

例子输入

8
186 186 150 200 160 130 197 220

例子输出

4
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200

/**
思路：两次动态规划

首先介绍最长上升子序列问题。
在有n个元素的数组nums中，若有0 <= i1 < i2 < ... < it < n，且nums[i1] < nums[i2] < ... < nums[it]，
则nums[i1], nums[i2], ..., nums[it]是nums的一个上升子序列。问题是如何求取nums的最长上升子序列的长度。

用dp[i]来表示以nums[i]为结束的上升子序列的最长长度。
显然只要有j < i且nums[j] < nums[i]，那么就可以用在nums[j]结尾的最长子序列后面拼上nums[i]，得到长度为dp[j] + 1的上升子序列。
而如果不存在这样的j，说明nums[i]是目前为止最小的数，其单独也可以作为一个上升子序列，长度为1。
因此dp[i] = max(1, dp[j] + 1), if 0 <= j < i and nums[j] < nums[i]
当计算完dp数组后，遍历找到最大的dp[i]即得到了最长上升子序列的长度。

下面来考虑本题目，题目要求找到最长的先升再降的子序列。因此我们可以先计算上升子序列dp1，再倒过来计算上升子序列dp2。
dp1[i]表示以nums[i]为结束的上升子序列的最长长度，dp2[i]表示将从尾到头看nums数组，以nums[i]为结束的上升子序列的最长长度。
那么dp1[i] + dp2[i] - 1就是以nums[i]为拐点的先升再降子序列的最长长度。遍历所有位置找到最大即可。
**/

int main()
{
    int dp1[MAX_N] = {0}, dp2[MAX_N] = {0};
    int h[MAX_N] = {0}, n = 0, ans = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
    {
        dp1[i] = 1;
        for (int j = 0; j < i; j++)
            if (h[j] < h[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        dp2[i] = 1;
        for (int j = n - 1; j > i; j--)
            if (h[j] < h[i])
                dp2[i] = max(dp2[i], dp2[j] + 1);
    }
    for (int i = 0; i < n; i++)
        ans = max(ans, dp1[i] + dp2[i] - 1);
    cout << n - ans << endl;
    return 0;
}
