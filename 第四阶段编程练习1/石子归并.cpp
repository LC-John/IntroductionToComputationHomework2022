/*****
题目描述

现摆一排 N 堆石子（N ≤ 100），要将石子有次序地合并成一堆。规定每次只能选
取相邻的两堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。编一
程序，由文件读入堆数 N 及每堆的石子数（ ≤ 20）。选择一种合并石子的方案，
使所做 N－1 次合并，得分的总和最小。

关于输入

第一行为石子堆数 N；第二行为每堆石子数，数字之间用一个空格分隔。

关于输出

最小的得分总和。

例子输入

21
17 2 9 20 9 5 2 15 14 20 19 19 1 9 8 8 9 14 9 4 8

例子输出

936

提示信息

求解不当，可能超时。
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 110
#define MAX_INT 0x7fffffff

/**
思路 -- 动态规划 + 前缀和

前缀和在之前已经介绍过，参考第三阶段编程练习5的最优路径一题示例。
用psum[i]表示pile[0]到pile[i]的和（pile下标从1开始，pile[0] = 0）。
那么pile中任意i到j的和sum(i,j)就可以用psum数组求取：
sum(i,j) = psum[j] - psum[i-1]。

用dp[i][j]表示从pile[i]到pile[j]的最小合并方案的分数。
我们可以从i、j中找到k，使得从k合i到j区间的方案是最小的。
不断递推求取dp数组，dp[1][n]即为所求答案。
**/

int pile[MAX_N] = {0}, psum[MAX_N] = {0};
int dp[MAX_N][MAX_N] = {0};

int main()
{
    int n = 0, tmp = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pile[i];
        psum[i] = psum[i - 1] + pile[i];
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j + i <= n; j++)
        {
            tmp = i + j;
            dp[j][tmp] = MAX_INT;
            for (int k = j; k <= tmp; k++)
                dp[j][tmp] = min(dp[j][tmp], dp[j][k] + dp[k + 1][tmp] + psum[tmp] - psum[j - 1]);
        }
    cout << dp[1][n];
    return 0;
}
