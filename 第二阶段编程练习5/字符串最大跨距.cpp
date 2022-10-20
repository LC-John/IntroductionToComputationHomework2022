/*****
题目描述

有三个字符串S,S1,S2，其中，S长度不超过300,S1和S2的长度不超过10，想检测S1和S2是否同时在S中出现，
且S1位于S2的左边，并在S中互不交叉（即，S1的右边界点在S2的左边界点的左侧）。计算满足上述条件的最
大跨距（即，最大间隔距离：最右边的S2的起始点与最左边的S1的终止点之间的字符数目）。如果没有满足
条件的偶对S1，S2存在，则输出 -1
例如，S = "abcd123ab888efghij45ef67kl", S1="ab", S2="ef"，其中，S1在S中出现了2次，S2也在S中
出现了2次，最大跨距则为：18

关于输入

三个串：S, S2, S3，其间以逗号间隔（注意，S, S2, S3中均不含逗号）；

关于输出

S1和S2在S最大跨距；若在S中没有满足条件的S1和S2，则输出-1

例子输入

abcd123ab888efghij45ef67kl,ab,ef

例子输出

18
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 1000

char s[MAX_LEN] = "", s1[MAX_LEN] = "", s2[MAX_LEN] = "";

int main()
{
    int l = 0, l1 = 0, l2 = 0;
    int left = 0, right = 0;    // left记录s中从左向右s1第一次出现的结尾位置
                                // right记录s中从右向左s2第一次出现的开始位置

    /** 读入数据，预处理各个字符串长度 **/
    cin.getline(s, MAX_LEN, ',');
    cin.getline(s1, MAX_LEN, ',');
    cin.getline(s2, MAX_LEN, '\n');
    l = strlen(s);
    l1 = strlen(s1);
    l2 = strlen(s2);

    /** 在s中从左向右匹配s1 **/
    for (int left1 = 0; left < l; left++)
    {
        if (s1[left1] == s[left])
            left1++;
        else
            left1 = 0;
        if (left1 >= l1)
            break;
    }

    /** 在s中从右向左匹配s2 **/
    right = l - 1;
    for (int right2 = l2 - 1; right >= 0; right--)
    {
        if (s2[right2] == s[right])
            right2--;
        else
            right2 = l2 - 1;
        if (right2 < 0)
            break;
    }

    if (left >= l || right < 0 || right - left <= 0)    // 若s中无法匹配s1或s2，或者s1在s2右侧出现
        cout << -1 << endl;                             // 则不符合要求，输出-1
    else                                                // 否则
        cout << right - left - 1 << endl;               // 输出跨距
    return 0;
}
