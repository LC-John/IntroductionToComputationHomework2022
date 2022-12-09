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

/**
思路

首先介绍快速幂，即如何快速求取A^k。
显然最直接的方法就是循环k次，但这样时间复杂度较高，有更优的方法。
我们可以发现k是可以分解成二进制编码的，即：

k = sum_i(2^i), where k's i-th binary code is 1

那么显然就有：

A^k = A^(sum_i(2^i)) = mul_i(A^(2^i)), where k's i-th binary code is 1

因此，我们可以用O(log(k))的复杂度而非O(k)来求取A^k。可以参考下面的exp函数


有了快速幂后，我们考虑如何求取A^k的和。
同样的，最直接的办法就是逐个求取A^k，然后再加起来，但这样的复杂度也很高。
我们可以构造下面的分块矩阵

| S(k-1) A^k |
|  0      0  |

和

| I 0 |
| I A |

其中，S(k-1) = A + A^2 + ... + A^(k-1)。那么可以发现递推关系

| S(k-1) A^k | x | I 0 | = | S(k) A^(k+1) |
|  0      0  |   | I A |   |  0      0    |

把上面的递推关系展开，可以得到

| S(k) A^(k+1) | = | S(0) A | x | I 0 |^k = SA(0) x I0IA^k
|  0      0    |   |  0   0 |   | I A |

使用快速幂求取I0IA^k，然后与SA(0)相乘即可。
需要注意，在所有计算过程中都需要取模。
**/

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

/** 快速幂 **/
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

    /** 构造SA(0)和I0IA **/
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

    b = exp(b, k);  // 快速幂
    a = mul(a, b);  // 相乘
    for(int i = 1;i + i <= n; i++)  // 答案在a的左上角分块矩阵中
    {
        for(int j = 1;j + j <= n; j++)
            cout << a.mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
