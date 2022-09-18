/*****
题目描述

鲁宾逊先生有一只宠物猴，名叫多多。这天，他们两个正沿着乡间小路散步，突然发现路边的告示牌上贴着一
张小小的纸条：“欢迎免费品尝我种的花生！??熊字”。
鲁宾逊先生和多多都很开心，因为花生正是他们的最爱。在告示牌背后，路边真的有一块花生田，花生植株整
齐地排列成矩形网格（如图1）。有经验的多多一眼就能看出，每棵花生植株下的花生有多少。例如在图2中的
花生田里，只有位于(2, 5), (3, 7), (4, 2), (5, 4)的植株下长有花生，个数分别为13, 7, 15, 9。我们
假定多多在每个单位时间内，可以做下列四件事情中的一件：(1)从路边跳到最靠近路边（即第一行）的某棵
花生植株；(2)从一棵植株跳到前后左右与之相邻的另一棵植株；(3)采摘一棵植株下的花生；(4)从最靠近路
边（即第一行）的某棵花生植株跳回路边。
为了训练多多的算术，鲁宾逊先生说：“你先找出花生最多的植株，去采摘它的花生；然后再找出剩下的植株
里花生最多的，去采摘它的花生；依此类推，不过你一定要在我限定的时间内回到路边。” 例如在图2中，沿
着图示的路线，多多在21个单位时间内，最多可以采到37个花生。
现在给定一块花生田的大小和花生的分布，请问在限定时间内，多多最多可以采到多少个花生？注意可能只有
部分植株下面长有花生，假设这些植株下的花生个数各不相同。

关于输入

输入第一行代表组数T。
之后每组第一行包括三个整数，M, N和K，用空格隔开；表示花生田的大小为M * N（1 <= M, N <= 20），多多
采花生的限定时间为K（0 <= K <= 1000）个单位时间。接下来的M行，每行包括N个非负整数，也用空格隔开；
第i + 1行的第j个整数Pij（0 <= Pij <= 500）表示花生田里植株(i, j)下花生的数目，0表示该植株下没有花
生。

关于输出

输出包括T组，每一行代表一组，只包含一个整数，即在限定时间内，多多最多可以采到花生的个数。

例子输入

2
6 7 21
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0
6 7 20
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0

例子输出

37
28
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 40

struct _LOC
{
	int r;
	int c;
	int num;
} peanut[MAX_N * MAX_N];

bool compare (_LOC a, _LOC b)
{
	return a.num > b.num;
}

int main()
{
	int kase;
	cin >> kase;
	while (kase--)
    {
        int np = 0;
        int remain = 0, value = 0;
		int now_r = -1, now_c = 0;
		int m, n, time;

	    cin >> m >> n >> time;
	    for (int i = 0; i < m; i++)
	    	for (int j = 0; j < n; j++)
            {
                int num;
	    		cin >> num;
	    		if (num)
                {
                    peanut[np].num = num;
                    peanut[np].r = i;
                    peanut[np].c = j;
                    np++;
                }
			}
		sort(peanut, peanut + np, compare);

		now_c = peanut[0].c;
        remain = time;
		for (int i = 0; i < np - 1 && remain >= abs(peanut[i].r- now_r) + abs(peanut[i].c - now_c) + 1 + peanut[i].r + 1; i++)
        {
			remain -= (abs(peanut[i].r - now_r) + abs(peanut[i].c - now_c) + 1);
			now_r = peanut[i].r;
			now_c = peanut[i].c;
			value += peanut[i].num;
		}
		cout << value << '\n';
	}
	return 0;
}
