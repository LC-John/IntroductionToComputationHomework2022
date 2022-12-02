/*****
题目描述

任意输入两个K进制纯小数，均为正数，计算其和，其中，1 < K < 11。所谓纯小数是指整数部分为0,
一定有小数位（允许小数位都为0）。假定小数部分的长度不超过100位。

关于输入

第1行，是小数对的个数 n；
之后是 n 行，每行格式是：
k m1 m2
其中，k表示后面的 m1 和 m2 是k进制，m1和m2为k进制纯小数。中间均按空格间隔。
注意：输入的纯小数末位可能会带有0

关于输出

输出为对应的 n 行相加的结果。
规定：结果值的小数位末位不能是0，如果小数位都为0，也必须有小数点。

例子输入

4
2 0.1000110111 0.000011111111101
3 0.1210000001 0.210000010001211
2 0.1011 0.00110
10 0.499 0.501

例子输出

0.100111011011101
1.101000010101211
0.111
1.
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 110

int base = 0, c = 0;

void zero_pad(char *a, char *b)
{
    for (int i = strlen(b); a[i] != '\0'; i++)
        b[i] = '0';
}

int add(int base, char *a, char *b)
{
    int c = 0;
    reverse(a, a + strlen(a));
    reverse(b, b + strlen(b));
    for (int i = 0; a[i] != '\0'; i++)
    {
        a[i] = a[i] - '0' + b[i] - '0' + c;
        c = a[i] / base;
        a[i] = a[i] % base + '0';
    }
    reverse(a, a + strlen(a));
    return c;
}

void remove_zero_pad(char *a)
{
    for (int i = strlen(a) - 1; i >= 0 && a[i] == '0'; i--)
        a[i] = '\0';
}

int main()
{
    char *a = new char[MAX_LEN], *b = new char[MAX_LEN], tmp_c = '\0';
    int base = 0, n = 0, tmp = 0;
    cin >> n;
    while (n--)
    {
        memset(a, 0x00, sizeof(char) * MAX_LEN);
        memset(b, 0x00, sizeof(char) * MAX_LEN);
        cin >> base;
        cin >> tmp >> tmp_c >> a;
        cin >> tmp >> tmp_c >> b;
        if (strlen(a) < strlen(b))  // Swap if a is shorter than b
        {
            char *t = a;
            a = b;
            b = t;
        }
        zero_pad(a, b);
        tmp = add(base, a, b);
        remove_zero_pad(a);
        cout << tmp << "." << a << endl;
    }
    return 0;
}
