/*****
题目描述

各种语言都充满了缩略语。如汉语上的“非典（非典型性肺炎）”，“北大（北京大学）”，英语上的
“SARS(Severe Atypical Respiratory Syndrome)”。假定某个字符串A中的每个字符出现在另一个
字符串S中不同的位置（大小写完全相同），且字符串 A 中字符的前后关系在 S 中不发生改变，同时，
A的长度小于S的长度，就认为 A 是 S 的一个可能缩略语。现在任意给定两对串，请判断前面的串是否
是后面串的可能缩略语。若是，则输出 YES，否则，输出 NO

关于输入

第1行为串对数目n；
后面 n 行中，每行是一对字符串，其间以冒号间隔（判断左边的串是否是右边串可能的缩略语），假定
左边串的长度不大于30个字符，右边串的长度不大于300个字符。

关于输出

若有n对，则有 n 行输出，每行对应判断的结果。若是可能的缩略语，输出YES；若否，输出 NO

例子输入

6
AB:ACDEbFBkBD
AR:ACDBrT
SARS:Severe Atypical Respiratory Syndrome
ACDEFBD:AB
ABD:ACDEDkBY
ABBR:ACDEDkBRT

例子输出

YES
NO
YES
NO
NO
NO
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 1000

char abbr[MAX_LEN] = "", str[MAX_LEN] = "";

int main()
{
    int n = 0;
    int abbr_idx = 0, str_idx = 0;
    cin >> n;
    cin.get();      // 跳过输入缓冲区中的'\n'，防止影响cin.getline读入数据
    while (n--)
    {
        abbr_idx = 0;
        str_idx = 0;
        cin.getline(abbr, MAX_LEN, ':');    // 读入abbr，直到长度达到MAX_LEN上限或者遇到','终止
        cin.getline(str, MAX_LEN, '\n');    // 同上，读入str

        /** 处理特殊情况，abbr的长度不短于str **/
        if (strlen(abbr) >= strlen(str))
        {
            cout << "NO" << endl;
            continue;
        }

        /** 遍历abbr和str **/
        while(abbr[abbr_idx] != '\0' && str[str_idx] != '\0')
        {
            if (abbr[abbr_idx] == str[str_idx]) // 当abbr中字符与str中字符一样
                abbr_idx++;                     // 则abbr_idx向右移动一位
            str_idx++;                          // 不论如何，str_idx向右移动一位
        }

        /** 输出 **/
        if (abbr[abbr_idx] != '\0')     // abbr_idx指向字符不为'\0'
            cout << "NO" << endl;       // 则说明abbr没有与str完全匹配
        else                            // 否则
            cout << "YES" << endl;      // abbr与str完全匹配
    }
    return 0;
}
