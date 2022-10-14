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
char str[MAX_LEN] = "", rev_str[MAX_LEN] = "";

int main()
{
    cin >> str;
    strcpy(rev_str, str);
    reverse(rev_str, rev_str + strlen(rev_str));
    if (!strcmp(str, rev_str))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
