/*****
题目描述

给定一个row行col列的整数数组array，要求从array[0][0]元素开始，按回形从外向内顺时针顺序遍历整个数组。如图所示：


关于输入

输入的第一行上有两个整数，依次为row和col。
余下有row行，每行包含col个整数，构成一个二维整数数组。
（注：输入的row和col保证0<row<100, 0<col<100）

关于输出

按遍历顺序输出每个整数。每个整数占一行。

例子输入

4 4
 1  2  3 4
12 13 14 5
11 16 15 6
10  9  8 7

例子输出

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
#define MASK 0x7fffffff
#define N_DIR 4

int arr[MAX_N][MAX_N] = {0};

/** 旋转输出的移动方向，0->1->2->3->0->...依次变化循环 **/
int dx[N_DIR] = {0, 1, 0, -1};  // 行的变化量
int dy[N_DIR] = {1, 0, -1, 0};  // 列的变化量

int main()
{
    int n = 0, m = 0;   // 矩阵大小
    int i = 0, j = 0;   // 当前位置坐标
    int _i = 0, _j = 0; // 下一位置坐标

    /** 读入数据 **/
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    /** 回形旋转输出 **/
    for (int cur = 0, d = 0; cur < n * m; cur++)
    {
        /** 输出当前位置 **/
        cout << arr[i][j] << endl;
        arr[i][j] = MASK;   // 将输出过的位置的数标记为MASK
        /** 计算下一个输出的位置 **/
        _i = i + dx[d];     // 计算下一位置坐标
        _j = j + dy[d];
        if (_i < 0 || _i >= n || _j < 0 || _j >= m || arr[_i][_j] == MASK)  // 若计算出的下一位置不合法
        {
            d = (d + 5) % 4;                                                // 则方向改变
            _i = i + dx[d];                                                 // 重新计算下一位置坐标
            _j = j + dy[d];
        }
        i = _i; // 更新位置
        j = _j;
    }
    return 0;
}
