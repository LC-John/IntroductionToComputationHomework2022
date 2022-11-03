/*****
题目描述

菌落的数量对医生来说一直是一个很重要的数据，但是细菌数量太多人工又无法计数，因此你能写个程序帮助医生完成这个任务么？
有一张n*m的菌落的显微镜照片，每个格子是0(表示当前位置无细菌)或者1(表示当前位置是细菌)，请你输出这张照片中菌落的数量。
如果一个细菌，其上下左右四个方向有细菌的话，则这些相邻的细菌属于一个菌落。
例如给定如下照片：
0 0 1 0
0 1 0 1
1 1 0 0
则给出的照片一共有A,B,C三个菌落，如下：
0 0 A 0
0 B 0 C
B B 0 0

关于输入

输入数据第一行两个整数n,m（1<=n,m<=100）,表示照片的长和宽。
接下来n行，每行都有m个用空格隔开的整数（0或者1），表示这一照片行的状态（有无细菌）。

关于输出

输出一个整数，表示该张照片中菌落数量

例子输入

3 5
0 0 1 0 1
0 1 0 1 1
1 1 0 0 1

例子输出

3
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 110
#define ND 4

/** 搜索区域 **/
int arr[MAX_N][MAX_N] = {0};
int n = 0, m = 0;

/** 搜索方向 **/
const int dr[ND] = {0, 0, 1, -1};
const int dc[ND] = {1, -1, 0, 0};

/** 移除当前菌落 **/
void removeGermColony(int r, int c)
{
    if (!arr[r][c])
        return;
    arr[r][c] = 0;
    for (int d = 0; d < ND; d++)
        removeGermColony(r + dr[d], c + dc[d]);
}

int main()
{
    int cnt = 0;
    memset(arr, 0, sizeof(arr));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)        // 下标从1开始，留出周围一圈的缓冲
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (arr[i][j])                  // 每当发现细菌
            {
                cnt++;                      // 菌落计数加1
                removeGermColony(i, j);     // 移除该细菌所属的菌落
            }
    cout << cnt << endl;
    return 0;
}
