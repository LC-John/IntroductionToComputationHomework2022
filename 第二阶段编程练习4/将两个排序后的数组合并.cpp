/*****
题目描述

假设你给出两个已经经过排序的数组A[10]与B[10]，
那么利用归并排序的思想，将两个数组合并并且再排序为一个新的数组C[20]
并且把C输出的屏幕上。

关于输入

两行 每行十个元素

关于输出

一行 总共20个元素

例子输入

1 3 5 7 9 11 13 15 17 19
2 4 6 8 10 12 14 16 18 20

例子输出

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*****/

#include <iostream>
using namespace std;

#define N 10

int a[N] = {0}, b[N] = {0};

int main()
{
    bool flag = false;

    /** 读入数据 **/
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];

    /** 归并数组 **/
    for(int i = 0, j = 0; i < N || j < N; ) // i和j分别指代a和b数组当前下标
    {

        /** 控制是否输出空格 **/
        if (flag)
            cout << " ";
        else
            flag = true;

        /** 归并 **/
        if (i < N & j < N)      // 若i和j都小于N，说明a和b数组都没有输出完
        {
            if (a[i] < b[j])    // 当a[i]较小时
            {
                cout << a[i];   // 则输出a[i]
                i++;            // i向后移动
            }
            else                // 否则b[j]较小
            {
                cout << b[j];   // 输出b[j]
                j++;            // j向后移动
            }
        }
        else if (i < N)         // a还没输出完而b已经输出完
        {
            cout << a[i];       // 则输出a[i]
            i++;                // i向后移动
        }
        else                    // 同上
        {
            cout << b[j];
            j++;
        }
    }
    return 0;
}
