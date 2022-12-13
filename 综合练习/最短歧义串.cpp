/*****
题目描述

对于一个字符串,如果我们可以用两种不同的办法把它切分成单词的序列,那么我们说这个字
符串是有歧义的.比如iskill,可以切分成is和kill,也可以切分成i和skill.
现在给你一个单词表,请你构造出在这个单词表上的最短歧义串,即这个串可以用两种方案切
分成单词表中的单词,要求歧义串尽可能短.

关于输入

第一行是一个整数n(n<=100)表示词表的大小.
接下来n行,每行一个单词,只包含数字和小写字母,长度不超过20.

关于输出

输出最短歧义串,如果最短歧义串有多种可能,请输出字典序最小的那一个.

例子输入

4
i
is
kill
skill

例子输出

iskill
*****/

#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

#define MAX_N 110

string dict[MAX_N] = {""};  // Word dictionary
unordered_set<string> h;    // Hash
queue<string> q;            // BFS queue
int n = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> dict[i];

    /** BFS **/
	q.push("");
	while (!q.empty())
    {
        for (int i = 0; i < n; i++)
            if (h.find(q.front() + dict[i]) != h.end()) // Already in h
            {
                cout << q.front() + dict[i] << endl;    // Output & return
                return 0;
            }
            else                                        // Otherwise
            {
                h.insert(q.front() + dict[i]);          // Insert into h & push into q
                q.push(q.front() + dict[i]);
            }
        q.pop();
    }
	return 0;
}
