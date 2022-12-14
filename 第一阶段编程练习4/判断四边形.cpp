/*****
题目描述

给出平面上a,b,c,d四个点的坐标,依次连接a-b,b-c,c-d,d-a,请你写程序判断得到的图形是否是凸四边形.

关于输入

输入包含多组数据,每组数据一行,包含8个整数(绝对值都不大于1000),依次为a,b,c,d四个点的坐标.

关于输出

对每组输入输出一行,若得到的图形是凸四边形,输出"yes",否则输出"no"

例子输入

0 0 0 1 1 1 1 0
0 0 1 1 0 1 1 0
0 0 0 1 0 2 1 1
0 0 1 1 0 2 2 1

例子输出

yes
no
no
no

提示信息

样例2不是简单多边形,样例3是三角形,样例4是凹四边形
所谓的凸多边形是指: 对于多边形上任意一边所在的直线而言,多边形的整体都在直线的同一侧
可以用向量外积(即叉积)判断点在直线的哪一侧

*****/

#include<iostream>
using namespace std;

int main()
{
	long long x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	long long y1 = 0, y2 = 0, y3 = 0, y4 = 0;
	long long z1 = 0, z2 = 0, z3 = 0, z4 = 0;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
	{

		z1 = (x4 - x1) * (y2 - y1) - (y4 - y1) * (x2 - x1);
		z2 = (x1 - x2) * (y3 - y2) - (y1 - y2) * (x3 - x2);
		z3 = (x2 - x3) * (y4 - y3) - (y2 - y3) * (x4 - x3);
		z4 = (x3 - x4) * (y1 - y4) - (y3 - y4) * (x1 - x4);
		if (z1 * z2 > 0 && z2 * z3 > 0 && z3 * z4 > 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
