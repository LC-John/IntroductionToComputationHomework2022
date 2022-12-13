/*****
题目描述

政府在某山区修建了一条道路，恰好穿越总共m个村庄的每个村庄一次，没有回路或交叉，任意两个村庄只能通过
这条路来往。已知任意两个相邻的村庄之间的距离为di（为正整数），其中，0 < i < m。为了提高山区的文化素
质，政府又决定从m个村中选择n个村建小学（设 0 < n < = m < 500 ）。请根据给定的m、n以及所有相邻村庄的
距离，选择在哪些村庄建小学，才使得所有村到最近小学的距离总和最小，计算最小值。

关于输入

第1行为m和n，其间用空格间隔
第2行为(m-1) 个整数，依次表示从一端到另一端的相邻村庄的距离，整数之间以空格间隔。
例如
10 3
2 4 6 5 2 4 3 1 3
表示在10个村庄建3所学校。第1个村庄与第2个村庄距离为2，第2个村庄与第3个村庄距离为4，第3个村庄与第4个
村庄距离为6，...，第9个村庄到第10个村庄的距离为3。

关于输出

各村庄到最近学校的距离之和的最小值。

例子输入

10 2
3 1 3 1 1 1 1 1 3

例子输出

18
*****/

#include<iostream>
#include<cmath>
using namespace std;

#define MAX_INT 0x7fffffff
#define MAX_N 1000

int m = 0, n = 0;
int dist[MAX_N][MAX_N] = {0};
int total[MAX_N][MAX_N] = {0};
int dp[MAX_N][MAX_N] = {0};

int main()
{
    cin >> m >> n;
    for(int i = 1; i < m; i++)
        cin>>dist[i][i+1];

    for(int i = 1; i <= m; i++)
        for(int j = i + 1; j <= m; j++)
            dist[i][j] = dist[j][i] = dist[i][j - 1] + dist[j - 1][j];
    for(int i = 1; i <= m; i++)
        for(int j = i + 1; j <= m; j++)
        {
            int mid = (i + j) / 2;
            for(int k = i; k <= j; k++)
                total[i][j] += dist[k][mid];
        }

    for(int i = 1; i <= m; i++)
        dp[i][1] = total[1][i];
    for(int i = 1; i <= m; i++)
        for(int j = 2; j <= n; j++)
        {
            dp[i][j] = MAX_INT;
            for(int k = j - 1;k <= i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + total[k + 1][i]);
        }
    cout << dp[m][n];
    return 0;
}
