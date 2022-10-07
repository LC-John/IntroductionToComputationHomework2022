/*****
题目描述

两个单词 s 和 w ，判断 s 出现在 w 中第一次出现的位置。

关于输入

输入只有一行，第一个词 s 和第二个单词 w ，单词之间以一个空格分隔。每个字符串的长度都小于50。并且输入保证s一定是w的一个子串。

关于输出

输出也只有一行，s 在 w 中出现的位置。

例子输入

it waiter

例子输出

2
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100

int main()
{
    char s[MAX_LEN] = "\0", w[MAX_LEN] = "\0";
    cin >> s >> w;
    cout << strstr(w, s) - w;   // strstr直接寻找子串
    return 0;
}
