/*****
题目描述

卡塔尔世界杯正在举行！假设有 n 场比赛，每场比赛均分出胜负，没有平局，请找出所有没有输掉任何比赛，
且至少参加了一场比赛的国家，并按国家编号递增输出；若不存在这样的国家，输出字符串"None"。

关于输入

第一行是一个正整数 n，表示比赛场数（1 <= n <= 100000）。
接下来 n 行，每行两个正整数，分别表示该场比赛获胜和失利的国家的编号（1 <= 国家编号 <= 100000），
第一个为获胜国家编号，第二个为失利国家编号。

关于输出

一列正整数，所有没有输掉任何比赛的国家编号，但不包括那些没有参与过任何一场比赛的国家。国家间使用
", "（一个逗号和一个空格）作为分隔；或者"None"。

例子输入

4
2 3
1 3
4 2
6 4

例子输出

1, 6

提示信息

只需考虑那些参与至少一场比赛的国家。测试用例保证不存在两场比赛结果相同。
*****/

#include <iostream>
using namespace std;

#define MAXN 100100
#define EMPTY 0
#define YES 1
#define NO 2

int f[MAXN] = {0};

int main()
{
    int n = 0, a = 0, b = 0;
    bool flag = true;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        f[a] = (f[a] == NO) ? f[a] : YES;
        f[b] = NO;
    }
    for (int i = 0; i < MAXN; i++)
        if (f[i] == YES)
        {
            if (flag)
                flag = false;
            else
                cout << ", ";
            cout << i;
        }
    if (flag)
        cout << "None";
    return 0;
}
