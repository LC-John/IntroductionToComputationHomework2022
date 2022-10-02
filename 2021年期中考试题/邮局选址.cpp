/*****
题目描述

在一个偏远的地区修建一个邮局，希望选择一个邮局地址，使得邮局到所有的这个地区所有村落的距离之和最小。
在这个问题中，我们假设所有村子位于一条直线上，每一个村子对应一个小于 100000 的整数x，代表村子在这个
直线上的位置，邮局可以选择在直线上的任意一点，可以在一个村落中，也可以不位于村落中。

关于输入

输入由多组测试数据构成。
第一行为一个整数T，代表了测试数据的组数。
每组测试数据中 第一行是一个正整数n，输入数据中保证n大于等于2
第二行为n个数字，代表村落的坐标值。输入数据中保证村落的输入顺序按坐标从小到大排列。

关于输出

对于每组测试数据，每个测试数据输出一行，为一个整数，输出邮局到所有村落的距离之和。

例子输入

3
3
1 2 3
5
1 5 9 12 19
4
1 10 100 1000

例子输出

2
25
1089
*****/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 10000
#define MAX_INT 0x7fffffff

int x[MAX_N] = {0};

int main()
{
    int T = 0, n = 0;
    int ans = MAX_INT, dis = 0;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> x[i];

        ans = MAX_INT;
        for (int i = 1; i < n; i++)
        {
            dis = 0;
            for (int j = 0; j < n; j++)
                dis += abs(x[i] - x[j]);
            if (dis < ans)
                ans = dis;
        }
        cout << ans << endl;
    }
    return 0;
}
