/*****
题目描述

某乒乓球场里有很多张球桌,其中有一张由极品材料制作而成,大家都喜欢租这张球桌打球。
由于租的人太多,每年开张第一天,这张球桌的订单就如雪片一样飞来。这些订单中预订的时
间从开张第一天一直到过年关门的那一天都有，更让老板为难的是：这些订单中总是有很多
的时间冲突，接受了一张订单可能就有好些订单必须得拒绝。
现在，老板又在为这些订单犯愁了，某人很不厚道地向他透露了你精通动态规划算法的消息，
于是老板二话没说把订单全扔给了你，请你为他选择接受一些订单使得获益最大。
对你来说，小菜一碟，不是么？:)

关于输入

第一行是一个正整数n(1<=n<=100000)，表示订单的数目。
接下来n行，每行表示一份订单，包含三个非负整数s,t和c，其中s,t表示订单预订的时间段
及从时刻s到时刻t(0 <= s < t < = 2100000000)，c表示客户愿意为这份订单出多少钱。

关于输出

输出只包含一个整数，表示采用最优方案时老板能够获益多少(答案不超过32位有符号整数所
能表示的范围）。

例子输入

3
0 2 2
2 4 4
1 3 5

例子输出

6

提示信息

对于样例：接受第1份和第2份订单，获益是6，如果接受第3份订单，获益是5，所以答案应该是6
本题时间复杂度应为O(nlogn)
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100100
#define MAX_INT 0x7fffffff

struct Range
{
    int l;
    int r;
    int v;
} o[MAX_N];
int n = 0, dp[MAX_N] = {0};

bool cmp(Range &a, Range &b)
{
    if (a.r == b.r)
        return a.l < b.l;
    return a.r < b.r;
}

int bin_search(int st, int l, int r)    // Binary search
{
    int m = (l + r) / 2;
    if (o[m].r <= st && o[m + 1].r > st)
        return m;
    if (l == m || o[m].r <= st)
        return bin_search(st, m + 1, r);
    return bin_search(st, l, m - 1);
}

int main()
{
    int ans = 0, idx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> o[i].l >> o[i].r >> o[i].v;
    sort(o + 1, o + n + 1, cmp);    // O(n log n)
    for (int i = 1;i <= n; i++)
    {
        idx = bin_search(o[i].l, 0, i); // O(log n), repeat n times. Therefore O(n log n)
        dp[i] = max(dp[i - 1], dp[idx] + o[i].v);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
