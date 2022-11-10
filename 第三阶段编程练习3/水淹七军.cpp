/*****
题目描述

随着最后通牒的递出，C国的总攻也开始了，由于C国在地形上的优势，C国总司令下令采用水攻，剿灭A国最后的有生力量。
地形图是一个M*N的矩阵，矩阵上每一个点都对应着当前点的高度。C国总司令将选择若干个点进行放水（放水……这个词很
好很强大嘛……）。根据水往低处流的特性，水可以往四个方向的流动，被淹的地方的水面高度便和放水点的高度一样。然
而，A国不是一马平川的，所以总会有地方是淹没不到的。你的任务很简单，判断一下A国司令部会不会被淹没掉。
我们将给你完整的地形图，然后给出A国司令部所在位置，给出C国将在哪几个点进行放水操作。你所需要的，就是给出A国
司令部会不会被水淹。如果被水淹了，那么就意味着，战争结束了，否则，战争也会结束（八成被水包围了）……

关于输入

第一行：一个整数K，代表数据组数。
对于每一组数据：
第1行：符合题目描述的两个整数，M(0 < M <= 200)、N(0 < N <= 200)。
第2行至M+1行：每行N个数，以空格分开，代表这个矩阵上的各点的高度值H(0<=H<=1000)。
第M+2行：两个整数I(0 < I <= M)、J(0 < J <= N)，代表司令部所在位置。
第M+3行：一个整数P(0 < P <= M * N)，代表放水点个数。
第M+4行至M+P+4行：每行两个整数X(0 < X <= M)、Y(0 < Y <= N)，代表放水点。

关于输出

对于每组数据，输出一行，如果被淹则输出Yes，没有则输出No。

例子输入

1
5 5
1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1
3 3
2
1 1
2 2

例子输出

Yes
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000
#define ND 4

int arr[MAX_N][MAX_N] = {};     // 高度矩阵
bool visit[MAX_N][MAX_N] = {};  // 记录各个位置是否淹没的矩阵
int m = 0, n = 0;               // 棋盘大小
int tr = 0, tc = 0;             // 司令部位置
int dr[ND] = {0, 0, 1, -1}, dc[ND] = {1, -1, 0, 0}; // 水流动的方向

/** 深度优先搜索 **/
void dfs(int sr, int sc, int h)
{
    if (sr <= 0 || sc <= 0 || sr > m || sc > n)     // 非法位置
        return;                                     // 终止
    if (arr[sr][sc] > h)    // 当前位置高于放水高度
        return;             // 终止
    if (visit[sr][sc])      // 当前位置已经被淹没
        return;             // 终止
    visit[sr][sc] = true    // 淹没当前位置;
    for (int d = 0; d < ND; d++)
        dfs(sr + dr[d], sc + dc[d], h);     // 向所有方向搜索
}

int main()
{
    int _n = 0, n_spot = 0;
    int r = 0, c = 0;
    cin >> _n;
    while (_n--)
    {
        memset(visit, 0x00, sizeof(visit));

        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];
        cin >> tr >> tc >> n_spot;
        while (n_spot--)
        {
            cin >> r >> c;
            dfs(r, c, arr[r][c]);
        }
        if (visit[tr][tc])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
