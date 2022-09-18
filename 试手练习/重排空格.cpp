/*****
题目描述

给你一个字符串 text，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小
写英文字母组成，并且两个单词之间至少存在一个空格。
请你重新排列空格，使每对相邻单词之间的空格数目都相等，并尽可能最大化该数目。如果不
能重新平均分配所有空格，请将多余的空格放置在字符串末尾，这也意味着输出的字符串应当
与原字符串的长度相等。

关于输入

一行由小写英文字母和空格组成的字符串。
字符串长度不超过1000，至少包含一个单词。

关于输出

一行和原字符串长度相等的字符串。

例子输入

  this   is  a sentence

例子输出

this   is   a   sentence
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 1010
char str[MAX_LEN] = "\0";

int main()
{
    int cnt = 0, len = 0, ws = 0, pad = 0;
    bool flag = false;

    cin.getline(str, MAX_LEN);
    len = strlen(str);

    for (int i = 0; i < len; i++)
        if (str[i] == ' ')
        {
            str[i] = '\0';
            ws++;
        }
        else if ((!i) || str[i - 1] == '\0')
            cnt++;

    if (cnt == 1)
    {
        pad = ws;
        ws = 0;
    }
    else
    {
        pad = ws % (cnt - 1);
        ws /= (cnt - 1);
    }

    for (int i = 0; i < len; i++)
        if (str[i] && ((!i) || (!str[i - 1])))
        {
            if (flag)
                for (int j = 0; j < ws; j++)
                    cout << " ";
            else
                flag = true;
            cout << str + i;
        }
    for (int j = 0; j < pad; j++)
        cout << " ";
    cout << endl;
    return 0;
}
