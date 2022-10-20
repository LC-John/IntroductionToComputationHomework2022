/*****
题目描述

N个人围成一圈玩传球游戏。开始时，第一个人拿着球。每个人把球传给左手的第K个人，
其中，1 <= K <= N/2。计算最大的K，使得第一个人重新拿到球之前，每个人都拿过球。

关于输入

正整数N，假定N的值大于2

关于输出

K的最大值

例子输入

9

例子输出

4
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000000
bool flag[MAX_N] = {false};

int main()
{
    int n = 0, cnt = 0, curr = 0;
    while(cin >> n)
        for (int i = n / 2; i > 0; i--)
        {
            /** 初始化 **/
            memset(flag, 0x00, sizeof(flag));
            cnt = 0;
            curr = 0;

            /** 按规则传球，直到拿到球的人此前已经拿过了 **/
            while (!flag[curr])
            {
                flag[curr] = true;
                curr = (curr + i) % n;
                cnt++;
            }
            if (cnt == n)
            {
                cout << i << endl;
                break;
            }
        }
    return 0;
}
