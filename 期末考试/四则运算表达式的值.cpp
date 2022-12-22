/*****
题目描述

输入一个包括+、-、*、/和()的四则运算表达式，你能算出表达式的值吗？
这个表达式满足：
1、没有括号不匹配的情况，但可能有嵌套的情形
2、操作数均为整数，但需考虑正负数
3、没有非法表达式，也没有零作除数的情况
4、所有操作都可以视为整型计算，不考虑分数和小数的情况
5、中间结果和最终结果不会超出int的表示范围

关于输入

若干行，每行为一个合法的四则运算表达式

关于输出

若干行，为对应的运算结果

例子输入

1+3+5
5*(3+7)
-(-4/(1+3))*5-1*2*3
+2+3+5

例子输出

9
50
-1
10

提示信息
*****/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX_LEN 100000

char a[MAX_LEN] = "\0";

/** Bracket match **/
int match_bracket(int l, int r)
{
	int cnt = 1, ans = 0;
	for (int i = r - 1; i >= l; i--) {
		if (a[i] == ')')
			cnt++;
		else if (a[i] == '(')
			cnt--;
		if (cnt == 0) {
			ans = i;
			break;
		}
	}
	return ans;
}

int compute(int l, int r)
{
    /** Low priority (addition, subtraction) **/
	for (int i = r; i >= l; i--)
    {
		if (a[i] == ')')
			i = match_bracket(l, i);
		if (a[i] == '+')
			return compute(i + 1, r) + compute(l, i - 1);
		if (a[i] == '-')
			return compute(l, i - 1) - compute(i + 1, r);
	}
	/** Medium priority (multiplication, division) **/
	for (int i = r; i >= l; i--)
	{
		if (a[i] == ')')
			i = match_bracket(l, i);
		if (a[i] == '*')
			return compute(i + 1, r) * compute(l, i - 1);
		if (a[i] == '/')
			return compute(l, i - 1) / compute(i + 1, r);
	}
	/** High priority (bracket) **/
	if (a[r] == ')')
		return compute(l + 1, r - 1);
	/** Number only **/
	if (a[r] >= '0' && a[r] <= '9')
    {
		int ans = 0, j = 0;
		for (int i = r; i >= l; i--, j++)
			ans += pow(10.0, (double)j) * (a[i] - '0');
		return ans;
	}
	return 0;
}

int main()
{
	while (cin.getline(a, MAX_LEN))
		cout << compute(0, strlen(a) - 1) << endl;
	return 0;
}
