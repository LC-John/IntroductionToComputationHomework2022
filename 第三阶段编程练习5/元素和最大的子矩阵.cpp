/*****
题目描述

输入一个n级方阵，请找到此矩阵的一个子矩阵，此子矩阵的各个元素的和是所有子矩阵中最大的，输出这个子矩阵及这个最大的和。

关于输入

首先输入方阵的级数n，
然后输入方阵中各个元素。

关于输出

输出子矩阵，
最后一行输出这个子矩阵的元素的和。

例子输入

4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

例子输出

9 2
-4 1
-1 8
15
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
#define MIN_INT 0x80000000

int arr[MAX_N][MAX_N] = {0};
int sum[MAX_N][MAX_N] = {0};    // sum[i][j]存放arr[i][j]左上方的子矩阵的和（包括arr[i][j]点）
int n = 0;

int main()
{
    int st_r = 0, st_c = 0, end_r = 0, end_c = 0, max_sum = MIN_INT;
    int num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            sum[i][j] = sum[i][j - 1] + arr[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] += sum[i - 1][j];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            for (int _r = r + 1; _r <= n; _r++)
                for (int _c = c + 1; _c <= n; _c++)
                {
                    num = sum[_r][_c] - sum[r][_c] - sum[_r][c] + sum[r][c];    // 左上点为arr[r+1][j+1]，右下点为arr[i][j]的子矩阵的和
                    if (num > max_sum)
                    {
                        st_r = r + 1;
                        st_c = c + 1;
                        end_r = _r;
                        end_c = _c;
                        max_sum = num;
                    }
                }
    for (int i = st_r; i <= end_r; i++)
    {
        cout << arr[i][st_c];
        for (int j = st_c + 1; j <= end_c; j++)
            cout << " " << arr[i][j];
        cout << endl;
    }
    cout << max_sum << endl;
    return 0;
}
