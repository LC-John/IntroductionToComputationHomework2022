/*****
题目描述

药学院附属小学于2018年将编程正式加入校园课程，要求所有课程均要结合编程进行教学，于是，老师药驰盖给同学们
布置了一道家庭作业，要求利用编程，统计出一串乱码中的大写字母个数，小写字母个数以及数字个数，但药老师自己
不会编程，所以麻烦你帮忙写一份作为标准答案。

关于输入

一行长度为n的英文字母（0 < n <=256）

关于输出

一行，大写字母个数，小写字母个数以及数字个数，均为整数，两数之间用一个空格隔开

例子输入

AbCdEf gHiJkL 123456

例子输出

6 6 6

提示信息

输入的乱码中包含空格
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 1000

#define OTHER 0     // 不是字母或数字
#define UPPER 1     // 大写字母
#define LOWER 2     // 小写字母
#define DIGIT 3     // 数字

/** 检查字符是大小写数字、数字还是其他 **/
int check_char(char c)
{
    if (c >= 'A' && c <= 'Z')
        return UPPER;   // 返回UPPER，即1
    if (c >= 'a' && c <= 'z')
        return LOWER;   // 返回LOWER，即2
    if (c >= '0' && c <= '9')
        return DIGIT;   // 返回DIGIT，即3
    return OTHER;       // 返回OTHER，即0
}

int main()
{
    int l = 0;                  // 字符串长度
    int cnt[DIGIT + 1] = {0};   // 各类字符计数
    char str[MAX_LEN] = "\0";   // 输入的字符串

    /** 读入一行字符串 **/
    cin.getline(str, MAX_LEN, '\n');    // 在超过MAX_LEN或读到'\n'时终止

    /** 各类字符计数 **/
    while (str[l] != '\0')
        cnt[check_char(str[l++])]++;
    /** // 计算字符串长度的方法
    l = 0;
    while (str[l++] != '\0');
    **/

    for (int i = UPPER; i <= DIGIT; i++)
    {
        if (i != UPPER)
            cout << " ";
        cout << cnt[i];
    }
    cout << endl;
    return 0;
}
