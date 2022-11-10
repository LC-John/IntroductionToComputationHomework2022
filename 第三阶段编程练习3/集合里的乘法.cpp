/*****
题目描述

给定整数集合S和一个目标数T，判断是否可以从S中挑选一个非空子集，子集中的数相乘的乘积为T。

关于输入

输入为两行。
第一行为目标数T和S中的元素个数N，以空格隔开。
第二行为S中的N个元素，以空格隔开。
其中 N <= 16。

关于输出

如果可以，则输出YES，否则输出NO。

例子输入

Sample Input 1:
12 5
1 2 3 4 5

Sample Input 2:
33 5
4 2 8 7 5

例子输出

Sample Output 1:
YES

Sample Output 2:
NO
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

int s[MAX_N] = {}, n = 0;

/** 深度优先搜索 **/
bool dfs(int t, int depth)  // t为目标乘积，depth为搜索深度
{
    if (t == 1)         // t为1，说明目标已经达成
        return true;    // 返回true
    if (depth >= n)     // depth超过n，说明目标无法达成
        return false;   // 返回false
    if (dfs(t, depth + 1))  // 不用s[depth]来达成目标
        return true;
    if (s[depth] && !(t % s[depth]) && dfs(t / s[depth], depth + 1))    // 用s[depth]来达成目标，需要考虑0的情况
        return true;
    return false;
}

int main()
{
    int t = 0;
    cin >> t >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    if (dfs(t, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
