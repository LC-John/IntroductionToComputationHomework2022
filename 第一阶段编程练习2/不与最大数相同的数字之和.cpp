/*****
题目描述

输出一个整数数列中不与最大数相同的数字之和

关于输入

输入分为两行：
第一行为N(N为接下来数字的个数，N<=100)；
第二行为N个整数，以空格隔开；

关于输出

输出为N个数中除去最大数其余数字之和。（注意，最大数可能出现多次）

例子输入

3
1 2 3

例子输出

3
*****/

#include <iostream>
using namespace std;

#define MIN_INF 0x80000000  // 宏定义最小的数

int main()
{
    int n = 0;          // 输入个数
    int num = 0;        // 当前输入数字
    int sum = 0;        // 当前输入过的数字之和
    int _max = MIN_INF; // 当前最大数，默认为int类型最小值
    int n_max = 0;      // 当前最大数出现过的次数，默认为0次

    cin >> n;
    while(n--)
    {
        cin >> num;
        sum += num;         // 更新数字和
        if (num > _max)     // 若当前输入数字大于此前最大数
        {                   // 则需要
            _max = num;     // 更新最大数字
            n_max = 1;      // 并重置最大数字出现过的次数为1
        }
        else if (num == _max)   // 若当前输入数字等于此前最大数
            n_max++;            // 则最大数出现次数计数加一
    }
    cout << sum - _max * n_max << endl; // 所有数字和-最大数字*出现的次数
    return 0;
}
