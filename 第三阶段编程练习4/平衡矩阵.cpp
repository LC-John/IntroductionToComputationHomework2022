/*****
题目描述

现在有一个n阶正整数方阵（n<=7），现在可以对矩阵的任意一行进行左移，具体操作为：每次对于
某一行a_i1,a_i2,…,a_in进行一次左移，最左边的元素移动到这一行的末尾，其他元素均向左移动
一位，即变为a_i2,a_i3,…,a_in,a_i1。对某一行可以执行任意次的左移。
现在我们的目标是：通过对矩阵的每一行进行若干次左移，使得矩阵中每列和的最大值最小。

关于输入

输入包含多组数据。
对于每组数据，第一行为一个正整数n（1<=n<=7），代表矩阵的阶。接下来的n行，每行n个正整数
（不超过10000），代表这个矩阵。
输入数据以一个-1为结尾代表输入结束。

关于输出

对于每组数据，输出一行一个正整数，为最小的最大列和。

例子输入

2
4 6
3 7
3
1 2 3
4 5 6
7 8 9
-1

例子输出

11
15
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 10
#define MAX_INT 0x7fffffff

int arr[MAX_N][MAX_N] = {0}, n = 0;     // 矩阵
int sum[MAX_N] = {0};                   // 各列之和

/** 左移arr中的row那一行，并更新sum **/
void shift_left(int row)
{
    for (int j = 0; j < n; j++)
        sum[j] -= arr[row][j];
    reverse(arr[row], arr[row] + n);        // arr[0],arr[1],...,arr[n-1] => arr[n-1],arr[n-2],...,arr[0]
    reverse(arr[row], arr[row] + n - 1);    // arr[n-1],arr[n-2],...,arr[0] => arr[1],arr[2],...,arr[n-1],arr[0]
    for (int j = 0; j < n; j++)
        sum[j] += arr[row][j];
}

/** 深度优先搜索 **/
int dfs(int depth)
{
    if (depth >= n)
        return *max_element(sum, sum + n);  // max_element返回sum到sum+n中（左闭右开）最大的元素的地址
    int ret = dfs(depth + 1);       // 本行不左移，直接向下递归
    for (int i = 1; i < n; i++)
    {
        shift_left(depth);                  // 本行左移
        ret = min(ret, dfs(depth + 1));     // 向下递归，保留最小值
    }
    return ret;
}

int main()
{
    while(cin >> n)
    {
        if (n < 0)
            return 0;
        memset(sum, 0x00, sizeof(sum));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                sum[j] += arr[i][j];
            }
        cout << dfs(0) << endl;
    }
    return 0;
}
