/*****
题目描述

任意给定一个正整数N(N<=100)，计算2的N次方的值。

关于输入

输入只有一个正整数N。

关于输出

输出2的N次方的值。

例子输入

5

例子输出

32
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_LEN 500
char *a = NULL, *b = NULL;

void add()
{
    int c = 0;
    reverse(a, a + strlen(a));
    memset(b, 0x00, MAX_LEN * sizeof(char));
    strcpy(b, a);
    for (int i = 0; a[i] != '\0'; i++)
    {
        a[i] = a[i] - '0' +  b[i] - '0' + c;
        c = a[i] / 10;
        a[i] = '0' + (a[i] % 10);
    }
    if (c)
        a[strlen(a)] = '0' + c;
    reverse(a, a + strlen(a));
}

int main()
{
    int n = 0;
    a = new char[MAX_LEN];
    b = new char[MAX_LEN];
    cin >> n;
    memset(a, 0x00, MAX_LEN * sizeof(char));
    a[0] = '1';
    while (n--)
        add();
    cout << a;
    return 0;
}
