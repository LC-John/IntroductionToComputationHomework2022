/*****
题目描述

计算概论班的同学发明了一种新的文本加密算法--将文本转化为十进制数并回型存放到矩阵里。
使用者事先约定好矩阵的行数与列数，并且规定文本中仅有大写字母和空格。他们事先按照这样的方法对文本进行编码：
空格 = 00
A = 01
B = 02
C = 03
......
Y = 25
Z = 26
然后，然后按照回型遍历的方法，将每个字符对应编码的2位十进制数依次填入矩阵中，多出来的位置使用0补充。例如，
对于信息“PKU”，在矩阵行列数均是3的情况下，填充结果为：
1 -> 6 -> 1
          |
0 -> 0    1
|         |
0 <- 1 <- 2
再逐行将矩阵中的数字连起来，完成加密过程。也就是上述例子中的信息最终会被加密为：
161001012

关于输入

第一行为两个整数R和C，中间用一个空格隔开，分别表示行数和列数，其中1≤R≤10，1≤C≤10。
第二行为一个只包含大写字母和空格的字符串，不会以空格开头。1≤字符串长度≤(R * C) / 2。

关于输出

一行，为加密后的十进制串

例子输入

3 3
PKU

例子输出

161001012

提示信息

注意：前导0也要输出
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 20

int arr[MAX_N][MAX_N] = {0};
int num[MAX_N * MAX_N] = {0};
char str[MAX_N * MAX_N] = "\0";
int R = 0, C = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    int pos = 0, x = 0, y = 0, dir = 0;
    memset(arr, -1, sizeof(arr));
    memset(num, -1, sizeof(num));
    cin >> R >> C;
    cin.get();
    cin.getline(str, MAX_N * MAX_N);
    /* Code sequence */
    for (int i = 0; str[i] != '\0'; i++)
    {
        int digit = 0;
        if (str[i] >= 'A' && str[i] <= 'Z')
            digit = str[i] - 'A' + 1;
        num[pos++] = digit / 10;
        num[pos++] = digit % 10;
    }
    /* Zero padding */
    for (; pos < R * C; pos++)
        num[pos] = 0;
    /* Rotationally filling the matrix */
    pos = 0;
    while (pos < R * C)
    {
        int _x = x + dx[dir], _y = y + dy[dir];
        arr[x][y] = num[pos++];
        if (_x < 0 || _x >= R || _y < 0 || _y >= C || arr[_x][_y] >= 0)
        {
            dir = (dir + 1) % 4;
            _x = x + dx[dir], _y = y + dy[dir];
        }
        x = _x;
        y = _y;
    }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cout << arr[i][j];
    return 0;
}
