/*****
题目描述

输入三个整数,输出最大的数。

关于输入

输入为一行，共三个整数。

关于输出

输出为最大的整数。

例子输入

10 20 56

例子输出

56
*****/

#include <iostream>
using namespace std;

#define MIN_INF 0x80000000

int main()
{
    int _max = MIN_INF, num = 0;
    while (cin >> num)
        if (num > _max)
            _max = num;
    cout << _max << endl;
    return 0;
}
