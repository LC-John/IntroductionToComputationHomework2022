/*****
题目描述

佩奇的期末考试马上就要开始了, 但是他没有足够的勇气报名参加, 为了帮助佩奇,她的小伙伴给
她准备一台勇气获得机。初始的时候佩奇的勇气值是0, 勇气获得机有两个按钮:
1、N按钮: 如果当期拥有的勇气值为x, 按下之后勇气值将变为2*x+1，
2、G按钮: 如果当前拥有的勇气值为x, 按下之后勇气值将变为2*x+2，
勇气值过高也会膨胀,所以佩奇需要将自己的勇气值恰好变为n, 请你帮助她设计一个勇气获得机的
按键方案使妞妞的勇气值恰好变为n。

关于输入

输入包括一行, 包括一个正整数n(1 <= n <= 100000), 表示佩奇最后需要的勇气值。

关于输出

输出一行字符串, 每个字符表示该次佩奇选择按动的按钮,'N'表示该次按动N按钮,'G'表示该次按
动G按钮。

例子输入

20

例子输出

NGNG
*****/

#include <iostream>
using namespace std;

#define MAX_N 100000

char action[MAX_N] = "";    // 搜索到的动作序列

/** 深度优先搜索 **/
bool brave_machine(int depth, int target, int current)  // depth为当前搜索深度，target为目标勇气值，current为当前勇气值
{
    /** 首先考虑递归终止的情况 **/
    if (current == target)  // 当current等于target，说明搜索完成，找到需要的动作序列
        return true;        // 递归终止，返回true
    if (current > target)   // 当current大于target，说明当前动作序列已经超过目标值，舍弃当前动作序列
        return false;       // 递归终止，返回false

    /** 深度优先搜索 **/
    action[depth] = 'N';    // 第depth个动作若为'N'，向下搜索，尝试是否可行
    if (brave_machine(depth + 1, target, current * 2 + 1))  // 若递归返回为true，说明该动作可行
        return true;                                        // 直接return，跳出搜索
    action[depth] = 'G';    // 第depth个动作不是'N'，尝试'G'，向下搜索
    if (brave_machine(depth + 1, target, current * 2 + 2))  // 同上，若返回true，说明动作可行
        return true;                                        // return跳出搜索
    action[depth] = '\0';   // 第depth个动作不能是'N'或'G'，说明前序动作有误，恢复depth动作为初始化的'\0'
    return false;           // 返回false
}

int main()
{
    int target = 0;
    cin >> target;
    brave_machine(0, target, 0);    // DFS递归
    cout << action << endl;
    return 0;
}
