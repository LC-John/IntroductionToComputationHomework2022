/*****
题目描述

在一个平面上，如果有两个点(x,y),(a,b),如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;
用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。
给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。
编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。
本题规定：n不超过100，并且不考虑点的坐标为负数的情况。

关于输入

输入包括两行，第一行是正整数n，表示是点数，第二行包含n个点的坐标，坐标值都是整数，坐标范围
从0到100，输入数据中不存在坐标相同的点。

关于输出

按x轴坐标最小到大的顺序输出所有极大点。
输出格式为:(x1,y1),(x2,y2),...(xk,yk)
注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错

例子输入

5
1 2 2 2 3 1 2 3 1 4

例子输出

(1,4),(2,3),(3,1)
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000

struct Point            // 记录点坐标的结构体
{
    int x;
    int y;
} p[MAX_N] = {{0, 0}};  // 记录所有的点的数组
int n = 0;              // 点的数目

void _swap(int i, int j)    // 交换数组中的两点
{
    p[i].x ^= p[j].x;
    p[j].x ^= p[i].x;
    p[i].x ^= p[j].x;
    p[i].y ^= p[j].y;
    p[j].y ^= p[i].y;
    p[i].y ^= p[j].y;
}

void _sort()    // 对点坐标排序；按x排序，若x相等则按y排序
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i].x > p[j].x || (p[i].x == p[j].x && p[i].y > p[j].y))
                _swap(i, j);
}

int main()
{
    bool comma = false, flag = true;

    /** 读入数据并排序 **/
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    _sort();    // 排序后，每个点都不比其前面的点的x坐标小；并且若与前一个点的x坐标一样，则y坐标不比其小


    for (int i = 0; i < n; i++)
    {
        /** 判断i点是否被其他点支配 **/
        flag = true;    // 初始化flag，flag为true表示当前点不被任何点支配
        for (int j = i + 1; j < n; j++) // 每个点只需与其后面的点比较y即可
            if (p[j].y >= p[i].y)       // 若i的y坐标小于j
            {
                flag = false;           // 则说明i被j支配，flag置为false
                break;                  // 终止继续向后循环
            }

        /** 若i不被支配，则输出 **/
        if (flag)
        {
            if (comma)
                cout << ",";
            else
                comma = true;
            cout << "(" << p[i].x << "," << p[i].y << ")";
        }
    }
    return 0;
}
