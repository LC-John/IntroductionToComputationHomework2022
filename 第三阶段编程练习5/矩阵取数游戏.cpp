/*****
题目描述

帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的n行*m列的矩阵，矩阵中的每个元素aij均为非负整数。游戏规则如下：
1. 每次取数时须从每行各取走一个元素，共n个。m次后取完矩阵所有的元素；
2. 每次取走的各个元素只能是该元素所在行的行首或行尾；
3. 每次取数都有一个得分值，为每行取数的得分之和；每行取数的得分 = 被取走的元素值*i，其中i表示第i次取数（从1开始编号）；
4. 游戏结束总得分为m次取数得分之和。
帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。

关于输入

包括n+1行；
第一行为两个用空格隔开的整数n和m。
第2~n+1行为n*m矩阵，其中每行有m个用单个空格隔开
l<=n，m<=80，1<=aij<=1000

关于输出

仅包含1行，为一个整数，即输入矩阵取数后的最大的分。

例子输入

2 3
1 2 3
3 4 2

例子输出

34
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 100

/**
思路：动态规划

首先，各行都是独立的，因此可以每一行分开计算，最后的结果加起来即可。

对某一行row来说，用dp[i][j]（i <= j）表示在[i,j]这个片段进行取数的最大得分。
显然dp[i][i] = row[i]。
考虑如何计算dp[i][j]，只会出现两种情况：
1. 先在[i, j]段的左侧（i）取数，那么得分为dp[i+1][j] + sum(row[i+1], row[i+2], ..., row[j]) + row[i]
2. 先在[i, j]段的右侧（j）取数，那么得分为dp[i][j-1] + sum(row[i], row[i+1], ..., row[j-1]) + row[j]
因此，当dp[i+1][j]和dp[i][j-1]已知的情况下，dp[i][j]取上述得分的最大值即可。
我们可以先初始化对角线（dp[i][i]），然后向dp矩阵的右上角计算即可，最终dp[0][length(row) - 1]便是答案。

可以使用前缀和sum数组来加速区间求和，sum[i]表示从row[0]一直到row[i-1]的和。那么就可以直接用sum[j+1] - sum[i]来计算某段的和

一个例子如下：
假设row为： 3 4 2
那么sum为： 3 7 9
dp数组为：  3 -11-> 11 -20-> 20
                    ^        ^
                    |        |
                    10       19
                    |        |
            0       4 -10-> 10
                            ^
                            |
                            8
                            |
            0       0       2
整个dp数组的传播计算过程也如上所示。
**/

int row[MAX_N] = {0};
int sum[MAX_N] = {0};
int dp[MAX_N][MAX_N] = {0};
int n = 0;

int main()
{
    int n_row = 0, ans = 0;
    int r = 0, c = 0;
    cin >> n_row >> n;
    while (n_row--)
    {
        memset(dp, 0x00, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin >> row[i];
            dp[i][i] = row[i];
            sum[i + 1] = sum[i] + row[i];
        }
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                r = j - i, c = j;
                if (r < 0)
                    continue;
                dp[r][c] = max(dp[r + 1][c] + sum[c + 1] - sum[r + 1] + row[r],
                                dp[r][c - 1] + sum[c] - sum[r] + row[c]);
                 cout << r << " " << c << " " << dp[r][c] << endl;    // Debug
            }
        ans += dp[0][n - 1];
    }
    cout << ans << endl;
    return 0;
}
