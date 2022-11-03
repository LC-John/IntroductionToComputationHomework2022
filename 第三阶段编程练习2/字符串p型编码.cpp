/*****
题目描述

给定一个完全由数字字符（'0','1','2','3'…'9'）构成的字符串str，请写出str的p型编码串。例如：字符串122344111
可被描述为"1个1、2个2、1个3、2个4、3个1"，因此我们说122344111的p型编码串为1122132431；类似的道理，编码串101
可以用来描述1111111111；00000000000可描述为"11个0"，因此它的p型编码串即为110；100200300可描述为"1个1、2个0、
1个2、2个0、1个3、2个0"，因此它的p型编码串为112012201320。

关于输入

输入包含若干测试。第一行给出测试的组数k，接着k行输入为字符串。每一行字符串最多包含1000个数字字符。

关于输出

对每一组测试，输出该字符串对应的p型编码串，输出k行结果（每一输出结果后只需换一行）。

例子输入

3
122344111
1111111111
12345

例子输出

1122132431
101
1112131415
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 10100   // p型编码可以长于原始字符串，因此要留足空间

char str[MAX_LEN] = "\0", p_str[MAX_LEN] = "\0";

/** 将数字转为字符串，并存储在p_str的l位，返回之后的p_str长度 **/
int num2digit(int num, int l)
{
    int ret = l;
    while (num)
    {
        p_str[ret++] = num % 10 + '0';
        num /= 10;
    }
    reverse(p_str + l, p_str + ret);    // 翻转
    return ret;
}

int main()
{
    int n = 0;
    int l = 0;
    int cnt = 0;
    int i = 0;
    cin >> n;
    while (n--)
    {
        cin >> str;
        memset(p_str, '\0', sizeof(p_str));
        l = 0;
        cnt = 0;
        for (i = 0; str[i] != '\0'; i++)
            if (!i || str[i] == str[i - 1])
                cnt++;
            else
            {
                l = num2digit(cnt, l);
                p_str[l++] = str[i - 1];
                cnt = 1;
            }
        l = num2digit(cnt, l);
        p_str[l++] = str[i - 1];
        cout << p_str << endl;
    }
    return 0;
}
