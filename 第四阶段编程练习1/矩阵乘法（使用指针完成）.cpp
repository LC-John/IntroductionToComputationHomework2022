/*****
题目描述

计算两个矩阵的乘法。n*m阶的矩阵A乘以m*k阶的矩阵B得到的矩阵C是n*k阶的，且
C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + …… +A[i][m-1]*B[m-1][j]
(C[i][j]表示C矩阵中第i行第j列元素)

关于输入

首先输入G，即测试数据的组数
每组测试数据输入：
第一行为n, m, k，表示A矩阵是n行m列，B矩阵是m行k列，n, m, k均小于100
然后先后输入A和B两个矩阵，A矩阵n行m列，B矩阵m行k列，矩阵中每个元素不会大
于10000

关于输出

针对每组数据，输出n行k列的C矩阵

例子输入

1
3 2 3
1 1
1 1
1 1
1 1 1
1 1 1

例子输出

2 2 2
2 2 2
2 2 2

提示信息

注意每行最后一个数后边的空格不要输出
*****/

#include <iostream>
using namespace std;

int main()
{
    int n_case = 0;
    int n = 0, m = 0, k = 0;
    int **A = NULL, **B = NULL, C = 0;
    cin >> n_case;
    while (n_case--)
    {
        cin >> n >> m >> k;

        /** 给指针分配空间 **/
        A = new int*[n];
        for (int i = 0; i < n; i++)
            A[i] = new int[m];
        B = new int*[m];
        for (int i = 0; i < m; i++)
            B[i] = new int[k];

        /** 读入数据 **/
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> A[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < k; j++)
                cin >> B[i][j];

        /** 计算结果的各个元素并输出 **/
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
            {
                C = 0;
                for (int l = 0; l < m; l++)
                    C += A[i][l] * B[l][j];
                cout << C;
                if (j == k - 1)
                    cout << endl;
                else
                    cout << " ";
            }
    }
    return 0;
}
