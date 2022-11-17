/*****
题目描述

把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法
（用K表示）？注意：5，1，1和1，5，1是同一种分发。

关于输入

第一行是测试数据的数目t（0<= t <= 20）,其后的t行均包含两个整数M和N，以空格分开。
1<= M <= 25;
1<= N <= 10;

关于输出

对输入的每组数据M和N，用一行输出相应的K

例子输入

1
7 3

例子输出

8

提示信息

采用递归思想解题。
*****/

#include <iostream>
using namespace std;

int dfs(int apple, int plate)
{
    if (plate == 1)
        return 1;
    if (!apple)
        return 1;
    if (apple >= plate)
        return dfs(apple - plate, plate) + dfs(apple, plate - 1);
    return dfs(apple, apple);
}

int main()
{
    int t = 0, apple = 0, plate = 0;
    cin >> t;
    while(t--)
    {
        cin >> apple >> plate;
        cout << dfs(apple, plate) << endl;
    }
    return 0;
}
