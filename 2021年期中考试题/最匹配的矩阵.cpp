/*****
题目描述

给定一个矩阵A[m,n](100 ≥ m ≥ 1,100 ≥ n ≥ 1) 和另一个矩阵B[r,s],有0 < r ≤ m, 0 < s ≤ n，A、B所有
元素值都是小于100的正整数。求A中和B最匹配的矩阵C[r,s]，所谓最匹配是指B和C的对应元素差值的绝对值之和最小，
如果有多个最佳匹配只需输出第一个（行号最小，行号相同时，列号最小）。

关于输入

第一行是m和n，以空格隔开
以下m行每行有n个整数，表示A矩阵中的各行
第m+2行为r和s，以空格隔开
以下r行每行有s个整数，表示B矩阵中的各行

关于输出

求出A中和B最匹配的矩阵C并输出之
注意：每一个数字后面都有空格，包括一行中的最后一个数字

例子输入

3 3
3 4 5
5 3 4
8 2 4
2 2
7 3
4 9

例子输出

4 5
3 4
*****/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_SIZE 110
#define MAX_INT 0x7fffffff

int A[MAX_SIZE][MAX_SIZE] = {0};
int B[MAX_SIZE][MAX_SIZE] = {0};

int main()
{
    int m = 0, n = 0, r =  0, s = 0;
    int diff = 0;
    int min_diff = MAX_INT, min_row = -1, min_col = -1;

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    cin >> r >> s;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < s; j++)
            cin >> B[i][j];

    for (int i = 0; i + r <= m; i++)
        for (int j = 0; j + s <= n; j++)
        {
            diff = 0;
            for (int _i = 0; _i < r; _i++)
                for (int _j = 0; _j < s; _j++)
                    diff += abs(A[i + _i][j + _j] - B[_i][_j]);
            // cout << i << " " << j << " " << diff << endl;
            if (diff < min_diff)
            {
                min_diff = diff;
                min_row = i;
                min_col = j;
            }
        }

    for (int i = min_row; i < min_row + r; i++)
    {
        for (int j = min_col; j < min_col + s; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}
