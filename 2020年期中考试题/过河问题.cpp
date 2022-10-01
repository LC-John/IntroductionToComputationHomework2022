/*****
题目描述

n个人想要过一条河,河上只有一条小船,这条船只能容纳两个人,因此这n个人想要全部过河的
话就必须来回很多次.每个人划船的速度有所不同,两个人一起的时候船的速度是划得较慢的人
的速度.请你找出一种策略使得他们在尽可能短的时间内过河.

关于输入

第一行包括一个正整数t,表示有t组数据.
每组数据两行,第一行是人数n(n<=1000),第二行是n个人各自过河所需的时间(不大于100).

关于输出

输出最短时间

例子输入

1
4
1 2 5 10

例子输出

17
*****/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 1010

int a[MAX_N] = {0}, n = 0;

int main()
{
    int n_case = 0;
    int ans = 0;
	cin >> n_case;
	while (n_case--)
	{
	    ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
            cin >> a[i];
		sort(a, a + n);
		for (int i = n - 1; i >= 3; i -= 2)
		{
			ans += min(a[0] + 2 * a[1] + a[i], 2 * a[0] + a[i - 1] + a[i]);
		}
		if (n % 2 == 0)
            ans += a[1];
		else
            ans += a[0] + a[1] + a[2];
        cout << ans << endl;
	}
	return 0;
}
