/*****
题目描述

读入一组大小为n(n<=10010)个样本数据（双精度浮点数），求他们的均值E和方差D。

关于输入

第一个整数为n，剩余n个双精度浮点数为样本数据。

关于输出

输出为一行，均值E和方差D，两数之间用一个空格分隔，精确到小数点后5位。

例子输入

4
1
2
3
2

例子输出

2.00000 0.50000
*****/

#include <cstdio>

#define MAX_N 10100
double num[MAX_N] = {0};

int main()
{
    int n = 0;
    double E = 0, D = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &num[i]);

    /** 计算均值 **/
    for (int i = 0; i < n; i++)
        E += num[i];
    E /= n;

    /**计算方差**/
    for (int i = 0; i < n; i++)
        D +=  (num[i] - E) * (num[i] - E);
    D /= n;

    printf("%.5lf %.5lf\n", E, D);
    return 0;
}
