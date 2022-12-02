/*****
题目描述

有个财主收藏了大量的宝物。为防止被盗，他将宝物藏在离家不太远一个海岛上的不同洞穴内，有些洞内放
了一件宝物，有些洞存放了多件，并绘制了藏宝图。但藏宝图不慎被一个海盗发现，他详细知道了每件宝物
所在的洞穴。好在财主事先做了进一步的防范措施：万一有人进入一个洞内窃取宝物，最多只能取走洞内的
一件宝物，而且不能让其再进入同一个洞内。海盗决定驾着他的小船去盗宝，但船承载货物的重量受限。已
知每件宝物的重量和价值，请你根据船的载重量，推算海盗在每个洞只能进去一次的情况下，这一趟盗走宝
物可能导致财主最大价值的损失是多少？

关于输入

第一行两个整数m,n（1<=m,n<=1000），分别是船的载货重量（海盗自身的重量忽略不计）和宝物总件数。
两个整数以空格间隔
接下来n行，每行3个数，分别表示各件宝物的重量、价值和所在洞的编号。均为整数，且以空格间隔。

关于输出

一个整数值，为所盗宝物可能的最大总价值。

例子输入

30 3
15 8 1
10 5 1
48 400 2

例子输出

8
*****/

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_C 10000
#define MAX_N 10000

int w[MAX_C][MAX_N] = {0};      // w[i][j] weight of j-th treasure in i-th cave
int v[MAX_C][MAX_N] = {0};      // v[i][j] value of j-th treasure in i-th cave
int cave[MAX_N] = {0};          // Treasure number in each cave
int dp[MAX_C][MAX_N] = {0};

int main()
{
    int m = 0, n = 0;
    int max_cave = 0;
    int a= 0, b = 0, c = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
    {
		cin >> a >> b >> c;
		max_cave = max(max_cave, c);
		w[c][cave[c]] = a;
		v[c][cave[c]] = b;
		cave[c]++;
	}

	/** Init **/
	for (int i = 1; i <= max_cave; i++)
		for (int j = 0; j < cave[i]; j++)
			for (int k = w[i][j]; k <= m; k++)
				dp[i][k] =max(v[i][j], dp[i][k]);

    /** DP **/
	for (int i = 0; i <= m; ++i)
		for (int j = 1; j <= max_cave; ++j)
			for (int k = 0; k < cave[j]; ++k)
				if (i >= w[j][k])
                {
					dp[j][i] = max(dp[j][i], dp[j - 1][i - w[j][k]] + v[j][k]);
					dp[j][i] = max(dp[j][i], dp[j - 1][i]);
				}
				else
					dp[j][i] = max(dp[j - 1][i],dp[j][i]);
	cout << dp[max_cave][m] << endl;
}
