/*****
题目描述

会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋
盘上（有8 * 8个方格），使它们谁也不能被吃掉！这就是著名的八皇后问题。
对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，其中bi为相应摆法中
第i行皇后所处的列数。已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时
比y小

关于输入

第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)

关于输出

n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串

例子输入

2
1
92

例子输出

15863724
84136275
*****/

#include <iostream>
using namespace std;

#define MAX_B 100
#define N_BOARD 8

int b[MAX_B] = {0}, n_b = 0;        // 皇后串
int board[N_BOARD][N_BOARD] = {0};  // 记录各个位置是否会被吃的棋盘，非0表示会，0表示不会

void set_board(int row, int col, int val)   // 设置棋盘，将(row, col)位置放上后，并将其左下、下、右下的所有格子加1
{
    board[row][col] += val;
    for (int i = row + 1; i < N_BOARD; i++)
        board[i][col] += val;
    for (int i = row + 1, j = col - 1; i < N_BOARD && j >= 0; i++, j--)
        board[i][j] += val;
    for (int i = row + 1, j = col + 1; i < N_BOARD && j < N_BOARD; i++, j++)
        board[i][j] += val;
}

/** 深度优先搜索，产生所有的皇后串 **/
void dfs(int depth, int curr_b)
{
    if (depth >= N_BOARD)   // 深度超过棋盘
    {
        b[n_b++] = curr_b;  // 搜索到一个皇后串，在b中记录
        return;
    }
    curr_b *= 10;   // curr_b向左移一位（十进制）
    curr_b++;       // 加一，因为皇后串的下标需要从1开始
    for (int i = 0; i < N_BOARD; i++)
        if (!board[depth][i])           // 若当前位置可以放置一个皇后
        {
            set_board(depth, i, 1);     // 设置棋盘
            dfs(depth + 1, curr_b + i); // 向下深搜
            set_board(depth, i, -1);    // 棋盘回溯
        }
}

int main()
{
    int n = 0, m = 0;
    dfs(0, 0);
    cin >> n;
    while (n--)
    {
        cin >> m;
        cout << b[m - 1] << endl;
    }
    return 0;
}
