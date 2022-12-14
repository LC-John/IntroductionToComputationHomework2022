/*****
题目描述

有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的四
块瓷砖中的黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

关于输入

包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。
在接下来的H行中，每行包括W个字符。每个字符表示一块瓷砖的颜色，规则如下
‘.’：黑色的瓷砖
‘#’：红色的瓷砖
‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中仅出现一次
当在一行中读入的是两个零时，表示输入结束。

关于输出

对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。

例子输入

6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0

例子输出

45
59
6
13
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N   100
#define BLACK   '.'
#define RED     '#'
#define STAND   '@'
#define ND      4

/** 搜索区域 **/
char arr[MAX_N][MAX_N] = {"\0"};
int H = 0, W = 0;

/** 搜索方向 **/
const int dw[ND] = {0, 0, 1, -1};
const int dh[ND] = {1, -1, 0, 0};

/** 深度优先遍历 **/
int dfsCount(int h, int w)
{
    int ret = 0;
    if (arr[h][w] == RED)   // 若当前格子为RED
        return ret;         // 则直接返回0
    arr[h][w] = RED;        // 将当前位置标记为RED
    ret++;                  // ret计数加1
    for (int d = 0; d < ND; d++)                // 探索四个方向
        ret += dfsCount(h + dh[d], w + dw[d]);  // 每个方向返回的结果加到计数ret上
    return ret;
}

int main()
{
    int sh = 0, sw = 0;
    while (cin >> W >> H)
    {
        if (!W && !H)
            return 0;
        memset(arr, RED, sizeof(arr));
        for (int i = 1; i <= H; i++)
            for (int j = 1; j <= W; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == STAND)
                {
                    sh = i;
                    sw = j;
                }
            }
        cout << dfsCount(sh, sw) << endl;
    }
    return 0;
}
