/*****
题目描述

我们称一个字符的数组S为一个序列。对于另外一个字符数组Z,如果满足以下条件，
则称Z是S的一个子序列：（1）Z中的每个元素都是S中的元素（2）Z中元素的顺序与
在S中的顺序一致。例如：当S = (E,R,C,D,F,A,K)时，（E，C，F）和（E，R）等
等都是它的子序列。而（R，E）则不是。
现在我们给定两个序列，求它们最长的公共子序列的长度。

关于输入

一共两行，分别输入两个序列

关于输出

一行，输出最长公共子序列的长度。

例子输入

ABCBDAB
BDCABA

例子输出

4
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 1000

/**
思路：动态规划

两个字符串用a和b表示。
用dp[i][j]来记录a的长度为i的前缀和b的长度为j的前缀的最长公共子序列的长度。
显然，dp[i][0] = dp[0][j] = 0（对任意可行的i和j来说）。
假设对任意0 <= i < M和任意0 <= j < N的dp[i][j]都是已知的，求dp[M][N]就只有如下的两种情况：
1. a[M]和b[N]相同，则说明在M-1和N-1的基础之上公共子序列长度可以增长1，那么dp[M][N] = dp[M - 1][N - 1] + 1；
2. 否则，只能a的前缀或b的前缀回退一个字符，选取其中较大的方案，那么dp[M][N] = max(dp[M - 1][N], dp[M][N - 1])。
按上述计算方式，从dp[0][0]向右下计算即可，dp[strlen(a)][strlen(b)]便是需要求的答案。
**/

char a[MAX_LEN] = "\0", b[MAX_LEN] = "\0";
int dp[MAX_LEN][MAX_LEN] = {0};

int main()
{
    cin >> a >> b;
    for (int i = 0; a[i] != '\0'; i++)
        for (int j = 0; b[j] != '\0'; j++)
        {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
        }
    cout << dp[strlen(a)][strlen(b)] << endl;
    return 0;
}
