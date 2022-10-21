/*****
题目描述

给定 n 个闭区间 [ai; bi]，其中i=1,2,...,n。 我们可以通过添加一些闭区间来使这些区间可以用一个不间断
的闭区间来表示。我们的任务是找出这些需要添加的闭区间中的最小的集合（最小的集合是指这些区间包含的整数
个数总和最小），并将其按照升序输出（所谓升序，即对于区间[a;b]和[c;d]是升序的，当且仅当a ≤ b < c ≤ d），
如果这些区间本来就可以用一个闭区间来表示，则输出”Not Needed”。

关于输入

第一行为一个整数n，3 ≤ n ≤ 50000。表示输入区间的数量。在第i+1行上（1 ≤ i ≤ n），为两个整数 ai
和 bi ，整数之间用一个空格分隔，表示区间 [ai; bi]（其中 1 ≤ ai ≤ bi ≤ 100000）。

关于输出

输出应包括所找到的结果区间中的全部，每行为一个区间，由两个整数中间用一个空格分隔表示，两个整数依次为
该区间的开始数和结尾数，这些区间以升序的顺序输出。如果输入的区间可以用一个闭区间来表示，则输出”Not
Needed”

例子输入

5
5 6
1 4
13 15
6 9
8 10

例子输出

4 5
10 13
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000

struct Range
{
    int l;
    int r;
} range[MAX_N] = {{0, 0}};

bool cmp(Range &a, Range &b)
{
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}

int main()
{
    int n = 0;
    bool flag = true;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> range[i].l >> range[i].r;
    sort(range, range + n, cmp);
    for (int i = 1, l = range[0].r; i < n; i++)
        if (l < range[i].l)
        {
            cout << l << " " << range[i].l << endl;
            l = range[i].r;
            flag = false;
        }
        else if (l < range[i].r)
            l = range[i].r;
    if (flag)
        cout << "Not Needed" << endl;
    return 0;
}
