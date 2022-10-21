/*****
题目描述

有一种游戏，在纸上画有很多小方格，第一个方格为起点(S)，最后一个方格为终点。有一个棋子，
初始位置在起点上，棋子每次可移动一次，棋子在起点时，可向前移动一个格子到第二个方格内；棋
子在其他方格内时，可根据方格内的数字Ni进行移动。如果Ni大于零，就向前移动Ni个格子；如果Ni
小于零，就向后移动-Ni个格子；如果Ni等于零，则此次原地不动一次，在下一步移动时可向前移动
一步到下一个格子。显然，如果仅按此方案，会出现棋子永远移动不到终点的情形。为防止这种情况
发生，我们规定，当棋子再次来到它曾经到过的方格时，它需要原地不动一次，在下一步移动时可向
前移动一步到下一个格子。按此方案，棋子总能够走到终点(F)。如果给定一个方格图，试求棋子要
走多少步才能从起点走到终点。（注：当然还可能会出现向前移动Ni个格子就跑过终点了，则把棋子
放到终点上。如果Ni太小，使得棋子向后移动跑过了起点，则把棋子放到起点上。）（如图所示，其
中S代表起点，F代表终点）（只有离开后再次来到一个方格时，才算来到它曾经到过的方格，包括起
点S）

关于输入

第一行为所有中间格子的总数n（n<20）（即加上起点小格子和终点小格子，共有n+2个小格子）。
其余各行上分别为一个整数，表示对应的小格子上的初始数字。

关于输出

输出一行，要从起点跳到终点，共要跳多少步。
（注：每跳一步，可能跳过多个格子，也可能原地不动。)

例子输入

5
2
3
-2
0
-5

例子输出

19

提示信息

只有离开后再次来到一个方格时，才算来到它曾经到过的方格，包括起点S
如果有疑问可再读一遍题干！
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

int board[MAX_N] = {0}, visit[MAX_N] = {0}, n = 0;

void print(int curr)
{
    for (int i = 0; i <= n; i++)
    {
        if (i == curr)
            cout << "<";
        cout << board[i];
        if (i == curr)
            cout << ">";
        cout << "(" << visit[i] << ")" << " ";
    }
    cout << endl;
}

int play(int step, int curr)
{
    //print(curr);
    if (curr >= n)
        return step;
    if (curr < 0)
        curr = 0;
    if (visit[curr])
        return play(step + 2, curr + 1);
    visit[curr]++;
    if (!board[curr])
        return play(step, curr + board[curr]);
    return play(step + 1, curr + board[curr]);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> board[i];
    board[0] = 1;
    n++;
    cout << play(0, 0) << endl;
    return 0;
}
