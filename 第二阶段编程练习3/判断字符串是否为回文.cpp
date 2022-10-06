/*****
题目描述

编程，输入一个字符串，输出该字符串是否回文。

关于输入

输入为一行字符串（字符串中没有空白字符，字符串长度不超过100）。

关于输出

如果字符串是回文，输出yes；否则，输出no。

例子输入

abcdedcba

例子输出

yes

提示信息

回文是指顺读和倒读都一样的字符串。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 1000
char str[MAX_LEN] = "\0", str_rev[MAX_LEN] = "\0";

/** 翻转字符串 **/
void my_strrev(char* s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)   // 交换对称位置的字符
    {
        s[i] ^= s[len - 1 - i];
        s[len - 1 - i] ^= s[i];
        s[i] ^= s[len - 1 - i];
    }
}

int main()
{
    cin >> str;
    strcpy(str_rev, str);   // 将str复制到str_rev中
    //strrev(str_rev);  // 编程网格不支持使用strrev函数，因此只能自己实现一个my_strrev函数用来反转字符串
    my_strrev(str_rev);     // 将str_rev翻转
    if (!strcmp(str_rev, str))  // 比对str和str_rev是否一致
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
