/*****
题目描述

有一个n*n的二维数组，里面存放的数字是0或者1。对于任何一个位置(i,j)，我们定义
(i-1,j)，(i+1,j)，(i,j-1)，(i,j+1)为与其相邻的位置。所有相邻的位置，如果它
们中存放的数字都相同（都是0或者都是1），那么它们构成一个区域。现在请求出给定
的数组中有多少个区域。比如下面的数组中有3个区域，在框中的为一个区域，这个区域
左边和右边又分别有一个区域。
                          +---+
0 1 1 0                  0|1 1|0
                          |   |
0 1 1 0      ----->      0|1 1|0
                          +-+ |
0 0 1 0                  0 0|1|0
                            | +--+
0 0 1 1                  0 0| 1 1|
                            +----+

关于输入

第一行的数字表示有多少组输入。
每组测试样例分为两部分，一行只有一个数n（n<10），用来表示数组的维数，接下来n
行是数组中每一行的值。

关于输出

每行一个输出，表示数组中区域的个数。

例子输入

2
4
0 1 1 0
0 1 1 0
0 0 1 0
0 0 1 1
3
0 1 0
1 1 1
0 1 0

例子输出

3
5

提示信息

可以使用一个备用的数组visited[10][10]，用来记录一个位置是否被访问过。
注意边界问题。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 20
#define ND 4

int arr[MAX_N][MAX_N] = {0};
int n = 0;
const int dr[ND] = {1, -1, 0, 0}, dc[ND] = {0, 0, 1, -1};

void dfs(int r, int c, int val)
{
    if (arr[r][c] != val)
        return;
    arr[r][c] = -1;
    for (int d = 0; d < ND; d++)
        dfs(r + dr[d], c + dc[d], val);
}

int main()
{
    int ans = 0;
    cin >> n;
    while (cin >> n)
    {
        ans = 0;
        memset(arr, 0xff, sizeof(arr));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (arr[i][j] >= 0)
                {
                    dfs(i, j, arr[i][j]);
                    ans++;
                }
        cout << ans << endl;
    }
    return 0;
}
