/*****
题目描述

输入一个句子（一行），将句子中的每一个单词翻转后输出

关于输入

只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。

关于输出

翻转每一个单词后的字符串

例子输入

hello world

例子输出

olleh dlrow

提示信息

1. 每个句子都只有一行，是一个只包含空格和字母的字符串。
2. 单词与单词间的空格可能不只一个。
*****/

#include <cstdio>

#define MAX_LEN 1000
char w[MAX_LEN] = "";

bool is_delim(char c)
{
    return c == '\0' || c == ' ';
}

int main()
{
    scanf("%[^\n]", w); // 读入一行字符串

    for (int _begin = 0, _end = 0; w[_end] != '\0'; _end++) // [_begin, _end)区间为一个完整的单词，左闭右开
    {
        if (is_delim(w[_end]))  // 若_end是空格
            printf(" ");        // 则输出空格
        if (_end && is_delim(w[_end - 1]))  // 若_end非0且_end - 1是空格
            _begin = _end;                  // 则更新_begin
        if (!is_delim(w[_end]) && is_delim(w[_end + 1]))    // 若_end不是空格而_end + 1是
            for (int i = _end; i >= _begin; i--)            // 则说明找到了一个完整的单词
                printf("%c", w[i]);                         // 倒序输出该单词
    }
    printf("\n");
    return 0;
}
