/*****
题目描述

有1堆苹果共 m 个，由 n 只猴子按个数平均分配。每次到达苹果堆放地的猴子只有1只，
而且每个猴子都会平均分 1 次苹果。第1个到达的猴子将苹果平均分成 n 等份，但发现
多 k ( k < n )个，于是，将多余的k个扔掉，然后拿走其中的1等份。第 2 个猴子同样
将剩余的苹果又分成 n 等份，也发现多 k 个，并同样将多余的 k 个扔掉，然后拿走其
中1等份。之后的每个猴子都这样（将剩余的苹果又分成 n 等份，也发现多 k 个，并将
多余的 k 个扔掉，然后拿走其中1等份）。假设最后的猴子分配后至少可以拿走1个苹果，
请根据输入的 n 和 k值，计算最小的 m

关于输入

输入猴子数目n 和扔掉的个数 k，其中 k 小于 n，n 和 k 之间以空格间隔。

关于输出

输出最小苹果数目

例子输入

2 1

例子输出

7
*****/

#include <iostream>
using namespace std;

/** 判断n,k,m是否能满足分完的要求 **/
bool divide(int n, int k, int m, int depth) // depth为深度，从0开始
{
    if (depth == n)     // 深度为n，到达最大深度
        return true;    // 递归终止，返回true
    m -= k;     // 扔掉k个
    if (m % n)          // 判断此时是否能恰好分成n堆
        return false;   // 若不能，则返回false
    return divide(n, k, m / n * (n - 1), depth + 1);    // 向下递归，深度加1
}

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	for (int i = 1; ; i++)
        if (divide(n, k, i, 0))
        {
            cout << i << endl;
            return 0;
        }
	return 0;
}
