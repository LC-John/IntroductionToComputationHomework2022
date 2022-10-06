/*****
题目描述

编写程序，读入一段英文(英文中不包含标点)，将所有单词的顺序倒排并输出，其中单词以空格分隔。

关于输入

输入为一个字符串（字符串长度最大为100）

关于输出

输出为按要求排续后的字符串

例子输入

I am a student

例子输出

student a am I
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 1000
char str[MAX_LEN] = "\0";

int main()
{
    int len = 0;
    cin.getline(str, MAX_LEN, '\n');    // 读入整行字符串
    while(str[len] != '\0')     // 从前向后遍历整个字符串
    {
        if (str[len] == ' ')    // 将空格的位置都标记为'\0'
            str[len] = '\0';
        len++;
    }
    len--;
    while (len >= 0)    // 从后向前遍历整个字符串
    {
        if (!len)           // 若当前位置是起始位置
            cout << str;    // 则输出该单词；此时必然是最后一个输出的单词
        else if (str[len] != '\0' && str[len - 1] == '\0')  // 若当前位置不是'\0'，而前一个位置是'\0'
            cout << str + len << " ";                       // 则说明当前位置是一个单词的起点，输出该单词
        len--;
    }
    return 0;
}
