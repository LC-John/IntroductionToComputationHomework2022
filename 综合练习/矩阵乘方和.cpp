/*****
题目描述

给出一个n*n的矩阵A和正整数k,请求出S=A+A^2+A^3+A^4+...+A^k的值.mat^x表示x个A相乘的结果.

关于输入

输入包含一组数据.
第一行是三个正整数n k m, (n<=30,k<=1000000000,m<=10000).
接下来n行,每行n个数,表示这个矩阵.

关于输出

输出矩阵S对m取模后的值（即：每个元素对 m 取余）,包括n行,每行n个数

例子输入

2 2 4
0 1
1 1

例子输出

1 2
2 3
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 40

struct Matrix
{
    int mat[MAX_N * 2][MAX_N * 2];
};
int n = 0, k = 0, m = 0;

Matrix mul(Matrix &a, Matrix &b)
{
    Matrix ret;
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= n; j++)
        {
            ret.mat[i][j]=0;
            for(int k = 1; k <= n; k++)
            {
                ret.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % m;
                ret.mat[i][j] %= m;
             }
        }
    return ret;
}

Matrix exp(Matrix &a, int x)
{
    Matrix ret;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ret.mat[i][j] = (i == j ? 1 : 0);
    for(; x ; x >>= 1)
    {
        if(x & 1)
            ret = mul(ret, a);
        a = mul(a, a);
     }
    return ret;
}

int main()
{
    Matrix a, b;
    memset(a.mat, 0, sizeof(a.mat));
    memset(b.mat, 0, sizeof(b.mat));
    cin >> n >> k >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a.mat[i][j + n];
            b.mat[i + n][j + n] = a.mat[i][j + n];
        }
    for(int i = 1;i <= n; i++)
    {
        b.mat[i][i] = 1;
        b.mat[i+n][i] = 1;
    }
    n = n * 2;

    b = exp(b, k);
    a = mul(a, b);
    for(int i = 1;i + i <= n; i++)
    {
        for(int j = 1;j + j <= n; j++)
            cout << a.mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
