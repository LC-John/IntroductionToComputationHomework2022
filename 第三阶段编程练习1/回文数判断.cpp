/*****
题目描述

给定一个正整数（不超过9位），判断其是否为回文数。所谓回文数是指正向看与逆向看相等的数。
如，123454321，12344321。若是，输出yes,若不是，输出no

关于输入

一个正整数

关于输出

若是，输出yes
若不是，输出no

例子输入

135797531

例子输出

yes
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 100

char num[MAX_LEN] = "\0", rev_num[MAX_LEN] = "\0";

int main()
{
    cin >> num;             // 输入字符串num
    strcpy(rev_num, num);   // 将num拷贝到rev_num中
    reverse(rev_num, rev_num + strlen(rev_num));    // 翻转rev_num
    if (!strcmp(rev_num, num))  // 对比num和rev_num
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
