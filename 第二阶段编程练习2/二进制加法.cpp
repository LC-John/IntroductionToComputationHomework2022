/*****
题目描述

给定两个二进制数 a 和 b ，计算 a + b 之和，输出和的二进制表示。

关于输入

输入有 2n + 1 行，第一行是 n，其余2n行，每两行一组，第一行是二进制数 a，第二行是二进制数 b；a 和 b
都大于 0 且不含前导 0 ，a、b 的位数不超过 100 位。

关于输出

输出 n 行 a + b 的结果，用二进制表示。

例子输入

2
1110011
11111111000
1010101
101010

例子输出

100001101011
1111111

提示信息

对 n 的取值没有特别的限制，只需要保证 n 是自然数即可。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 300


int debug(char* str, int len)
{
    for (int i = 0; i < len; i++)
        cout << str[i];
    cout << endl;
    return 0;
}

/** 翻转字符串，编程网格不支持strrev函数 **/
char* str_reverse(char* str, int len)
{
    int i = len / 2;
    if (len % 2 == 1)
        i++;
    for (; i < len; i++)
    {
        str[i] = str[i] ^ str[len-1-i];
        str[len-1-i] = str[i] ^ str[len-1-i];
        str[i] = str[i] ^ str[len-1-i];
    }
    return str;
}

int main()
{
    int n_case = 0;
    char *a = NULL, *b = NULL;  // 两数的字符串；使用指针，方便进行交换
    char c = '0';               // 记录进位
    int la = 0, lb = 0;         // 两数的长度
    cin >> n_case;
    while(n_case--)
    {
        /** 初始化&读入数据 **/
        c = '0';
        a = new char[MAX_N];    // new出足够长度的字符数组
        b = new char[MAX_N];
        memset(a, 0, sizeof(char) * MAX_N);     // 用'\0'初始化字符数组的所有位置
        memset(b, 0, sizeof(char) * MAX_N);
        cin >> a >> b;
        la = strlen(a);     // strlen返回字符串长度，需要cstring
        /**
       la = 0;
       while (a[la++] != '\0'); // 也可以使用这一方法计算长度
       **/
        lb = strlen(b);

        /** 准备工作 **/
        if (la < lb)        // 若a短于b
        {
            char* tmp = a;  // 则交换a和b的指针
            a = b;
            b = tmp;
            la = strlen(a); // 并更新a和b的长度
            lb = strlen(b);
        }
        a = str_reverse(a, la);  // 翻转a和b，使最低位对其
        b = str_reverse(b, lb);
        memset(b + lb, '0', sizeof(char) * (la - lb));  // 用'0'补齐b，使得b与a一样长
        //debug(a, la);
        //debug(b, la);

        /** 逐位计算 **/
        for (int i = 0; i < la; i++)                    // 使用a[i]、b[i]和c逐位进行计算
            switch ((a[i] - '0') + (b[i] - '0') + c)    // 计算得到该位结果存于a[i]中
            {                                            // 进位更新存于c中
                case '0': a[i] = '0'; c = '0'; break;
                case '1': a[i] = '1'; c = '0'; break;
                case '2': a[i] = '0'; c = '1'; break;
                case '3': a[i] = '1'; c = '1'; break;
            }

        /** 输出结果&释放空间 **/
        if (c > '0')    // 若c不是0,
            cout << c;  // 则说明结果多出一位，先输出c
        for (int i = la - 1; i >= 0; i--)   // 由于a最低位在前，因此倒序输出a
            cout << a[i];
        cout << endl;
        delete[] a; // 释放new出的字符数组
        delete[] b;
    }
    return 0;
}
