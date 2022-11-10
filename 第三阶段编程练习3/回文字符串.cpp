/*****
题目描述

回文就是正读和反读都一样的字符串,例如"radar", "a man, a plan, a canal, panama"(忽略空格和标点符号).
请编写程序，读入一行字符串，若为回文，则输出"true"，否则输出"false".

关于输入

输入有若干行，每行一个字符串,长度不超过100

关于输出

对应于每一行输入，输出"true"或"false"
注意：忽略字符串中的空格和标点符号

例子输入

radar
  ,  rada     .'" r
radAr

例子输出

true
true
false
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 110

/** 移除所有src中所有空格和标点，结果存放在tgt中 **/
void remove_space_and_punctuation(char *src, char *tgt)
{
    for (int i = 0, j = 0; src[i] != '\0'; i++)
        if ((src[i] >= 'a' && src[i] <= 'z') ||
            (src[i] >= 'A' && src[i] <= 'Z') ||
            (src[i] >= '0' && src[i] <= '9'))
            tgt[j++] = src[i];
}

int main()
{
    char buffer[MAX_LEN] = "", str[MAX_LEN] = "";
    while(cin.getline(buffer, MAX_LEN, '\n'))
    {
        /** 移除空格和标点 **/
        memset(str, '\0', sizeof(str));
        remove_space_and_punctuation(buffer, str);

        /** 判断回文串 **/
        strcpy(buffer, str);
        reverse(buffer, buffer + strlen(buffer));
        if (!strcmp(buffer, str))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
