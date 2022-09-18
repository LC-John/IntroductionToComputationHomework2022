/*****
题目描述

输入一个长度小于1000字符串，统计这个字符串中‘*’ ‘@＇出现的次数。

关于输入

只有一行，一个包括可能包括了多个‘*’，’@’

关于输出

一共二行，分别输出二种符号的个数。

例子输入

@sfw3241*　&@*#(!(@$!

例子输出

*出现了2次;
@出现了3次.

提示信息

读入字符串需要用到gets函数。
*****/

#include <iostream>
using namespace std;

#define N_ASCII 300

char ch[N_ASCII] = {'*', '@'};
int n_ch = 2;
int cnt[N_ASCII] = {0};

int main()
{
    int cnt[N_ASCII] = {0};
    char c = '\0';

    while(cin >> c)
        cnt[c]++;

    for (int c = 0; c < n_ch; c++)
    {
        cout << ch[c] << "出现了" << cnt[ch[c]] << "次";
        if (c < n_ch - 1)
            cout << ";" << endl;
        else
            cout << "." << endl;
    }
    return 0;
}
