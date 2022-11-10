/*****
题目描述

在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在
棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。

关于输入

输入含有多组测试数据。
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数
目。 n <= 8 , k <= n
当为-1 -1时表示输入结束。
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空
白行或者空白列）。

关于输出

对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。

例子输入

2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1

例子输出

2
1
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10
#define AVAILABLE '#'
#define EMPTY '.'

char board[MAX_N][MAX_N] = {""};                                        // 棋盘
int n = 0, ans = 0;                                                     // n为棋盘大小，ans为搜索结果
bool r[MAX_N] = {false}, c[MAX_N] = {false};                            // 记录行（r）或列（c）是否放过棋子
int x[MAX_N * MAX_N] = {0}, y[MAX_N * MAX_N] = {0}, n_available = 0;    // 记录棋盘上所有可行位置

/** 深度优先搜索 **/
void dfs (int step,int chess)   // step记录搜索到哪个可行位置，chess记录还有几个棋子要放
{
    if (chess <= 0) // 若没有棋子要放了
    {
    	ans++;      // 则找到一种可行的放置方案，ans加1
    	return;     // 返回
	}
	if (step >= n_available)    // 若没有可行位置了
        return;                 // 则直接返回

	dfs(step + 1, chess);               // step位置不放，向后搜索
	if (!r[x[step]] && !c[y[step]])     // 若step位置可以放置
	{
		r[x[step]] = true;              // 则先设置r和c的标签
		c[y[step]] = true;
		dfs(step + 1, chess - 1);       // 向后搜索
		r[x[step]] = false;             // 搜索结束后，恢复r和c的标签
		c[y[step]] = false;
	}
}
int main ()
{
    int k = 0;
	while (cin >> n >> k)
    {
        if (n < 0 && k < 0)
            return 0;

        /** 初始化 **/
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		ans = 0;
		n_available = 0;

        /** 读入棋盘，记录所有可行的位置 **/
		for (int i = 0;i < n; i++)
			for (int j = 0;j < n; j++)
            {
				cin >> board[i][j];
				if (board[i][j] == AVAILABLE)
				{
					x[n_available] = i;
					y[n_available++] = j;
				}
			}

        /** 深度优先搜索 **/
		dfs(0, k);
		cout << ans << endl;
	}
	return 0;
}
