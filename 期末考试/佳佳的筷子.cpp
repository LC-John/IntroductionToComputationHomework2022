/*****
题目描述

佳佳与常人不同，吃饭用三只筷子，两根短的加一根比较长的。两只短的筷子的长度应该尽可能接近，
但是最长的那根长度是无所谓的。如果一套筷子的长度分别是a,b,c(a<=b<=c),则用(a-b)*(a-b)的值
表示这套筷子的质量，这个值越小，这套筷子的质量越高。
佳佳请朋友吃饭，并准备为每人准备一套这种特殊的筷子。佳佳有n(n<=5000)只筷子,他希望找到一种
办法搭配好k套筷子，使得这些筷子的质量之和最小。

关于输入

第一行是两个整数n和k(n<=5000,3*k<=n)
第二行是n个整数表示筷子的长度

关于输出

输出一个整数,表示筷子质量和的最小值

例子输入

5 1
1 3 4 7 10

例子输出

1

提示信息

从小到大排序后从后向前递推
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 5010
#define MAX_INT 0x7fffffff

int l[MAX_N] = {0}, dp[MAX_N][MAX_N] = {0};

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> l[i];
    sort(l + 1, l + n + 1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = MAX_INT;
    for (int i = 1; i <= n; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = n - 3 * i + 1; j; j--)
            dp[i][j] = min((l[j + 1] - l[j]) * (l[j + 1] - l[j]) + dp[i - 1][j + 2],
                           dp[i][j + 1]);
    cout << dp[k][1] << endl;
    return 0;
}
