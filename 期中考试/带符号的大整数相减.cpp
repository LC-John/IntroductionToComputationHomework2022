/*****
题目描述

给定两个不超过200位的大整数（200位包含符号位。正整数和0可以带符号，也可以不带符号），计算其差值（前面的值-后面的值）。

关于输入

第1行输入 n ，表示后面有 n 组数。
之后，每组数依次占两行，表示被减数与减数；相邻的两组数之间隔一行。

关于输出

逐行输出相减的结果（若结果不为0，最高位不能是0；若结果为非负整数，不能带符号）。

例子输入

5
-567123
-545012

121346
-17623

+12341
2346789

-21346
+87623

-0
-9876543210

例子输出

-22111
138969
-2334448
-108969
9876543210

提示信息

结果的最高位不能是 0，除非结果为0
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_LEN 210

char *a = NULL, *b = NULL;
int la = 0, lb = 0;
bool pa = true, pb = true;  // Is positive

bool get_sign(char *s, int &l)
{
    switch(s[l - 1])
    {
    case '+': s[--l] = '\0'; return true;
    case '-': s[--l] = '\0'; return false;
    default: return true;
    }
}

void remove_zero(char *s, int &l)
{
    while (l > 1 && s[l - 1] == '0')
        s[--l] = '\0';
}

void pad_zero()
{
    while(lb < la)
        b[lb++] = '0';
    b[lb] = '\0';
}

int cmp()  // a < b, -1; a > b, 1; a == b, 0
{
    if (la < lb)
        return -1;
    if (la > lb)
        return 1;
    for (int i = la - 1; i >= 0; i--)
        if (a[i] < b[i])
            return -1;
        else if (a[i] > b[i])
            return 1;
    return 0;
}

void swp()
{
    char *c = a;
    a = b;
    b = c;
    la ^= lb;
    lb ^= la;
    la ^= lb;
    pa ^= pb;
    pb ^= pa;
    pa ^= pb;
}

void add()
{
    int c = 0;
    for (int i = 0; i < la; i++)
    {
        a[i] = c + a[i] - '0' + b[i] - '0' + '0';
        if (a[i] > '9')
        {
            a[i] -= 10;
            c = 1;
        }
        else
            c = 0;
    }
    if (c)
        a[la++] = '1';
    a[la] = '\0';
}

void subtract()
{
    int c = 0;
    for (int i = 0; i < la; i++)
    {
        a[i] = a[i] - (b[i] - '0') - c;
        if (a[i] < '0')
        {
            a[i] += 10;
            c = 1;
        }
        else
            c = 0;
    }
    remove_zero(a, la);
}

int main()
{
    int n = 0;
    bool pc = true;
    a = new char[MAX_LEN];
    b = new char[MAX_LEN];
    cin >> n;
    cin.get();
    while(n--)
    {
        cin.getline(a, MAX_LEN);
        cin.getline(b, MAX_LEN);
        if (n)
            cin.get();
        la = strlen(a);
        lb = strlen(b);
        reverse(a, a + la);
        reverse(b, b + lb);
        pa = get_sign(a, la);
        pb = get_sign(b, lb);
        remove_zero(a, la);
        remove_zero(b, lb);

        if (pa ^ pb)
        {
            pc = pa;
            if (cmp() < 0)
                swp();
            pad_zero();
            add();
        }
        else
        {
            pc = pa;
            if (cmp() < 0)
            {
                swp();
                pc = !pc;
            }
            pad_zero();
            subtract();
        }
        reverse(a, a + la);
        if (la == 1 && a[0] == '0')
        {
            cout << "0" << endl;
            continue;
        }
        if (!pc)
            cout << "-";
        cout << a << endl;
    }
    return 0;
}

