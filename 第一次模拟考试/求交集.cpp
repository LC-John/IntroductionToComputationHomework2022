/*****
题目描述

给定两个整数集合，输出交集，输出时，按元素从小到大的顺序输出，以逗号间隔。
注意：给定的集合中可能有重复元素，但输出的交集中不能有重复元素。如果没有交集，则输出 NULL
例：
集合A：1,3,5,6,10,6,8,11
集合B: 2,4,8,6,10,6,12,13
那么，输出为：
6,8,10

关于输入

2行，每行表示一个集合的元素序列，元素之间以逗号间隔，假定每个集合不超出200个元素。

关于输出

两个集合的交集，按元素从小到大输出，以逗号间隔。如果没有交集，则输出 NULL

例子输入

1,3,5,6,10,6,8,11
2,4,8,6,10,6,12,13

例子输出

6,8,10

提示信息

集合中元素的个数请自己想办法确定
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
#define MASK 0x7fffffff

int num1[MAX_N] = {0}, cnt1 = 0;
int num2[MAX_N] = {0}, cnt2 = 0;

int main()
{
    int n = 0;
    char c = '\0';
    bool flag = true;
    while (cin >> n)
    {
        cin.get(c);
        num1[cnt1++] = n;
        if (c != ',')
            break;
    }
    sort(num1, num1 + cnt1);
    for (int i = 1; i < cnt1; i++)
        if (num1[i] == num1[i - 1])
            num1[i - 1] = MASK;

    while (cin >> n)
    {
        cin.get(c);
        num2[cnt2++] = n;
        if (c != ',')
            break;
    }
    sort(num2, num2 + cnt2);

    for (int i = 0; i < cnt2; i++)
        for (int j = 0; j < cnt1; j++)
        {
            if (num2[i] == num1[j])
            {
                if (flag)
                    flag = false;
                else
                    cout << ",";
                cout << num1[j];
                num1[j] = MASK;
            }
        }
    if (flag)
        cout << "NULL";
    cout << endl;

    return 0;
}
