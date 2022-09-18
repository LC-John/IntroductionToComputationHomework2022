/*****
题目描述

一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。
问大象至少要喝多少桶水才会解渴。(设PAI=3.14159)

关于输入

输入有一行，两个整数：分别表示小圆桶的深h，和底面半径r，单位厘米。

关于输出

输出也只有一行，大象至少要喝水的桶数。

例子输入

23 11

例子输出

3

提示信息

1000升=1立方米
ceil(x) 求x的上取整，返回值为浮点
*需要#include "math.h"
*****/

#include<iostream>
#include<cmath>
using namespace std;

#define V 20000
#define PI 3.14159

int main()
{
    int h = 0, r = 0;
    cin >> h >> r;
    cout << ceil(V / (h * r * r * PI)) << endl;
    return 0;
}
