/*****
题目描述

小朋友玩跳绳比赛,要计算在一分钟内跳了多少下.假设每秒钟跳一下,如果中途失败了,则要花三秒钟后才能开始重跳.
一般小朋友跳绳一分钟要跳坏好几次.现在给出小朋友每次跳坏时已经跳的总数,求小朋友在一分钟内跳了多少下.(请
注意分析示例数据.)

关于输入

第一行为n个小朋友
其余各行,每行第一个整数是跳坏的次数m,其余m个整数是跳坏时累计跳了多少下. 这m个整数是从小到大排列的

关于输出

输出相应小朋友头一分钟内跳了多少下.

例子输入

6
0
3 12 23 45
1 17
4 10 20 30 40
5 10 20 30 40 58
6 10 20 30 40 47 60

例子输出

60
51
57
48
48
47

提示信息

提示,在跳绳比赛时,你可能已经超时了,但自己还在计数,但裁判已经停止计时并得到成绩了.这里相当与自己计数.因
此,并非跳坏的时候都是在前一分钟以内.请注意分析示例数据.
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 200
#define MINUTE 60
#define REST 3

int sec[MAX_N] = {0};   // 记录每一秒是否跳绳的数组，0表示跳了，1表示没跳

int main()
{
    int n_case = 0, n = 0;
    int curr = 0;   // 到跳坏时已经跳了多少个
    int cnt = 0;    // 记录个数
    cin >> n_case;
    while(n_case--)
    {
        /** 初始化 **/
        curr = 0;
        cnt = 0;
        memset(sec, 0x00, sizeof(int) * MAX_N);
        /** 在sec数组上标记每一秒是否有跳绳 **/
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> curr;
            int _cnt = 0;   // _cnt用于辅助计数
                            // 此时用cnt记录因为跳坏而等待的时间
            for (int j = curr + cnt; j < MINUTE && j < curr + cnt + REST; j++)
                if (!sec[j])
                {
                    sec[j] = 1; // 若跳坏或在跳坏的等待时间里，则sec数组对应位置标1
                    _cnt++;
                }
            cnt += _cnt;
        }
        /** 在sec数组上计数一分钟跳了多少次 **/
        cnt = MINUTE;   // 此时用cnt记录跳绳数目
        for (int i = 0; i < MINUTE; i++)
            cnt -= sec[i];
        cout << cnt << endl;
    }
    return 0;
}
