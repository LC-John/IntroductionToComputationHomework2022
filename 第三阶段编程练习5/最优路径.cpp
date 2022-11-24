/*****
题目描述

给定一个n*m的方格棋盘，第i行第j列的方格价值为W(i, j)。现在你从第一行的任选方格出发，可以选择向南、
向西或者向东走，但是不能重复经过相同的格子（即不能走回头路），一直到第n行的任意一个方格为止。
请你设计一条路径，使得从开始到结束所经过的所有方格的价值和最大。

关于输入

输入包含多组数据。
每组数据第一行为两个整数n和m（1<=n, m<=200），表示棋盘大小。下接一个n*m的整数矩阵，描述价值矩阵，
W(i,j)在[-1000, 1000]之内。

关于输出

对于每一组数据，输出一个整数，表示最大的价值。

例子输入

2 1
100
-101
4 4
1 -5 20 3
3 2 -50 20
3 3 3 3
9 -100 0 17

例子输出

-1
66

提示信息

样例第二组数据最优路径是(1,3)-(1,4)-(2,4)-(3,4)-(3,3)-(4,3)-(4,4)
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 300
#define MIN_INT 0x80000000

/**
思路：动态规划

简单分析问题可以发现，在每一行row（下标从1开始）内的得分都只能是由row[j]到row[k]的连续的一段的和。
为了后面能方便地计算row中任意一段的和，我们构造前缀和数组psum。
psum[i]表示从row[0]加到row[i]的和，那么对row中任意的j到k一段（0 < j <= k），其和就是psum[k] - psum[j-1]。
进一步地，我们可以发现根本没有必要存储整个矩阵，而是直接存储每一行的psum数组即可。
因此，我们用psum[i][j]表示矩阵第i行（从1开始）的长度为j的前缀和。psum[i][0]总是0。

用dp[i][j]表示第i行走完之后在第j个位置停下后能获得的最大分数。
我们可以从i-1行的任意k位置尝试，向下一行后径直走到j位置，在其中取分数最大的方案作为dp[i][j]。
这一过程中，dp[i-1][k]假设已知，在第i行的得分为psum[i][max(j, k)] - psum[i][min(j, k)-1]。
最后只需要考虑起始的边界条件即可——很显然dp[0][j]总是0，因为此时在第0行，还没有进入矩阵。
自上而下计算完dp数组后，扫描第n行找到最大值即为所需答案。
**/

int n = 0, m = 0;
int psum[MAX_N][MAX_N] = {0};
int dp[MAX_N][MAX_N] = {0};

int main()
{
    int num = 0;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> psum[i][j];
                psum[i][j] += psum[i][j - 1];
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = MIN_INT;
                for (int k = 1; k <= m; k++)
                {
                    num = psum[i][max(j, k)] - psum[i][min(j, k) - 1];
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + num);
                }
            }
        num = MIN_INT;
        for (int j = 1; j <= m; j++)
            num = max(num, dp[n][j]);
        cout << num << endl;
    }
    return 0;
}
