/*****
题目描述

要过新年了，小明想给许多同学购买礼物，选好礼物结账时发现带的钱不够，所以只能选择留下一部分。
每个要送礼物的同学在他心中有个优先级，小明决定优先级最大的优先购买，他为每个人挑选的礼物价格
不同，下面请你算出小明能给多少人买到礼物。

关于输入

输入有N+1行，第一行两个数字，选的礼物总数N和带的钱的总数M，后面N行每行包含两个数字，第一个数
字表示礼物的价格P，第二个数字表示这个礼物要送的人在他心中的优先级L，越大越优先购买，优先级不
能相同（N<100  M<1000  P<100  L<200   N,M,P,L均为整数）

关于输出

输出一行，能买的礼物个数

例子输入

5 10
2 4
6 3
1 5
7 2
1 1

例子输出

3

提示信息

若优先级最高的礼物价格超出带的钱总数，视为不能购买任何礼物（优先级较高的人没有，则不会考虑给
优先级低的买）
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 110

struct Gift
{
    int pri;    // 优先级
    int val;    // 价值
} g[MAX_N] = {{0, 0}};

bool cmp(const Gift& a, const Gift& b)
{
    return a.pri > b.pri;
}

int main()
{
    int n = 0, m = 0, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i].val >> g[i].pri;
    sort(g, g + n, cmp);
    for (int i = 0; i < n; i++)
        if (g[i].val <= m)
        {
            ans++;
            m -= g[i].val;
        }
        else
            break;
    cout << ans << endl;
    return 0;
}
