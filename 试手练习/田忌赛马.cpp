/*****
题目描述

你一定听过田忌赛马的故事吧？
如果3匹马变成1000匹，齐王仍然让他的马按从优到劣的顺序出赛，田忌可以按任意顺序选择他的赛马出赛。赢一局，
田忌可以得到200两银子，输一局，田忌就要输掉200两银子，平局的话不输不赢。
请问田忌最多能赢多少银子?

关于输入

输入包含多组测试数据.
每组测试数据的第一行是一个整数n(1<=n<=1000),表示田忌和齐王都拥有n匹马。接下来一行是n个整数，表示田忌
的马的速度，下一行也是n个整数，表示齐王的马的速度。

输入的最后以一个0表示结束。

关于输出

对每组数据，输出一个整数，表示田忌至多可以赢多少银子，如果田忌赢不了，就输出一个负数，表示田忌最少要输
多少银子。

例子输入

3
92 83 71
95 87 74
2
20 20
20 20
2
20 19
22 18
0

例子输出

200
0
0
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define UNIT 200
#define MAX_N 1010

int ji[MAX_N] = {0}, king[MAX_N] = {0};
int n = 0;

int main()
{
    int ji_fast_idx = 0, ji_slow_idx = 0;
    int king_fast_idx = 0, king_slow_idx = 0;
    int bonus = 0;
    while (cin >> n)
    {
        if (!n)
            return 0;
        ji_fast_idx = n - 1;
        ji_slow_idx = 0;
        king_fast_idx = n - 1;
        king_slow_idx = 0;
        bonus = 0;

        for (int i = 0; i < n; i++)
            cin >> ji[i];
        for (int i = 0; i < n; i++)
            cin >> king[i];
        sort(ji, ji + n);
        sort(king, king + n);

        while(n--)
            if (ji[ji_slow_idx] < king[king_slow_idx])  // King defeats Ji's slowest with King's fastest
            {
                bonus -= UNIT;
                ji_slow_idx++;
                king_fast_idx--;
            }
            else if (ji[ji_slow_idx] > king[king_slow_idx]) // Ji defeats King's slowest with his own slowest
            {
                bonus += UNIT;
                ji_slow_idx++;
                king_slow_idx++;
            }
            else if (ji[ji_fast_idx] > king[king_fast_idx]) // Ji defeats King's fastest with his own fastest
            {
                bonus += UNIT;
                ji_fast_idx--;
                king_fast_idx--;
            }
            else if (ji[ji_slow_idx] < king[king_fast_idx]) // King defeats Ji's slowest with King's fastest
            {
                bonus -= UNIT;
                ji_slow_idx++;
                king_fast_idx--;
            }
            else    // King's fastest vs. Ji's slowest. Tie.
            {
                ji_slow_idx++;
                king_fast_idx--;
            }
        cout << bonus << endl;
    }
    return 0;
}
