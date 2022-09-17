/*****
题目描述

有一个正方形，四个角的坐标（x,y)分别是（1，-1），（1，1），（-1，1），（-1，-1），
x是横轴，y是纵轴。写一个程序，判断一个给定的点是否在这个正方形内。

关于输入

输入坐标x，y

关于输出

点在正方形内，输出yes；点在正方形外，输出no

例子输入

0.5,0.5

例子输出

yes

提示信息

要注意正方形四个角的坐标（x，y）的边界条件
*****/

#include <iostream>
using namespace std;

int main()
{
    double x, y;    // (x,y)坐标
    char ch;        // 使用一个char类型变量来读入逗号
    cin >> x >> ch >> y;
    /**
    scanf("%lf,%lf", &x, &y);   // 也可以使用scanf来控制输入格式
                                // 注意需要#include <cstdio>
    **/
    if (x >= -1 && x <= 1 && y >= -1 && y <= 1)     // 判断点是否在正方形内
        cout << "yes";
    else
        cout << "no";
    return 0;
}
