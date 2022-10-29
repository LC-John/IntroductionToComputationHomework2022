/*****
题目描述

海上有一个岛，在环海边上建有一条环岛高速公路，沿着公路有n（5 < n < 10000）个居民点，假设每个居民点有一个编号，
从0开始，按顺时针依次从小到大（即，0,1，…，n-1）编号。在岛上啤酒很受青睐。某啤酒企业计划在岛上投资建一个啤酒厂
，并根据啤酒需求每天向居住点送啤酒。已知两个相邻的居民点的距离以及每个居住点每天的啤酒需求量（假设每个居住点每天
不超过2000桶）。假定每单位长度的路程送一桶啤酒需要的费用恒定（为单位费用）。请问，选择哪一个居民点建啤酒厂，才能
使每天送啤酒的费用最小（空车不计费用）。

关于输入

第一行：为居民点数目n
后面为n行，每行为一个居民点的啤酒需求量以及按顺时针离下一个居民点的距离（均为整数,空格间隔），从编号为0的开始，按
单增顺次给出。
注意：后面第n行对应于居民点（n-1)的啤酒需求量以及到编号为0的居民点距离。

关于输出

啤酒厂所在的居民点编号以及每天的运输费用，其间以逗号间隔

例子输入

6
500 10
300 30
350 25
400 60
700 28
200 35

例子输出

0,94100
*****/

#include <iostream>
using namespace std;

#define MAX_N 10010
#define MAX_INT 0x7fffffff

int demand[MAX_N] = {0};
int next_dis[MAX_N] = {0};
int dis[MAX_N][MAX_N] = {0};
int n = 0, dis_total = 0;

int main()
{
    int min_idx = -1, min_cost = MAX_INT;
    int d = 0, cost = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> demand[i] >> next_dis[i];
        dis_total += next_dis[i];
    }

    for (int i = 0; i < n; i++)
    {
        d = 0;
        for (int j = 1; j < n; j++)
        {
            d += next_dis[(i + j - 1) % n];
            if (d < dis_total - d)
                dis[i][(i + j) % n] = dis[(i + j) % n][i] = d;
            else
                dis[i][(i + j) % n] = dis[(i + j) % n][i] = dis_total - d;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cost = 0;
        for (int j = 0; j < n; j++)
            cost += dis[i][j] * demand[j];
        if (cost < min_cost)
        {
            min_cost = cost;
            min_idx = i;
        }
    }
    cout << min_idx << ',' << min_cost << endl;
    return 0;
}
