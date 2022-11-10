/*****
题目描述

给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，并且
1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。

关于输入

第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a (1 < a < 32768)

关于输出

n行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数

例子输入

2
2
20

例子输出

1
4
*****/

#include <iostream>
#include <cmath>
using namespace std;

int ans = 1;    // 搜索结果，初始化为1（即只有这个数本身）

/** 深度优先搜索 **/
void dfs(int a, int curr)  // a为当前数字，curr为搜索到可能的因数
{
	if (curr * curr > a)    // 若curr的平方大于a
		return;             // 则curr不可能是a的因数，返回
    int sq = sqrt(a);   // sq为a可能的因数的上界
	for(int i = curr; i <= sq; i++)
        if (a % i == 0) // 当i是a的因数时
        {
            ans++;      // 多出一种可能的分解方式，ans加1
            dfs(a / i, i);  // 向下递归搜索
        }
}

int main()
{
	int n = 0, num = 0;
	cin >> n;
	while (n--)
	{
		ans = 1;
		cin >> num;
		dfs(num, 2);
		cout << ans << endl;
	}
}
