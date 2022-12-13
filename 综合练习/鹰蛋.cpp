/*****
题目描述

有一个教授有一批一模一样的鹰蛋。有一天他来到了一栋楼的脚下，他突然想知道自己的鹰蛋从这栋楼
的多少层扔下时恰好不碎。
一颗鹰蛋如果从i层摔下没有碎，那么从小于j层摔下也不会碎，如果从j层摔下碎了，从大于j层摔下也
会摔碎。如果恰好存在一层n，从n层摔下鹰蛋未碎，而从n+1层摔下碎了，那么这批鹰蛋恰好从n层摔下
未碎。如果从第一层摔下碎了，那么称恰好从0层摔下未碎；另一方面，如果从最高层（N层）摔下未碎，
那么称恰好从N层摔下未碎
这个教授想知道从第多少层恰好摔下不碎，但是这个教授想使用最少的试验次数来得到这个值。
现已知鹰蛋的个数M和楼层高度N，试问在最坏情况下，这个教授最少需要试验多少次来得到他想要的结
果？
比如：M为1，N为3。那么这个教授为了得到结果，就必须从一层一层测试，在最坏情况下，最少需要3
次试验。但是如果M=2,N=3，那么他就可以第一次从二层扔下，不管碎了还是没碎，他都只需再扔一次
即可得到结果，即需要做2次试验即可。

关于输入

有多组输入，每一组输入单独一行。
分别为两个如题所述的正整数N（大于0小于400001），M （大于0小于N+1）中间用空格隔开。
如果得到的N和M都为0，表示输入结束。

关于输出

每组输出单独一行，输出需要试验的次数K。

例子输入

100 1
100 2
0 0

例子输出

100
14

提示信息

动态规划，由于输入量比较大，最好尽量优化算法。。
*****/

#include <iostream>
using namespace std;

#define MAX_F 400010
#define MAX_TRIAL 30

int F = 0, E = 0;
int dp[MAX_F][MAX_TRIAL] = {0};

int main()
{
	for (int i = 0; i < MAX_TRIAL; ++i)
		dp[1][i] = i;
	for (int i = 2; i < MAX_F; ++i)
		for (int cnt = 1; cnt <= 25; ++cnt)
			dp[i][cnt] = 1 + dp[i - 1][cnt - 1] + dp[i][cnt - 1];
	while (cin >> F >> E)
    {
		if (!F && !E)
			break;
		if (E == 1)
        {
            cout << F << endl;
            continue;
        }
        for (int i = 0; i < MAX_TRIAL; i++)
            if (dp[E][i] >= F)
            {
                cout << i << endl;
                break;
            }
	}
	return 0;
}
