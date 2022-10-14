/*****
题目描述

有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。
在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间
不会传染。请输出第m天得流感的人数。

关于输入

第一行一个数字n，n不超过100，表示有n*n的宿舍房间。
接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间
住着得流感的人。
接下来的一行是一个整数m，m不超过100.

关于输出

输出第m天，得流感的人数

例子输入

5
....#
.#.@.
.#@..
#....
.....
4

例子输出

16
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1010
#define HEA '.'
#define EMP '#'
#define ILL '@'
#define TOBEILL '$'

char room[MAX_N][MAX_N] = {""};
int n = 0;

void infect()
{
    const int nd = 4;
    int di[nd] = {1, -1, 0, 0};
    int dj[nd] = {0, 0, 1, -1};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (room[i][j] == ILL)
                for (int d = 0; d < nd; d++)
                    if (room[i + di[d]][j + dj[d]] == HEA)
                        room[i + di[d]][j + dj[d]] = TOBEILL;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (room[i][j] == TOBEILL)
                room[i][j] = ILL;
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << room[i][j];
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int d = 0, cnt = 0;
    memset(room, EMP, sizeof(char) * MAX_N * MAX_N);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> room[i][j];
    cin >> d;
    while (--d)
    {
        infect();
        // print();
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (room[i][j] == ILL)
                cnt ++;
    cout << cnt << endl;
    return 0;
}
