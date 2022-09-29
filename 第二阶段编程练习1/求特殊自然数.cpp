/*****
题目描述

一个十进制自然数,它的七进制与九进制表示都是三位数，且七进制与九进制的三位数码表示顺序正好相反。
编程求此自然数,并输出显示.
输入为1时，输出此自然数的十进制表达式；输入为2时，输出此自然数的七进制表达式；输入为3时，输出
此自然数的九进制表达式。

关于输入

输入为1，2，3中的一个数。

关于输出

输出一行。

输出为十进制或七进制或九进制数

例子输入

1

例子输出
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 5
#define MIN_NUM 100                     // 最小的三位数
#define MAX_NUM 6 * 7 * 7 + 6 * 7 + 6   // 最大的三位数（七进制下的666，用十进制表示）

char* get_digit(int num, int base)
{
    char *digit = new char[MAX_LEN];                // new字符数组用作返回值
    int l = 0;
    memset(digit, 0x00, MAX_LEN * sizeof(char));    // 用'\0'字符初始化整个字符数组
    /** 倒序取出base进制下各位数码 **/
    while(num)
    {
        digit[l++] = num % base + '0';
        num /= base;
    }
    /** 恢复数码顺序 **/
    for (int i = 0; i < l / 2; i++)
    {
        digit[i] ^= digit[l - 1 - i];
        digit[l - 1 - i] ^= digit[i];
        digit[i] ^= digit[l - 1 - i];
    }
    return digit;
}

int main()
{
    int option = 0;
    cin >> option;
    for (int num = MIN_NUM; num <= MAX_NUM; num++)
    {
        char *num_7 = get_digit(num, 7);    // 取出七进制数
        char *num_9 = get_digit(num, 9);    // 取出九进制数
        bool flag = true;
        for (int i = 0; i < 3; i++)         // 比对数码
            if (num_7[i] != num_9[2 - i])
            {
                flag = false;
                break;
            }
        if (flag)
        {
            switch (option)
            {
            case 1: cout << num << endl; break;
            case 2: cout << num_7 << endl; break;
            case 3: cout << num_9 << endl; break;
            default: break;
            }
            return 0;
        }
        delete[] num_7;     // 删除new出的七进制字符串
        delete[] num_9;     // 删除new出的九进制字符串
    }
    return 0;
}
