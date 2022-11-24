/*****
题目描述

给定一个长度为n的数组，从其中任意选择不相邻的m个元素形成子数组，求这个子数组所有元素之和的最大值。

关于输入

输入包括两行。
第一行为一个正整数n(0<=n<=10000)。
第二行为n个整数，表示整个数组。

关于输出

输出一个数字，代表数组所有不相邻元素之和的最大值。

例子输入

5

1 2 3 4 5

例子输出

9
*****/

#include <iostream>
#include <algorithm>
using namespace std;

/**
思路：动态规划

用nums表示数组，用dp[i]表示nums从0到i的前缀能形成的符合要求的子数组的和的最大值。
考虑dp[i]（i > 1）要如何计算，有如下两种情况：
1. dp[i]对应的方案中没有取nums[i-1]，那么此时nums[i]是可以取的，这种情况的子数组的和的最大值是dp[i-2] + nums[i]；
2. dp[i]对应的方案中取了nums[i-1]，则此时nums[i]不能取，这种情况的子数组的和的最大值就是dp[i-1]。
两种情况中较大的方案就是dp[i]的方案，因此dp[i] = max(dp[i-2] + nums[i], dp[i-1])。
最后再考虑一下边界条件，dp[0]显然应该是nums[0]，而dp[1] = max(nums[0], nums[1])。
从dp[2]开始逐个计算，最终dp[length(nums) - 1]就是所求的答案。

我们可以进一步优化这个过程。
简单观察可以发现在每一步dp[i]的计算过程中，始终都只与dp[i], dp[i-1], dp[i-2]和nums[i]四个数相关。
那么我们只需要在每一步保留这四个值即可，而不用保存全部nums和dp数组。
**/

int main()
{
    int n = 0, num = 0;
    int dp[3] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (!i)
            dp[0] = num;
        else if (i == 1)
            dp[1] = max(dp[0], num);
        else
            dp[i % 3] = max(dp[(i - 2) % 3] + num, dp[(i - 1) % 3]);
    }
    cout << dp[(n - 1) % 3] << endl;
    return 0;
}
