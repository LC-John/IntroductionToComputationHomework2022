/*****
题目描述

将两个其他进制的数求和，并以某进制的方式输出
(最大为 16进制，超出9的数字分别用 a、b、c、d、e、f表示)

关于输入

输入共三行，第一行两个数，一个为进制数，一个为该进制的数值
第二行和第一行含义相同
第三行为输出的进制数

关于输出

输出为两个数的和，并以要求的进制打印

例子输入

5 3
9 8
16

例子输出

b
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_LEN 100

/** k进制字符串转换为十进制数 **/
long long k2ten(char* num, int k)
{
    long long ret = 0;
    for (int i = 0; num[i] != '\0'; i++)
        if (num[i] >= '0' && num[i] <= '9')
            ret = ret * k + (num[i] - '0');
        else
            ret = ret * k + (num[i] - 'a' + 10);
    return ret;
}

/** 十进制数转换为k进制字符串 **/
void ten2k(long long num, int k, char* ret)
{
    int idx = 0;
    memset(ret, 0, sizeof(char) * strlen(ret));
    while (num > 0)
    {
        if (num % k < 10)
            ret[idx++] = num % k + '0';
        else
            ret[idx++] = num % k - 10 + 'a';
        num /= k;
    }
    reverse(ret, ret + strlen(ret));    // 翻转整个ret字符串
}

char str[MAX_LEN] = "\0";

int main()
{
    long long val = 0;
    int k = 0;
    cin >> k >> str;
    val = k2ten(str, k);
    cin >> k >> str;
    val += k2ten(str, k);
    cin >> k;
    ten2k(val, k, str);
    cout << str;
    return 0;
}
