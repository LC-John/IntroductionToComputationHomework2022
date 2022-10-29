/*****
题目描述

医院某科门诊早上开两个小时。从8点开始可以排队，9点开始正式门诊，每个病人需要看10分钟
(若最后剩余不足10分钟，则不进行门诊)，11点门诊结束。输入包含n（n<=20）个病人的到达时
间（距离8点的分钟数），输出最终得到门诊的病人数。

关于输入

第一行为病人数n。
之后有n行，每行为病人到达的时间

关于输出

一个整数：能得到门诊的病人数

例子输入

10
5
10
160
180
20
110
145
70
100
200

例子输出

8
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define BEGIN_TIME 60
#define END_TIME 180
#define TIME_COST 10

int arrive[MAX_N] = {0};

int main()
{
    int n = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arrive[i];
    sort(arrive, arrive + n);

    for (int curr = 0, time = BEGIN_TIME; curr < n && time < END_TIME; curr++)
    {
        if (arrive[curr] < time)
            time += TIME_COST;
        else
            time = arrive[curr] + TIME_COST;
        if (time < END_TIME)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
