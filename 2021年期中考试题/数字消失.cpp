/*****
题目描述

有一个包含n个整数的序列，序列中每个数都在[1, n]内，[1,n]中的数有些在这个序列中出现了1次或多次，
而有些数没出现过。请输出[1, n]的整数中所有没出现过的整数。其中2 <= n <= 100.

关于输入

输入包括两行：
第1行一个整数n
第2行共n个整数，表示序列中的n个数，相互之间用空格隔开

关于输出

输出若干行，按从小到大的顺序，每行输出一个没出现的整数。

例子输入

7
3 5 1 1 4 3 4

例子输出

2
6
7
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
bool appear[MAX_N] = {false};

int main()
{
    int n = 0, num = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        appear[num] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!appear[i])
            cout << i << endl;
    return 0;
}
