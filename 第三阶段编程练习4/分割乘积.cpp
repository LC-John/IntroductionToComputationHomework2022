/*****
题目描述

给定一个整数，求插入两个乘号的最大乘积。

关于输入

只有一行，一个整数。

关于输出

所求出的最大乘积。

例子输入

4242

例子输出

336

提示信息

整数有正有负。
输入保证：如果按题目要求的乘法操作，不会使int发生溢出。
*****/

#include <cstdio>
#include <cstring>

#define MAX_N 30
#define MIN_INT 0x80000000

int main()
{
    char s[MAX_N] = "", s1[MAX_N] = "", s2[MAX_N] = "", s3[MAX_N] = "";
    int len = 0, n1 = 0, n2 = 0, n3 = 0;
    int ans = MIN_INT, prod = 0;
    int st = 1;
    scanf("%s", s);
    len = strlen(s);
    st += (s[0]=='-');
    for(int i = st; i < len - 1; i++)
        for(int j = i + 1; j < len; j++)
        {
            memset(s1, '\0', sizeof(s1));
            memset(s2, '\0', sizeof(s2));
            memset(s3, '\0', sizeof(s3));
            strncpy(s1, s, i);
            strncpy(s2, s + i, j - i);
            strcpy(s3, s + j);
            sscanf(s1, "%d", &n1);
            sscanf(s2, "%d", &n2);
            sscanf(s3, "%d", &n3);
            prod = n1 * n2 * n3;
            if (ans < prod)
                ans = prod;
            // printf("%d %d %d %d\n", n1, n2, n3, ans);
        }
    printf("%d\n", ans);
    return 0;
}
