/*****
题目描述

有两堆石子,两个人轮流去取.每次取的时候,只能从较多的那堆石子里取,并且取的数目必须是较少的那堆石子数目的整数倍.最后谁能够把一堆石子取空谁就算赢.
比如初始的时候两堆石子的数目是25和7
25 7	-->	11 7	-->	4 7	-->	4 3	-->	1 3	-->	1 0
 	选手1取	 	选手2取	 	选手1取	 	选手2取	 	选手1取
最后选手1（先取的）获胜，在取的过程中选手2都只有唯一的一种取法。
给定初始时石子的数目，如果两个人都采取最优策略，请问先手能否获胜。

关于输入

输入包含多数数据。每组数据一行，包含两个正整数a和b，表示初始时石子的数目。
输入以两个0表示结束。

关于输出

如果先手胜，输出"win"，否则输出"lose"

例子输入

34 12
15 24
0 0

例子输出

win
lose

提示信息

假设石子数目为(a,b)且a>=b,如果[a/b]>=2则先手必胜,如果[a/b]<2,那么先手只有唯一的一种取法.
[a/b]表示a除以b取整后的值.
*****/

#include <iostream>
using namespace std;

bool offensiveWin(int a, int b, bool offensive) // a和b对应两堆石子，offensive表示当前是否是先手
{
    if (a < b)  // 保证a >= b
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    if (!b)                 // 若b为0
    {                       // 则上一步已经出现赢家
        if (offensive)
            return false;
        return true;
    }
    if (a / b >= 2)         // 若a比b的两倍多
    {                       // 则当前步为赢家
        if (offensive)
            return true;
        return false;
    }
    return offensiveWin(a - b, b, !offensive);  // 无法判断赢家，按唯一取法取，递归
}

int main()
{
    int a = 0, b = 0;
    while (cin >> a >> b)
    {
        if (!a && !b)
            return 0;
        if (offensiveWin(a, b, true))
            cout << "win" << endl;
        else
            cout << "lose" << endl;
    }
    return 0;
}
