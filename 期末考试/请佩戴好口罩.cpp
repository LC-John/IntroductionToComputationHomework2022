/*****
题目描述

疫情当下，希望同学们都认真佩戴口罩，保护自己，保护他人。
现假设有一个n*n的网格，每个人分别站在网格中的一个方格上，人们可以选择佩戴/不佩戴口罩，口罩对于病毒
的传播有如下影响，分为两种情况：
1. 某人已被感染，若未佩戴口罩，则病毒的“传染区域”是患者周围的四个方格；若正确佩戴口罩，则病毒无法
传染其他人。
2. 某人健康，若未佩戴口罩，则只要他位于任意一个患者的“传染区域”内，就会被传染；若正确佩戴口罩，则
只有他同时位于4个患者的“传染区域”内时，才会被传染。
我们将给出网格中每个人的口罩佩戴情况，以及网格中第一个患者的位置，请你计算d天后共有多少患者。

关于输入

第一行输入正整数n，表示网格的边长，1<=n<=100。
接下来输入网格，n行，每行n个整数，0表示未佩戴口罩，1表示佩戴口罩。
接下来一行是两个整数，表示第一个感染者在网格中的行、列坐标（规定网格左上角格子的坐标为(0, 0)，右上
角格子的坐标为(0, n-1)，以此类推）。
接下来一行是一个正整数，表示天数d，1<=d<=100。

关于输出

输出为一行整数，表示经过d天后患者的人数。

例子输入

4
0 0 0 1
0 1 0 0
1 0 0 1
0 0 1 0
1 2
5

例子输出

11

提示信息

可以考虑构建多个大小相等的二维数组，存储不同的数据，例如：一个二维数组存储网各中患者/健康的情况，一
个二维数组存储口罩佩戴情况等等。当然，也可以用一个二维数组，但每个数组元素是一个包含两个分量（健康与
否、戴口罩与否）的结构类型。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 110
#define ND 4

const int dr[ND] = {0, 0, 1, -1};
const int dc[ND] = {1, -1, 0, 0};

int mask[MAXN][MAXN] = {0};
int sick[2][MAXN][MAXN] = {0}, cur = 0, nxt = 1;
int n = 0;

int main()
{
    int r = 0, c = 0, d = 0;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mask[i][j];
    cin >> r >> c >> d;
    r++;
    c++;
    sick[cur][r][c] = 1;
    while (d--)
    {
        memset(sick + nxt, 0x00, sizeof(int) * MAXN * MAXN);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (sick[cur][i][j] && !mask[i][j])
                    for (int d = 0; d < ND; d++)
                        sick[nxt][i + dr[d]][j + dc[d]]++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if ((!mask[i][j] && sick[nxt][i][j]) ||
                    (mask[i][j] && sick[nxt][i][j] == ND) ||
                    sick[cur][i][j])
                    sick[nxt][i][j] = 1;
                else
                    sick[nxt][i][j] = 0;
        nxt = 1 - nxt;
        cur = 1 - cur;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += sick[cur][i][j];
    cout << ans << endl;
    return 0;
}
