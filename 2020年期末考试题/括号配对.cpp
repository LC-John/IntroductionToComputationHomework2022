/*****
题目描述

小凡同学在学习C语言时无意间发现括号的配对是件很有意思的事。对于不同数量的括号，
似乎有很多种不同但是合法的组合方式。对于小凡给出的括号总对数N，你能告诉他总共
有多少种不同的括号组合方式吗？

关于输入

输入有一行，为括号的总对数N，N为不超过10的正整数。

关于输出

按左括号优先的顺序排列出所有合法的组合方式。

例子输入

3

例子输出

((()))
(()())
(())()
()(())
()()()
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 100

void dfs(int cnt, int n, char *cur, int l)
{
    if (!n && !cnt)
    {
        cout << cur << endl;
        return;
    }
    if (cnt < n)
    {
        cur[l] = '(';
        dfs(cnt + 1, n, cur, l + 1);
        cur[l] = '\0';
    }
    if (cnt)
    {
        cur[l] = ')';
        dfs(cnt - 1, n - 1, cur, l + 1);
        cur[l] = '\0';
    }
}

int main()
{
    int n = 0;
    char cur[MAX_LEN] = "";
    cin >> n;
    dfs(0, n, cur, 0);
    return 0;
}
