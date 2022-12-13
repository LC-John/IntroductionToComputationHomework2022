/*****
题目描述

医院为了方便对患者进行建档和管理，引入了9位整数ID号来标识每个病人。最近医院入住了
一个迷信的病人，他认为ID号的好坏直接决定了自己的命运。他对ID号x有如下要求:
（1）x的前三位数构成的整数是素数
（2）x的后三位数构成的整数是平方数（所谓平方数，是指它是某一个正整数的平方，e.g.
1,4,9,16...）
（3）x中不包含"13"
为了避免不必要的医患矛盾，医院须尽量满足他的需求。现给定正整数区间[m,n]，请你判断
存在几个满足病人需求的ID号。

关于输入

两个正整数m，n，以空格隔开。(999999999>=n>=m>=111111111)

关于输出

一个整数（满足要求的ID的个数）。

例子输入

157689476 157689687

例子输出

5

提示信息

存在5个满足要求的ID：157689484,157689529,157689576,157689625,157689676
*****/

#include <cstdio>
#include <cstring>

#define MAX_LEN 10

bool contain_13(int n)
{
    char buf[MAX_LEN] = "";
    sprintf(buf, "%d", n);
    if (strstr(buf, "13"))
        return true;
    return false;
}

bool is_prime(int n)
{
    if (!n || n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

bool is_square(int n)
{
    for (int i = 1; i * i <= n; i++)
        if (i * i == n)
            return true;
    return false;
}

int main()
{
    int m = 0, n = 0;
    int ans = 0;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
        if (!contain_13(i) && is_prime(i / 1000000) && is_square(i % 1000))
            ans++;
    printf("%d\n", ans);
    return 0;
}
