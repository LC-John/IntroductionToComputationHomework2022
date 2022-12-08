/*****
题目描述

请从4个字符串中找出最长的公共前缀。

关于输入

输入有4行。每行输入是一个字符串（可能包含空格），长度不超过255个字符。

关于输出

所有输入字符串的公共前缀。如果没有公共前缀，则程序不输出内容。

例子输入

Asdfcsdk
Asddf
Asdtes
Asdtexd

例子输出

Asd
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_L 300
#define N 4

char s[N][MAX_L] = {"\0"};
int l = MAX_L;

int main()
{
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        cin.getline(s[i], MAX_L);
        l = min(l, (int)strlen(s[i]));
    }
    for (int i = l; i > 0; i--)
    {
        flag = true;
        for (int j = 1; j < N; j++)
            if (strncmp(s[j], s[j - 1], i))
            {
                flag = false;
                break;
            }
        if (flag)
        {
            for (int j = 0; j < i; j++)
                cout << s[0][j];
            cout << endl;
            return 0;
        }
    }
    return 0;
}
