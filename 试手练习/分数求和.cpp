/*****
题目描述

输入n个分数并对他们求和，用约分之后的最简形式表示。
比如：
q/p = x1/y1  + x2/y2 +....+ xn/yn，
q/p要求是归约之后的形式。
如：5/6已经是最简形式，3/6需要规约为1/2, 3/1需要规约成3，10/3就是最简形式。
PS:分子和分母都没有为0的情况，也没有出现负数的情况

关于输入

第一行的输入n,代表一共有几个分数需要求和
接下来的n行是分数

关于输出

输出只有一行，即归约后的结果

例子输入

2
1/2
1/3

例子输出

5/6
*****/

#include <cstdio>

int swp(unsigned int &a, unsigned int &b)
{
    if (a < b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return 0;
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    unsigned int r = 0;
    swp(a, b);
    while (a % b)
    {
        r = a % b;
        a = b;
        b = r;
        swp(a, b);
    }
    return b;
}

int main()
{
    int n = 0;
    unsigned int a = 0, b = 0;
    unsigned int numerator = 0, denominator = 0;

    scanf("%d", &n);
    while(n--)
    {
        unsigned int tmp = 0;
        scanf("%u/%u", &a, &b);
        /* Simplify the input fraction */
        tmp = gcd(a, b);
        a /= tmp;
        b /= tmp;
        /* Initialize numerator and denominator */
        if ((!numerator) && (!denominator))
        {
            numerator = a;
            denominator = b;
            continue;
        }
        /* Add the simplified fraction to the final fraction */
        tmp = b * (denominator / gcd(b, denominator));
        numerator = a * (tmp / b) + numerator * (tmp / denominator);
        denominator = tmp;
        /* Simplify the final fraction */
        tmp = gcd(numerator, denominator);
        numerator /= tmp;
        denominator /= tmp;
    }

    if (denominator == 1)
        printf("%u\n", numerator);
    else
        printf("%u/%u\n", numerator, denominator);

    return 0;
}
