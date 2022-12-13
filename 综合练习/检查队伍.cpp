/*****
题目描述

操场上，小明老师要求同学们站成整齐的一排队伍。在小明老师眼中，只有下面这三种
排队方式才算是整齐的队伍：
1）从左到右，身高从高到低排列，即h1>=h2>=h3...>=hm；（m为排队人数）
2）从左到右，身高从低到高排列，即h1<=h2<=h3...<=hm；
3）从左到右，身高先升高再降低，即h1<=h2<=...<=hi-1<=hi>=hi+1>=...>=hm；
请你写一段代码来帮小明老师检查一下队伍吧。

关于输入

第一行一个整数n，表示后面有n种排队方式。接下来有2n行，每个奇数行为一个整数m，
接下来的一行为m个整数，代表每位同学的身高。1<=n<=10，1<=m<=100。身高的范围
表示为(0, 100].

关于输出

输出共n行。对每种排队方式，如果是整齐的，输出Yes，否则输出No。

例子输入

5
1
50
3
6 6 6
5
10 30 50 70 90
6
65 55 45 50 55 60
10
51 52 53 54 55 54 53 52 51 50

例子输出

Yes
Yes
Yes
No
Yes
*****/

#include <iostream>
using namespace std;

#define MAX_N 110

int q[MAX_N] = {0};
int n = 0;

bool check()
{
    int l = 0, r = n - 1;
    while (l < r && q[l] <= q[l + 1])
        l++;
    while (l < r && q[r - 1] >= q[r])
        r--;
    return l == r;
}

int main()
{
    int n_case = 0;
    cin >> n_case;
    while (n_case--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> q[i];
        if (check())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
