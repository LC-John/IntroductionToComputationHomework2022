/*****
题目描述

中午是幼儿园水果时间，老师会给每个小朋友发水果。教室为一个矩形区域，共有N 排，
每排M个工位。老师通常按照逆时针方向螺旋发水果。已知每个座位有一个数字，表示该
小朋友的学号，每个学号各不相同。已知老师从（0, 0）位置开始，按照逆时针螺旋的
顺序发水果，请输出收到水果的小朋友的学号序列。

关于输入

第一行 两个数， 数组行列 N，M
接下来 N 行，每行 M 个正整数，表示每个位置的员工工号
1 ≤ N ≤ 15
1 ≤ M ≤ 15

关于输出

发放水果学号序列

例子输入

3 3
1 2 3
4 5 6
7 8 9

例子输出

1 4 7 8 9 6 3 2 5
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 20
#define ND 4

int n_row = 0, n_col = 0;
int arr[MAX_N][MAX_N] = {0};
const int dr[ND] = {1, 0, -1, 0}, dc[ND] = {0, 1, 0, -1};

int main()
{
    int r = 1, c = 1, cnt = 0, d = 0;
    memset(arr, 0xff, sizeof(arr));
    cin >> n_row >> n_col;
    for (int i = 1; i <= n_row; i++)
        for (int j = 1; j <= n_col; j++)
            cin >> arr[i][j];
    while (cnt < n_row * n_col)
    {
        if (cnt)
            cout << " ";
        cout << arr[r][c];
        arr[r][c] = -1;
        cnt++;
        if (arr[r + dr[d]][c + dc[d]] < 0)
            d = (d + 1) % ND;
        r = r + dr[d];
        c = c + dc[d];
    }
    return 0;
}
