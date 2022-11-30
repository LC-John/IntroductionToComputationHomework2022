/*****
题目描述

在计算机程序中，往往会大量使用字符串。对于不同的字符串，我们总希望能够有办法判断其相似度。
因此，我们定义了一套操作方法来把两个不同的字符串变得相同。
具体可选的操作方法有：
1. 修改一个字符，例如将"a"修改为"b"；
2. 增加一个字符，例如将"abdd"变为"aebdd"
3. 删除一个字符，例如将"travelling"变为"traveling"
例如，对于两个字符串"abcdefg"和"abcdef"两个字符串来说，我们可以通过“将前一个字符串减少一
个g”或者“给后一个字符串增加一个g”这两种方式来使得它们相同，这两种方案，都仅需要一次操作。
将修改字符串操作需要的最少的次数定义为两个字符串之间的距离，而相似度等于“距离+1”的倒数。
例如，上例中"abcdefg"和"abcdef"的距离为1，则其相似度为1/2=0.5.
给定任意两个字符串(长度20以内)，写出一个程序来求出它们的相似度。

关于输入

第一行有一个整数n。表示测试数据的组数，
接下来共n行，每行两个字符串，用空格隔开。表示要计算距离的两个字符串
字符串长度不超过20。

关于输出

针对每一组测试数据输出两个字符串的相似度，保留小数点后6位。

例子输入

3
abcdefg  abcdef
ab ab
mnklj jlknm

例子输出

0.500000
1.000000
0.200000
*****/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_LEN 30
int dp[MAX_LEN][MAX_LEN] = {0};

int main()
{
    int n = 0, l1 = 0, l2 = 0;
    char s1[MAX_LEN] = "", s2[MAX_LEN] = "";
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s %s", s1, s2);
        l1 = strlen(s1);
        l2 = strlen(s2);
        memset(dp, 0x00, sizeof(dp));
        for (int i = 0; i <= l1; i++)
            dp[i][0] = i;
        for (int j = 0; j <= l2; j++)
            dp[0][j] = j;
        for (int i = 1; i <= l1; i++)
            for (int j = 1; j <= l2; j++)
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])));
        printf("%.6f\n", 1. / (dp[l1][l2] + 1));
    }
    return 0;
}
