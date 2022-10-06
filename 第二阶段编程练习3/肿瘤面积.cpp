/*****
题目描述

在一个正方形的灰度图片上，肿瘤是一块矩形的区域，肿瘤的边缘所在的像素点在图片中用0 表示。其它肿瘤内和肿瘤外的点都用255 表示。
现在要求你编写一个程序，计算肿瘤内部的像素点的个数（不包括肿瘤边缘上的点）。已知肿瘤的边缘平行于图像的边缘。

关于输入

只有一个测试样例。第一行有一个整数n，表示正方形图像的边长。其后n 行每行有n 个整数，取值为0 或255。整数之间用一个空格隔开。
已知n 不大于1000。

关于输出

输出一行，该行包含一个整数，为要求的肿瘤内的像素点的个数。

例子输入

5
255 255 255 255 255
255 0 0 0 255
255 0 255 0 255
255 0 0 0 255
255 255 255 255 255

例子输出

1

提示信息

分别找到边缘的左上角和右下角，然后计算矩形面积。
本题也可以不使用数组来计算！
*****/

#include <iostream>
using namespace std;

#define MAX_N 1010
#define MASK 255    // 标记图片边界

int img[MAX_N][MAX_N] = {0};

int main()
{
    int n = 0;
    int upper_left_row = 0, upper_left_col = 0;
    int lower_right_row = 0, lower_right_col = 0;

    /** 读入数据，并将图片边界标记 **/
    cin >> n;
    for (int i = 1; i <= n; i++)        // 从下标1开始读入数据
        for (int j = 1; j <= n; j++)
            cin >> img[i][j];
    for (int i = 1; i <= n; i++)    // 将图片外一圈标记，之后就不需要特判边界
        img[i][0] = img[i][n + 1] = img[0][i] = img[n + 1][i] = MASK;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!img[i][j])
            {
                if (img[i - 1][j] && img[i][j - 1]) // 若当前位置是肿瘤边界，且左侧和上方不是
                {
                    upper_left_col = i;             // 则该点是肿瘤的左上角，记录位置
                    upper_left_row = j;
                }
                else if (img[i + 1][j] && img[i][j + 1])    // 若当前位置是肿瘤边界，且右侧和下方不是
                {
                    lower_right_col = i;                    // 则该点是肿瘤的右下角，记录位置
                    lower_right_row = j;
                }
            }
    cout << (lower_right_row - upper_left_row - 1) * (lower_right_col - upper_left_col - 1) << endl;
    return 0;
}
