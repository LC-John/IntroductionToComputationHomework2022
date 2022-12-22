/*****
题目描述

为了提高能源效率，北京市对居民用电实行阶梯式递增电价，第一档为0~240度（含），
每度电为0.4883元，第二档为241~400度（含），每度电为0.5383元；第三档为400度以
上，每度电为0.7883元。阶梯电价的含义是，如果本月用电量是246度，那么其中240度
执行第一档的价格0.4883×240，超过240度的部分还有6度，执行第二档价格0.5383×6，
实际电费为两档电费的总和。
输入为一个整数，为持有的人民币m，以元为单位。若这m元全部用来购电，求本月可购买
的用电度数d，保留到小数点后两位。

关于输入

输入为一个整数，为持有的人民币m，以元为单位。

关于输出

本月可购买的用电度数d，保留到小数点后两位。

例子输入

100

例子输出

204.79

提示信息

以double类型定义可购买电的度数. setprecision 需 include iomanip
*****/

#include<iostream>
#include<iomanip>
using namespace std;

#define PRICE1 0.4883
#define PRICE2 0.5383
#define PRICE3 0.7883
#define TH1 (240 * 0.4883)
#define TH2 (160 * 0.5383)
#define VOL1 240
#define VOL2 400

int main()
{
	double m;
	cin >> m;
	if (m <= TH1)
		cout << setprecision(2) << fixed << m / PRICE1;
	else if (m <= TH1 + TH2)
		cout << setprecision(2) << fixed << (m - TH1) / PRICE2 + VOL1;
	else
        cout << setprecision(2) << fixed << (m - TH1 - TH2) / PRICE3 + VOL2;
	return 0;
}
