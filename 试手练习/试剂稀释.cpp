/*****
题目描述

一种药剂可以被稀释成不同的浓度供病人使用，且只能稀释不能增加浓度；又已知医院规定同一瓶药剂
只能给某个病人以及他后面的若干人使用（这若干人不一定要紧挨着排在一起）。现为了能最大限度利
用每一瓶药剂（不考虑每一瓶容量），在给出的一个病人用药浓度队列（病人排队的顺序不能改变）中
找出能同时使用一瓶药剂的最多人数。

关于输入

有两行，第一行是一个整数n，为病人的人数，假设不超过100；第二行为一个浮点数（double）序列，
为病人队列中从队首到队尾每个病人的用药浓度，浮点数之间用一个空格隔开。

关于输出

输出一行，该行包含一个整数，为所求的最大人数。

例子输入

6
0.7 0.9 0.6 0.8 0.8 0.4

例子输出

4

提示信息

用药浓度为 0.9, 0.8, 0.8, 0.4 的四个人可以使用同一瓶依次稀释的药剂（注意这四个人在原来的队
伍中并不紧挨着排在一起）。
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000

double med[MAX_N] = {0};
int cnt[MAX_N] = {0};

int main()
{
    int n = 0, max_cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> med[i];
    cnt[0] = 1;
    for (int i = 1; i < n; i++)
    {
        max_cnt = 0;
        for (int j = 0; j < i; j++)
            if (med[j] >= med[i] && cnt[j] > max_cnt)
                max_cnt = cnt[j];
        cnt[i] = max_cnt + 1;
    }
    max_cnt = 0;
    for (int i = 0; i < n; i++)
        if (cnt[i] > max_cnt)
            max_cnt = cnt[i];
    cout << max_cnt << endl;
    return 0;
}
