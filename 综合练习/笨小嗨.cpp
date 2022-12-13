/*****
题目描述

笨小嗨的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，
用这种方法去选择选项的时候选对的几率非常大！
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数
最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小嗨就认为这是个Lucky Word，这样的单
词很可能就是正确的答案。

关于输入

输入只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。

关于输出

输出共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否
则输出“No Answer”；(注意：不包含引号)
第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。

例子输入

error

例子输出

Lucky Word
2

提示信息

单词error中出现最多的字母r出现了3次，出现次数最少的字母出现了1次，3-1=2，2是质数。
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_C 300
#define MAX_L 110
#define MAX_INT 0x7fffffff

int cnt[MAX_C] = {0};
char s[MAX_L] = "";

bool is_prime(int n)
{
    if (!n || n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

int main()
{
    int maxn = 0, minn = MAX_INT;
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
        cnt[s[i]]++;
    for (int i = 0; i < MAX_C; i++)
        if (cnt[i])
        {
            maxn = max(maxn, cnt[i]);
            minn = min(minn, cnt[i]);
        }
    if (is_prime(maxn - minn))
        cout << "Lucky Word" << endl << maxn - minn << endl;
    else
        cout << "No Answer" << endl << 0 << endl;
    return 0;
}
