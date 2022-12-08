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
