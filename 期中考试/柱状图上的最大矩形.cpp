/*****
题目描述

给定n个非负整数，代表柱状图上每个柱的高度（宽度均为1），求这个柱状图中最大的矩形面积。
例如对于输入"2 1 5 6 2 3"，最大面积为10（见下图）

关于输入

第一行是一个整数n，代表有多少个柱形，n小于等于20000
第二行有n个整数，依次为每个柱形的高度

关于输出

一个数字，即这个柱状图中最大的矩形面积，面积最大不超过int的表示范围

例子输入

6
2 1 5 6 2 3

例子输出

10
*****/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 20010

int num[MAX_N];

int main()
{
	int n = 0, res = 0;
	int minh = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++) {
		minh = num[i];
		for (int j = i; j < n; j++) {
			minh = min(minh, num[j]);
			res = max(res, minh * (j - i + 1));
		}
	}
	cout << res << endl;
	return 0;
}
