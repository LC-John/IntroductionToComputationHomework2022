/*****
题目描述

C语言中的合法标识符的定义为：以下划线或字母开头的字母数字串（含下划线）。
完成一个程序实现对输入的n个字符串进行判定，是否为C语言的合法标识符。如果是则输出1，不是则输出0

关于输入

输入的第一行为一个数字，表明有几个输入字串。
后面每一行为一个长度不超过80的字符串。

关于输出

对所有输入的字符串进行判断，是合法标识符则输出1，回车。否则输出0，回车。

例子输入

5
hello_world
my god
i
_stdio
008A

例子输出

1
0
1
1
0
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 100
#define VALID 1
#define INVALID 0

bool is_letter_or_underline(char c)
{
    return c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int check_valid_identifier(char* id)
{
    if (!is_letter_or_underline(id[0]))
        return INVALID;
    for (int i = 1; id[i] != '\0'; i++)
        if (!(is_digit(id[i]) || is_letter_or_underline(id[i])))
            return INVALID;
    return VALID;
}

int main()
{
    char id[MAX_LEN];
    int n = 0;
    cin >> n;
    cin.get();
    while(n--)
    {
        cin.getline(id, MAX_LEN, '\n');
        cout << check_valid_identifier(id) << endl;
    }
    return 0;
}
