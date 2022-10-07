/*****
题目描述

输入一个二维 (5*5)数组，每行只有一个最大值，每列只有一个最小值。
如果存在鞍点，则输出鞍点所在的位置（行和列），不存在鞍点时，要输出“not found”。
鞍点指的是数组中的一个元素，它是所在行的最大值，并且是所在列的最小值。
例如：在下面的例子中（第4行第1列的元素就是鞍点，值为8 ）。
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25

关于输入

输入包含一个5行5列的矩阵

关于输出

如果存在鞍点，输出鞍点所在的行、列及其值，如果不存在，输出"not found"

例子输入

11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8  6 4 7 2
15 10 11 20 25

例子输出

4 1 8
*****/

#include <iostream>
using namespace std;

#define N 5
#define MAX_INT 0x7fffffff
#define MIN_INT 0x80000000

int arr[N + 1][N + 1] = {0};    // 储存矩阵
int row_max_idx[N + 1] = {0};   // 每一行的最大值所在的列
int col_min_idx[N + 1] = {0};   // 每一列的最小值所在的行

int main()
{
    bool flag = false;

    /** 初始化 **/
    for (int i = 1; i <= N; i++)
    {
        arr[i][0] = MIN_INT;    // 每一行的0列放置MIN_INT
        arr[0][i] = MAX_INT;    // 每一列的0行放置MAX_INT
    }

    /** 读入数据 **/
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] > arr[i][row_max_idx[i]]) // 若当前数大于当前行的最大值
                row_max_idx[i] = j;                 // 则更新当前行的row_max_idx
            if (arr[i][j] < arr[col_min_idx[j]][j]) // 若当前数小于当前列的最小值
                col_min_idx[j] = i;                 // 则更新当前列的col_min_idx
        }

    /** 寻找鞍点并输出 **/
    for (int i = 1; i <= N; i++)
        if (col_min_idx[row_max_idx[i]] == i)
        {
            flag = true;
            cout << i << " " << row_max_idx[i] << " " << arr[i][row_max_idx[i]] << endl;
            return 0;
        }
    if (!flag)
        cout << "not found" << endl;
    return 0;
}
