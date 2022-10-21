/*****
题目描述

该题目的数据代表两种操作：
1. 在指定的区域上添加一个矩形（可以和以前已有的矩形重叠）；
2 .询问一个矩形是否被已添加的所有矩形形成的区域完全覆盖。
写程序完成添加矩形操作，并且针对第二种询问操作，如果被覆盖，则输出“Yes”，否则输出：“No”

关于输入

第一行是一个整数n (1<=n<=500)，代表有n个操作。
接下来共有n行，
每一行第一个数字为0时，代表该步要添加新矩形，接下来有四个整数x1,y1,x2,y2 (0 <= x1 <= 500,
0 <= x2 <= 500, 且x1小于x2 ;  0 <= y1 <= 500, 0 <= y2 <= 500, 且y1小于y2)，
代表该新矩形的左下角坐标为(x1,y1)，右上角坐标为(x2,y2)。
每一行第一个数字为1时，代表该步要进行询问，接下来有四个整数x1,y1,x2,y2 (0 <= x1 <= 500,
0 <= x2 <= 500, 且x1小于x2 ;  0 <= y1 <= 500, 0 <= y2 <= 500, 且y1小于y2)，
代表需要被询问的矩形的左下角坐标为(x1,y1)，右上角坐标为(x2,y2)。

关于输出

对于每一个询问操作，若给出的矩形被之前添加的矩形覆盖，那么输出“Yes”,否则输出“No”。

例子输入

7
1 1 1 3 3
0 1 1 3 2
0 1 1 2 3
1 1 1 2 2
1 1 1 3 3
0 2 2 3 3
1 1 1 3 3

例子输出

No
Yes
No
Yes
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000
#define EMPTY '#'
#define PAINT '*'

char arr[MAX_N][MAX_N] = {""};

bool check(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            if (arr[i][j] != PAINT)
                return false;
    return true;
}

void paint(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            arr[i][j] = PAINT;
}

int main()
{
    int n = 0, opt = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    memset(arr, EMPTY, sizeof(arr));
    cin >> n;
    while (n--)
    {
        cin >> opt >> x1 >> y1 >> x2 >> y2;
        switch(opt)
        {
        case 0:
            paint(x1, y1, x2, y2);
            break;
        case 1:
            if (check(x1, y1, x2, y2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        default: break;
        }
    }
    return 0;
}
