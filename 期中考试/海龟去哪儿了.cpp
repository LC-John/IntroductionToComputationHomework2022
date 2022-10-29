/*****
题目描述

海龟从坐标原点（0，0）出发，每次移动，坐标变化量为dx, dy；
输入一系列坐标的变化量，输出海龟移动若干次后，到原点的距离。
例如：
第一次，-1 -1移动到（-1，-1）
第二次，1 0移动到（0，-1）
第三次，1 2移动到（1，1）
经过三次移动，距离原点1.4142
也就是说，输入：
-1.0 -1.0 1.0 0.0 1.0 2.0
输出
1.4142

关于输入

一行若干个浮点数，若干对（dx，dy）

关于输出

一个浮点数，保留小数点后4位

例子输入

-1.0 -1.0 1.0 0.0 1.0 2.0

例子输出

1.4142

提示信息

（1）要让输出保持两位小数，可以如下处理
在#include部分增加对 iomanip 的引用
使用如下的语句进行输出：
cout << fixed << setprecision(4) << x << endl;
（2）如果需要用到求平方根函数
在#include部分增加对 cmath 的引用
函数原型为：double sqrt(double)
*****/

#include <cstdio>
#include <cmath>

int main()
{
    double x = 0, y = 0, dx = 0, dy = 0;
    while(scanf("%lf %lf", &dx, &dy) != EOF)
    {
        x += dx;
        y += dy;
    }
    printf("%.4lf\n", sqrt(x * x + y * y));
    return 0;
}
