/*****
题目描述

给定三个整数，求这三个数中最大值与最小值之差。

关于输入

只有一行，包括待处理的三个整数。

关于输出

一共一行，输出最大数减去最小数的差。

例子输入

3 5 9

例子输出

6

提示信息

三个数中可能出现相等的情况
*****/

#include <iostream>
using namespace std;

#define MIN_INF 0x80000000  // 宏定义最小的数，为int类型表示范围的下限，即十六进制的0x80000000
#define MAX_INF 0x7FFFFFFF  // 宏定义最大的数，为int类型表示范围的上限，即十六进制的0x7FFFFFFF

int main()
{
    int n = 3, num = 0;
    int _min = MAX_INF; // 当前最小值，初始化为MAX_INF（任何输入的数都比MAX_INF小或相等）
    int _max = MIN_INF; // 当前最大值，初始化为MIN_INF（任何输入的数逗比MIN_INF大或相等）
    for (int i = 0; i < n; i++)
    {
        cin >> num;     // 读入当前数字
        if (num < _min) // 若当前数字小于此前的最小值
            _min = num; // 则更新最小值
        if (num > _max) // 同理，若当前数字大于此前的最大值
            _max = num; // 则更新最大值
        /**
        cout << _min << " " << _max << endl;    // 可以通过cout来进行简单的断点调试
        **/
    }
    cout << _max - _min << endl;
    return 0;
}
