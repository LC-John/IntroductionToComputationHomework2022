/*****
题目描述

最近北京大学药学院的小晨在计概课上学习到二进制之后对其产生了浓厚的兴趣，在每次操作仅能
移动相邻的0和1的前提下，她想知道把一个二进制数转换成另一个二进制数的最小操作数。

关于输入

输入共三行：
第一行为一个整数n (0 < n <= 200)，代表二进制数的位数
第二行为第一个二进制数的每一位
第三行为第二个二进制数的每一位

关于输出

输出将第一个二进制数转换为第二个二进制数的最少操作数，如果答案不存在，则输出-1

例子输入

7
1 1 0 1 0 0 1
0 1 1 0 0 1 1

例子输出

4
*****/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 1000

int pos1[MAX_N] = {0}, n1 = 0;
int pos2[MAX_N] = {0}, n2 = 0;

int main()
{
    int n = 0, d = 0;
    cin >> n;
    /* Positions of 1's in each binary sequence */
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        if (d)
            pos1[n1++] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        if (d)
            pos2[n2++] = i;
    }

    d = 0;
    /* The numbers of 1's are not equal */
    if (n1 != n2)
        cout << -1;
    else
    {
        /* Move the 1's */
        for (int i = 0; i < n1; i++)
            d += abs(pos1[i] - pos2[i]);
        cout << d;
    }
    return 0;
}
