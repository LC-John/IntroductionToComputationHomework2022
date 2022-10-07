/*****
题目描述

北京大学有多个社团申请在圣诞节当天在图书馆南配楼举办 n 个活动，已知每个活动的开始时间和结束时间，
请问如何安排，才能让可举办的活动最多？
（注：如果两个活动的开始结束时间分别为（3,4）(4,5)，这两个活动是相容的）

关于输入

第一行数据为整数n (n < 100,000)，表示申请举办活动的个数；
其余n行每行两个整数，分别是活动的开始时间和结束时间（数值 < 1,000,000）。

关于输出

输出一个整数，为所能举办的活动的最大个数

例子输入

8
41 92
68 160
130 213
151 215
211 265
162 234
145 221
80 137

例子输出

2
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 100100

struct Interval
{
	int _start;
	int _end;
} intervals[MAX_N];

/** 用于排序的比较函数 **/
bool cmp(const Interval &a, const Interval &b)
{
	return a._end < b._end || a._end == b._end && a._start < b._start;
}

int main()
{
	int n = 0;
	int curend = 0, res = 0;

	/** 读入数据并排序 **/
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> intervals[i]._start >> intervals[i]._end;
	sort(intervals, intervals + n, cmp);

	/** 按结束时间贪心 **/
	for (int i = 0; i < n; i++)
    {
		if (intervals[i]._start < curend)
			continue;
		res++;
		curend = intervals[i]._end;
	}
	cout << res << endl;
	return 0;
}
