/*****
题目描述

石头剪子布是一种很简单的游戏：
石头胜剪子
剪子胜布
布胜石头
A和B猜拳，已知他们出拳的序列，编程求出谁胜谁负。

关于输入

第一行是一个正整数n(n<200)，表明A和B一共猜了n次拳。
接下来是n行，每行有两个数字，分别表示A和B在这次猜拳中出了什么。0表示石头，1表示剪刀，2表示布。

关于输出

输出一行，"A"表示A胜，"B"表示B胜，"Tie"表示平局。

例子输入

4
1 0
2 2
1 2
2 0

例子输出

A
*****/

#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int n_a_win = 0;
    int a = 0, b = 0;

    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        switch((a - b + 3) % 3) // 使用求模化简情况
        {
        case 1:         // A输B赢，包括A1B0、A2B1、A0B2
            n_a_win--;
            break;      // 注意使用break跳出switch语句，否则将顺序执行后面的程序
        case 2:         // A赢B输，包括A0B1、A1B2、A2B0
            n_a_win++;
            break;      // break跳出
        case 0:         // 平局，包括A0B0，A1B1，A2B2
        default:        // switch语句必须有default作为默认入口
                        // 由于平局和default的程序行为是一致的，因此可以合并
            ; // 空语句，无事发生...
        }
    }
    if (n_a_win > 0)
        cout << "A" << endl;
    else if (n_a_win < 0)
        cout << "B" << endl;
    else
        cout << "Tie" << endl;
    return 0;
}
