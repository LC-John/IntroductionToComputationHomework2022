/*****
题目描述

假设某国际发行了n种不同面值的邮票，并且规定每张信封上最多只允许贴m张邮票。连续邮资问
题要求对于给定的n和m的值，给出邮票面值的最佳设计，使得可在一张信封上贴出从邮资1开始，
增量为1的最大连续邮资区间。例如当n＝5和m＝4时，面值为（1，3，11，15，32）的5种邮票可
以贴出邮资的最大连续邮资区间是1到70。

关于输入

输入数据每一行给出2个正整数n和m的值（1<=n，m<=9），最后以0 0 表示文件结束。

关于输出

对于输入中每一行的正整数n和m，将最大连续邮资区间输出。

例子输入

5 4
0 0

例子输出

70
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 10
#define MAX_VAL 1000

int val[MAX_N] = {1};
int q[MAX_VAL] = {0};
int h[MAX_VAL] = {0};
int n = 0, m = 0;
int ans = 0;

int bfs()
{
    /** Init **/
    int tail = 0, head = 0;
    memset(h, 0x00, sizeof(h));
    q[head++] = 0;
    /** BFS **/
    for (int s = 0; head > tail && s < m; s++)
    {
        int _head = head;
        while (_head > tail)
        {
            for (int j = 0; j < n; j++)
            {
                if (!val[j])
                    break;
                int tmp = q[tail] + val[j];
                if (!h[tmp])
                {
                    h[tmp] = 1;
                    q[head++] = tmp;
                }
            }
            tail++;
        }
    }
    /** Find max **/
    int ret  = 1;
    while (h[++ret]);
    return ret - 1;
}

void dfs(int depth, int cur_max)
{
    if (depth >= n)
    {
        ans = max(ans, cur_max);
        return;
    }
    for (int v = val[depth - 1] + 1; v <= cur_max + 1; v++)
    {
        val[depth] = v;
        dfs(depth + 1, bfs());
        val[depth] = 0;
    }
}

int main()
{
    while(cin >> n >> m)
    {
        if (!n && !m)
            return 0;
        dfs(1, m);
        cout << ans << endl;
    }
    return 0;
}
