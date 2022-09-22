/*****
题目描述

辛苦工作一天后，饿坏了的程序员去学五吃鸡排饭。程序员点了n份鸡排。
每个鸡排有两个面，每一面都需要在平底锅上煎1分钟。
不幸的是，厨师只有一个平底锅，在这个平底锅上，一次只能同时烹饪k个
鸡排的一个面。请计算厨师需要花多少时间煎这些鸡排。

关于输入

输入两个整数n和k，空格隔开。(1 ≤ n, k ≤ 1000)

关于输出

输出厨师煎n个鸡排，最少需要的分钟数。

例子输入

3 2

例子输出

3

提示信息

每个鸡排有两个面，每一面都需要煎1分钟。平底锅中即使没有放满k个鸡
排，也需要1分钟时间。
*****/

#include <iostream>
using namespace std;

int fry(int raw, int half, int k, int t)    // raw表示两面都没煎过的鸡排的数量
                                             // half表示只煎了一面的鸡排的数量
                                             // k表示锅中能放的鸡排的数量
                                             // t表示已用时间
{
    if (raw <= 0 && half <= 0)  // 当raw和half都非正
        return t;               // 则所有鸡排都已经煎熟，递归终止

    if (raw < k)                // 若raw放不满一锅，则在锅中剩余部分煎half
    {
        if (half + raw > k)         // 若算上half可以放满一锅
            half -= (k - raw);      // 则从half中去掉煎熟的部分
        else                        // 否则，算上half也放不满一锅
            half = 0;               // half为0
        half += raw;                // raw煎了一面，变为half
        raw = 0;                    // raw为0
    }
    else                        // 否则，raw能放满一锅
    {
        raw -= k;                   // raw去掉一锅的量
        half += k;                  // 这一锅变为half
    }
    return fry(raw, half, k, t + 1);    // 递归
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    cout << fry(n, 0, k, 0) << endl;
    return 0;
}
