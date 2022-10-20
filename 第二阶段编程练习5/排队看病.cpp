/*****
题目描述

时过境迁，对于非急诊科室的医生，特别是特需门诊坐诊的医生来说，当天挂号来看病的病人已经很少了，
大多数病人都是提前多时进行了预约挂号。在这种情况下，先挂先看的办法有时不一定是最好的。假设有n
个已经挂号的病人，并且根据历史病例和大数据估算医生为每位病人的诊断时间为Ti，请找出这n个人的一
种顺序，使得n个病人的等待时间最小。

关于输入

输入为2行
第一行为n，为等待看病的人数(n<=1000)
第二行分别表示第一位病人到第n位病人的诊断时间T1，T2，…，Tn，每个数据间有一个空格

关于输出

输出为2行
第一行为一种排队顺序，即1到n的一种排列
第二行为这种方案下的平均等待时间（精确到小数点后两位）

例子输入

10
81 365 72 99 22 7 444 203 1024 203

例子输出

6 5 3 1 4 8 10 2 7 9
431.90
*****/

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define MAX_N 1010

struct Patient  // 病人的结构体
{
    int idx;    // 挂号的顺序
    int time;   // 需要的时间
} p[MAX_N] = {{0, 0}};

bool cmp(Patient &a, Patient &b)    // 比较函数，用于排序
{
    return a.time < b.time;
}

int main()
{
    int n = 0;
    double t = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].time;
        p[i].idx = i + 1;
    }
    sort (p, p + n, cmp);   // 排序

    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << p[i].idx;
        t += p[i].time * (n - i - 1);
    }
    cout << endl << setprecision(2) << fixed << t / n;
    return 0;
}
