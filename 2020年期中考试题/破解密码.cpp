/*****
题目描述

考虑一种加密方式，它需要一个任意长度的原文 m 和秘钥 key，其中要求原文和秘钥只包含大
写和小写的英文字符。
首先定义字符之间的加密，用字符 a 去加密字符 b 的结果是：
1. 首先把 a 和 b 转成数字 x 和 y。转换的规则是，小写字母 a 到 z 依次对应 0 到 25，
大写字母依次对应 26 到 51。
2. 计算 x 和 y 的和 z，对 52 取模，即计算 (x + y) % 52。
3. 返回数字 z 对应的字符。
现在来讲如何用秘钥 key 来加密原文 m：
1. 如果秘钥的 key 的长度小于 m，那么不停重复 key 直到长度不小于 m 为止。举例来说，如
果原文是 beijing，秘钥是 PKUSAA，那么秘钥需要被重复称 PKUSAAPKUSAA。
2. 假设原文的长度是 n，那么对于每一个 1~n 的数字 i，都用 key 的第 i 个字符去加密 m
的第 i 个字符。
3. 返回结果。
那么用 PKUSAA 去加密 beijing 的结果就是：QOcbINV
现在火山哥有 n 个字符串，s[1] 到 s[n]，他对这些字符串做了 m 次加密操作：第 i 次加密操
作用第 s[x[i]] 去加密 s[y[i]]，并把 s[y[i]] 替换成加密结果。
现在依次给出 m 次加密操作，以及加密操作结束后每一个字符串的模样，你可以还原出这 n 个
字符串原来的模样吗？

关于输入

第一行输入两个整数 n,m (1 <= n,m <= 1000)。
接下来 m 行每行输入两个整数 x[i],y[i]，表示依次加密操作，保证 x[i] 不等于 y[i]。
接下来 n 行每行输入一个字符串，表示加密最后的结果。字符串的长度在 1 到 100 之间，只包
含大小写英文字符。

关于输出

输出 n 行，每行一个字符串，表示原本的字符串。

例子输入

2 1
1 2
PKUSAA
QOcbINV

例子输出

PKUSAA
beijing
*****/

#include <iostream>
using namespace std;

#define MAX_N 1010
#define MAX_L 110

int xi[MAX_N], yi[MAX_N];
char str[MAX_N][MAX_L];

int letter2digit(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else
        return c - 'A' + 26;
}

char digit2letter(int x)
{
    x = (x + 52) % 52;
    if (x >= 26)
        return 'A' + x - 26;
    else
        return 'a' + x;
}

char rev(char a, char b_)
{
	return digit2letter(letter2digit(b_) - letter2digit(a));
}

void crack(int a, int b)
{
	for (int i = 0, j = 0; str[b][j] != '\0'; i++, j++)
    {
		if (str[a][i] == '\0')
			i = 0;
		str[b][j] = rev(str[a][i], str[b][j]);
	}
}


int main()
{
	int n, m;
	while (cin >> n >> m)
    {
		for (int i = 0; i < m; ++i)
			cin >> xi[i] >> yi[i];
		for (int i = 0; i < n; ++i)
			cin >> str[i];
		for (int i = m - 1; i >= 0; --i)
			crack(xi[i] - 1, yi[i] - 1);
		for (int i = 0; i < n; ++i)
			cout << str[i] << endl;
	}
	return 0;
}
