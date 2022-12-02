/*****
题目描述

图1是一个城堡的地形图。请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。城堡被分割成
m*n(m≤50，n≤50)个方块，每个方块可以有0~4面墙。

关于输入

程序从标准输入设备读入数据。第一行是两个整数，分别是南北向、东西向的方块数。在接下来的输入行里，
每个方块用一个数字(0≤p≤50)描述。用一个数字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，
8表示南墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两次，方块(1,1)的南墙同时也是
方块(2,1)的北墙。输入的数据保证城堡至少有两个房间。

关于输出

输出分为两行。城堡的房间数、城堡中最大房间所包括的方块数。结果显示在标准输出设备上。

例子输入

4 7
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13

例子输出

5
9
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define ND 4
#define MASK -1

int arr[MAX_N][MAX_N] = {0};
int n_row = 0, n_col = 0;
const int dr[ND] = {0, -1, 0, 1};   // West, North, East, South
const int dc[ND] = {-1, 0, 1, 0};
int n_mask = 0, prev_n_mask = 0;

bool is_wall(int v, int d)
{
    return v & (1 << d);
}

void dfs(int r, int c)
{
    int v = arr[r][c];
    if (v == MASK)
        return ;
    arr[r][c] = MASK;
    n_mask++;
    for (int d = 0; d < ND; d++)
        if (!is_wall(v, d))
            dfs(r + dr[d], c + dc[d]);
}

int main()
{
    int cnt = 0, max_area = 0;
    memset(arr, 0xff, sizeof(arr));
    cin >> n_row >> n_col;
    for (int i = 1; i <= n_row; i++)
        for (int j = 1; j <= n_col; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n_row; i++)
        for (int j = 1; j <= n_col; j++)
            if (arr[i][j] != MASK)
            {
                dfs(i, j);
                cnt++;
                max_area = max(max_area, n_mask - prev_n_mask);
                prev_n_mask = n_mask;
            }
    cout << cnt << endl << max_area << endl;
    return 0;
}
