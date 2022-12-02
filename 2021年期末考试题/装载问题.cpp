/*****
题目描述

有一批共 n 个集装箱要装上 2 艘载重量分别为 c1和 c2的轮船，其中集装箱 i 的重量为 wi，
且装载问题要求确定，是否有一个合理的装在方案可将这 n 个集装箱装上这 2 艘轮船。如果有，
找出最优装载方案。

关于输入

输入要输入
1、集装箱数量 类型整型
2、集装箱重量数组 类型整型数组
3、两艘轮船的载重量 类型整型数组
输入格式如：
5
67 34 2 69 24
78 158

关于输出

如果能装载的话输出格式如下：
ok,can load it
a way is:
the first trip load:2 69
the second trip load:67 34 24
如果不能装载的话输出如下：
can't find a way to Loading

例子输入

5
67 34 2 69 24
78 158

例子输出

ok,can load it
a way is:
the first trip load:2 69
the second trip load:67 34 24

提示信息

因为算法的复杂度为 O(2^n)，所以建议在测试时不要用 n 太大的数据。
最优装载问题采用算法：尽量将第一艘轮船装满，然后将剩余的集装箱装到第二艘轮船上。
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int w[MAX_N] = {0};
bool visit[MAX_N] = {false};
int n = 0;

bool best[MAX_N] = {0};
int best_left = 0;

void dfs(int depth, int left)
{
    if (left < 0)
        return;
    if (depth >= n)
    {
        if (left < best_left)
        {
            for (int i = 0; i < n; i++)
                best[i] = visit[i];
            best_left = left;
        }
        return;
    }
    dfs(depth + 1, left);   // Do not load w[depth]
    visit[depth] = true;
    dfs(depth + 1, left - w[depth]);    // Load w[depth]
    visit[depth] = false;
}

int main()
{
    int a = 0, b = 0;
    bool flag = true;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        best_left += w[i];
    }
    cin >> a >> b;
    dfs(0, a);
    for (int i = 0; i < n; i++)
        if (!best[i])
            b -= w[i];
    if (b < 0)
        cout << "can't find a way to Loading" << endl;
    else
    {
        cout << "ok,can load it\na way is:\nthe first trip load:";
        for (int i = 0; i < n; i++)
            if (best[i])
            {
                if (flag)
                    flag = false;
                else
                    cout << " ";
                cout << w[i];
            }
        cout << "\nthe second trip load:";
        flag = true;
        for (int i = 0; i < n; i++)
            if (!best[i])
            {
                if (flag)
                    flag = false;
                else
                    cout << " ";
                cout << w[i];
            }
        cout << endl;
    }
    return 0;
}
