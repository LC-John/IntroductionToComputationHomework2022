/*****
题目描述

给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i]。

关于输入

第一行是一个整数 n，表示数组大小。
接下来 n 行，每行表示数组中的一个数。
0 <= n <= 1000, 每个数都在int可以表示的范围内.

关于输出

n 行，每行代表数组中比它小的数的个数。
如果没有要输出的数据，输出"None"。

例子输入

5
8
1
2
2
3

例子输出

4
0
1
1
3
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1010

struct A
{
    int val;
    int idx;
    int less_cnt;
    int same_cnt;
} a[MAX_N] = {{0, 0, 0, 0}};

bool compare_val(struct A a, struct A b)
{
    return a.val < b.val;
}

bool compare_idx(struct A a, struct A b)
{
    return a.idx < b.idx;
}

int main()
{
    int n = 0;
    cin >> n;

    if (!n)
    {
        cout << "None" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].val;
        a[i].idx = i;
        a[i].less_cnt = 0;
        a[i].same_cnt = 1;
    }

    sort(a, a + n, compare_val);

    for (int i = 1; i < n; i++)
        if (a[i].val == a[i - 1].val)
        {
            a[i].less_cnt = a[i - 1].less_cnt;
            a[i].same_cnt = a[i - 1].same_cnt + 1;
        }
        else
            a[i].less_cnt = a[i - 1].less_cnt + a[i - 1].same_cnt;

    sort(a, a + n, compare_idx);

    for (int i = 0; i < n; i++)
        cout << a[i].less_cnt << endl;

    return 0;
}
