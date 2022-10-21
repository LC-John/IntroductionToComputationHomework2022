/*****
题目描述

在一个N×N的棋盘上下五子棋，给定一个五子棋黑白棋的落子序列 (x0,y0),(x1,y1), ..., （xn,yn），判断走到多少步时，哪方获胜。

关于输入

第一行有两个整数，棋盘的大小N和落子序列的长度n。
其余各行每行两个数字，分别表示黑棋或白棋棋子在棋盘上的位置。
定输入一定合理的，而且一定能分出输赢，但因为对弈双方没有判断出输赢而多行了数步。

关于输出

输出为一行，包含两个整数，第一个整数是判断出输赢时行棋的步数，第二个数字表示获胜方。如果黑方获胜，输出0；如果白方获胜，输出1。

例子输入

10 12
0 0
1 0
0 1
2 0
0 2
3 0
0 3
4 0
0 4
5 0
0 5
6 0

例子输出

9 0

提示信息

五子棋规则比较复杂，这里我们只要求黑棋先行，谁先连出至少5连子就算赢，不管是否出现规则中约束的禁手。每局棋都有胜负结果。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000
#define BLACK '$'
#define WHITE '*'
#define EMPTY '#'

char arr[MAX_N][MAX_N] = {""};
int N = 0;

void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j];
        cout << endl;
    }
}

bool check_win(int r, int c)
{
    const int nd = 4;
    const int n_win = 5;
    int cnt = 0;
    int dr[nd] = {0, 1, 1, 1};
    int dc[nd] = {1, 0, 1, -1};
    // print();
    for (int d = 0; d < nd; d++)
    {
        cnt = 1;
        for (int _r = r + dr[d], _c = c + dc[d];
              _r >= 0 && _r < N && _c >= 0 && _c < N && arr[_r][_c] == arr[r][c];
              _r += dr[d], _c += dc[d], cnt++);
        for (int _r = r - dr[d], _c = c - dc[d];
              _r >= 0 && _r < N && _c >= 0 && _c < N && arr[_r][_c] == arr[r][c];
              _r -= dr[d], _c -= dc[d], cnt++);
        if (cnt >= n_win)
            return true;
    }
    return false;
}

int main()
{
    int n = 0, r = 0, c = 0;
    char curr = BLACK;
    bool finish = false;
    memset(arr, EMPTY, sizeof(arr));
    cin >> N >> n;
    for (int step = 1; step <= n; step++)
    {
        cin >> r >> c;
        if (finish)
            continue;
        arr[r][c] = curr;
        if (check_win(r, c))
        {
            cout << step;
            switch(curr)
            {
                case BLACK: cout << " 0" << endl; break;
                case WHITE: cout << " 1" << endl; break;
                default: break;
            }
            finish = true;
        }
        switch(curr)
        {
                case BLACK: curr = WHITE; break;
                case WHITE: curr = BLACK; break;
                default: break;
        }
    }
    return 0;
}
