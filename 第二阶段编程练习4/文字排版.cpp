/*****
题目描述

给一段英文短文，单词之间以空格分隔（每个单词应包括其前后紧邻的标点符号）。请将短文重新排版，要求如下：
每行不超过80个字符；每个单词居于同一行上；在同一行的单词之间以一个空格分隔；行首和行尾都没有空格。

关于输入

第一行是一个整数n，表示英文短文中单词的数目. 其后是n个以空格分隔的英文单词（单词包括其前后紧邻的标点符号，且每个单词长度都不大于40个字母）。

关于输出

排版后的多行文本，每行文本字符数最多80个字符，单词之间以一个空格分隔，每行文本首尾都没有空格。

例子输入

84
One sweltering day, I was scooping ice cream into cones and told my four children they could "buy" a cone from me for a hug. Almost immediately, the kids lined up to make their purchases. The three youngest each gave me a quick hug, grabbed their cones and raced back outside. But when my teenage son at the end of the line finally got his turn to "buy" his ice cream, he gave me two hugs. "Keep the changes," he said with a smile.

例子输出

One sweltering day, I was scooping ice cream into cones and told my four
children they could "buy" a cone from me for a hug. Almost immediately, the kids
lined up to make their purchases. The three youngest each gave me a quick hug,
grabbed their cones and raced back outside. But when my teenage son at the end
of the line finally got his turn to "buy" his ice cream, he gave me two hugs.
"Keep the changes," he said with a smile.
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100
#define MAX_N 1000

char s[MAX_N][MAX_LEN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int curidx = 0;
	for (int i = 0; i < n; ++i)
    {
		int l = strlen(s[i]);
		if (curidx + l + 1 <= 80)
		{
			if (curidx != 0)
            {
				cout << ' ';
				curidx += 1;
			}
			cout << s[i];
			curidx += l;
		}
        else
		{
			cout << endl << s[i];
			curidx = l;
		}
	}
	return 0;
}
