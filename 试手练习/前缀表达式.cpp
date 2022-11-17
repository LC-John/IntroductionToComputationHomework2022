/*****
题目描述

前缀表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的前缀表示法为+ 2 3。
前缀表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，例如(2 + 3) * 4
的前缀表示法为* + 2 3 4。本题求解前缀表达式的值，其中运算符包括+ - * /四个。

关于输入

输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。

关于输出

输出为一行，表达式的值。
可直接用printf("%f\n", v)输出表达式的值v。

例子输入

* + 11.0 12.0 + 24.0 35.0

例子输出

1357.000000

提示信息

可使用atof(str)把字符串转换为一个double类型的浮点数。atof定义在stdlib.h中。
此题可使用函数递归调用的方法求解。
*****/

#include <cstdio>

#define MAX_LEN 100
char buf[MAX_LEN] = "";

double dfs()
{
    double n = 0;
    scanf("%s", buf);
    switch(buf[0])
    {
    case '+': return dfs() + dfs();
    case '-': return dfs() - dfs();
    case '*': return dfs() * dfs();
    case '/': return dfs() / dfs();
    default:
        sscanf(buf, "%lf", &n);
        return n;
    }
    return n;
}

int main()
{
    printf("%lf\n", dfs());
    return 0;
}
