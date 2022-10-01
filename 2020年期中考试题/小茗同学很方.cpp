/*****
描述

n(n不超过1000)个有蛀牙的小朋友被老师组织集体去拔牙，但是排队的时候由于所有小朋友都害怕拔牙，
所以没人主动排在前面。这时老师想了一个有趣的方法，所有小朋友排成一列，按照顺序进行编号（编号
从1开始），并从1依次进行报数，数到m的小朋友去拔牙，然后后面的小朋友再从1开始报数，下一个数到
m的小朋友去拔牙…依此循环往复。小茗同学既不想先去拔牙，也不想被留到最后再拔，于是他决定第k(k<=n)
个去拔。请你帮小茗同学想想他应该排在第几个位置才能“如愿以偿”。

关于输入

n,m,k

关于输出

一个整数，小茗在队列中的位置(从1开始)

例子输入

10,3,5

例子输出

7
*****/

#include <iostream>
using namespace std;

#define MAX_N 1010

int line[MAX_N] = {0};
int n = 0, m = 0, k = 0;

int main()
{
    int ans = 0;
    char ch = '\0';
    cin >> n >> ch >> m >> ch >> k;
    for (int i = 0; i < n; i++)
        line[i] = i + 1;
    for (int _wait = 0, cur = 0; _wait < k; _wait++)
    {
        cur = (cur + m - 1) % n;
        ans = line[cur];
        for (int i = cur; i < n - 1; i++)
            line[i] = line[i + 1];
        n--;
    }
    cout << ans;
    return 0;
}
