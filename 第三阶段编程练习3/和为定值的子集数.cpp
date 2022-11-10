/*****
题目描述

已知 n 个正整数，wi  (1≤i≤n) 形成一个集合 W={w1,w2,...,wn}，集合中的元素彼此不相同。
给定某个正整数 M ，集合W中可否存在子集，该子集的所有元素之和和恰好为M，问：这样的子集有
多少个？
例如，4个正整数为：
11 13 24 7
若给定M=31，则有两个子集{7,11,13}和{7,24}
于是，这样的子集有 2 个。

关于输入

第1行，输入若干个正整数，表示集合的元素，各整数之间以空格间隔；
后面有多行，每行表示一个 M 值；若某行的 M 值为0，则结束。

关于输出

对应的每个有效的 M 值，输出相应行的子集数目

例子输入

11 13 24 7
31
24
45
55
0

例子输出

2
2
0
1
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 5000

int w[MAX_N] = {0}, n = 0;  // 集合
int ans = 0;                // 搜索结果

/** 深度优先搜索 **/
void dfs(int step, int val) // step为当前需要考虑的数字，val为要达成的求和目标
{
    if (val <= 0)   // 若值小于等于0
    {               // 搜索结束
        if (!val)   // 若值为0
            ans++;  // 说明搜索到一个子集，ans加1
        return;
    }
    if (step >= n)  // 若step大于等于n
        return;     // 同样搜索结束
    dfs(step + 1, val);             // 不算step，递归搜索
    dfs(step + 1, val - w[step]);   // 算上step，递归搜索
}

int main()
{
    char c = '\0';
    int m = 0;

    /** 读入数据并排序 **/
    while (cin >> w[n++])
    {
        cin.get(c);
        if (c == '\n')
            break;
    }
    sort(w, w + n); // 排序可以一定程度上加快搜索过程

    while (cin >> m)
    {
        if (!m)
            return 0;
        ans = 0;
        dfs(0, m);
        cout << ans << endl;
    }
    return 0;
}
