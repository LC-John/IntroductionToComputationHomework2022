/*****
题目描述

有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，仅仅在繁殖能力上有显著差别，
A亚种繁殖能力非常强，B亚种的繁殖能力很弱。在一次为时一个小时的细菌繁殖实验中，实验员
由于疏忽把细菌培养皿搞乱了，请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分
成两组。

关于输入

输入有多行，第一行为整数n（n≤100），表示有n个培养皿。
其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。

关于输出

输出有多行：
第一行输出A亚种培养皿的数量，其后每行输出A亚种培养皿的编号，按繁殖率升序排列。
然后一行输出B亚种培养皿的数量，其后每行输出B亚种培养皿的编号，也按繁殖率升序排列。

例子输入

5
1 10 3456
2 10 5644
3 10 4566
4 20 234
5 20 232

例子输出

3
1
3
2
2
5
4

提示信息

亚种内部，细菌繁殖能力差异远远小于亚种之间细菌繁殖能力的差异。
也就是说，亚种间任何两组细菌的繁殖率之差都比亚种内部两组细菌的繁殖率之差大。
*****/

#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 110

struct Group
{
	double grow;
	int id;
} g[MAX_N];

bool cmp(const Group &a, const Group &b)
{
	return a.grow < b.grow || a.grow == b.grow && a.id < b.id;
}

int main()
{
	int n = 0;
	double a = 0, b = 0;
	double avg = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
    {
		cin >> g[i].id;
		cin >> a >> b;
		g[i].grow = b / a;
	}
	sort(g, g + n, cmp);

	avg = (g[0].grow + g[n - 1].grow) / 2;
	int split = 0;
	while (split < n && g[split].grow < avg)
		split++;

	cout << n - split << endl;
	for (int i = split; i < n; i++)
		cout << g[i].id << endl;
	cout << split << endl;
	for (int i = 0; i < split; i++)
		cout << g[i].id << endl;
	return 0;
}
