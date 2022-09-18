/*****
题目描述

一个字符串的前缀是从该字符串的第一个字符起始的一个子串。例如 "carbon"的字串是: "c", "ca", "car", "carb", "carbo",
和 "carbon"。注意到这里我们不认为空串是字串, 但是每个非空串是它自身的字串. 我们现在希望能用前缀来缩略的表示单词。
例如, "carbohydrate" 通常用"carb"来缩略表示. 现在给你一组单词, 要求你找到唯一标识每个单词的最短前缀
在下面的例子中，"carbohydrate" 能被缩略成"carboh", 但是不能被缩略成"carbo" (或其余更短的前缀) 因为已经有一个单词
用"carbo"开始
一个精确匹配会覆盖一个前缀匹配，例如，前缀"car"精确匹配单词"car". 因此 "car" 是 "car"的缩略语是没有二义性的,“car”
不会被当成"carriage"或者任何在列表中以"car"开始的单词.

关于输入

输入包括至少2行，至多1000行. 每行包括一个以小写字母组成的单词，单词长度至少是1，至多是20.

关于输出

输出的行数与输入的行数相同。每行输出由相应行输入的单词开始，后面跟着一个空格接下来是相应单词的没有二义性的最短前缀
标识符。

例子输入

carbohydrate
cart
carburetor
caramel
caribou
carbonic
cartilage
carbon
carriage
carton
car
carbonate

例子输出

carbohydrate carboh
cart cart
carburetor carbu
caramel cara
caribou cari
carbonic carboni
cartilage carti
carbon carbon
carriage carr
carton carto
car car
carbonate carbona
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_L 30
#define MAX_N 1010

char str[MAX_N][MAX_L + MAX_L], pre[MAX_L];
int n = 0;

/* Check whether s is a prefix of any string in str,
    besides str[index] */
bool in(char *s, int index)
{
    for (int i = 0; i < n; i++)
    {
        if (i == index)
            continue;
        if (strstr(str[i], s) == str[i])
            return true;
    }
    return false;
}

int main()
{
    while (cin >> str[n++]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(str[i]); j++)
        {
            memset(pre, 0, sizeof(pre));
            strncpy(pre, str[i], j+1);
            if (strcmp(pre, str[i]) == 0 || !in(pre, i))
            {
                strcat(str[i], " ");
                strcat(str[i], pre);
                break;
            }
        }
        cout << str[i] << endl;
    }
    return 0;
}
