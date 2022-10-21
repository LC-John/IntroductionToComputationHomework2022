/*****
题目描述

商家喜欢拥有容易记忆的电话号码。让电话号码容易被记住的一种方式是让它能够拼成一个单词或者短语。
例如，你可以通过容易记住的单词TUT-GLOP拨叫University of Waterloo。有时只有号码的一部分能够用
来拼写单词。当你今晚回到酒店你可以通过拨打310-GINO来从Gino's订一份pizza。另外一种让电话号码容
易被记住的方法是把号码分组。你可以从Pizza Hut订pizza，用含有三个十的号码3-10-10-10.
电话号码的标准格式是七个十进制数字，第三个和第四个数字之间有一个连接符（例如：888-1200）。电话
拨号盘提供字母到数字的映射。
A, B, 和C 映射到 2
D, E, 和F 映射到 3
G, H, 和I 映射到 4
J, K, 和L 映射到 5
M, N, 和O 映射到 6
P, R, 和S 映射到 7
T, U, 和V 映射到 8
W, X, 和Y 映射到 9
Q和Z没有映射到任何数字，连字符不需要拨号，可以任意添加和删除。 TUT-GLOP的标准格式是888-4567，
310-GINO的标准格式是310-4466，3-10-10-10的标准格式是310-1010。
如果两个号码有相同的标准格式，那么他们就是等同的（相同的拨号）
你的公司正在为本地的公司编写一个电话号码薄。作为质量控制的一部分，你想要检查是否有两个和多个公
司拥有相同的电话号码。

关于输入

输入的格式是，第一行正整数指定电话号码薄中号码的数量（最多100000）。余下的每行是一个电话号码。
每个电话号码由数字，大写字母（除了Q和Z）以及连接符组成

关于输出

对于每个出现重复的号码产生一行输出，输出是号码的标准格式紧跟一个空格然后是它的重复次数。如果存
在多个重复的号码按照号码的字典升序输出。如果没有重复的号码，输出一行：
No duplicates.

例子输入

12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

例子输出

310-1010 2
487-3279 4
888-4567 3
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 10000100

int cnt[MAX_N];

int map2num(char c)
{
	if (c <= '9' && c >= '0')
		return c - '0';
	else if (c >= 'A' && c <= 'P')
		return (c - 'A') / 3 + 2;
	else if (c >= 'R' && c <= 'Y')
		return (c - 'Q') / 3 + 7;
    return -1;
}

int main()
{
	int k = 0;
	bool flag = true;
	char s[100];
	cin >> k;
	memset(cnt, 0, sizeof(cnt));
	while (k--)
    {
		cin >> s;
		int l = strlen(s);
		int num = 0;
		for (int i = 0; i < l; ++i)
		{
			if (s[i] == '-')
				continue;
			num = num * 10 + map2num(s[i]);
		}
		cnt[num]++;
	}

	for (int i = 0; i < MAX_N; ++i)
	{
		if (cnt[i] <= 1)
			continue;
		int tmp = i;
		for (int j = 0; j < 4; ++j)
		{
			s[j] = tmp % 10 + '0';
			tmp /= 10;
		}
		s[4] = '-';
		for (int j = 5; j < 8; ++j)
		{
			s[j] = tmp % 10 + '0';
			tmp /= 10;
		}
		s[8] = '\0';
		reverse(s, s + 8);
		cout << s << ' ' << cnt[i] << endl;
		flag = false;
	}
	if (flag)
        cout << "No duplicates." << endl;
	return 0;
}
