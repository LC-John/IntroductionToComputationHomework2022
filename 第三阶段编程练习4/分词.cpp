/*****
题目描述

给定一个包含n个单词的英文词典和m个只由英文字母组成的字符串。
判断这些字符串能否由词典中的单词组成。
比如词典中包含5个单词："Jim", "and", "cat","like", "dog"
这些单词能组成"Jimlikecatanddog"、"doglikecatandcatlikedog"等，
但是不能组成"catlikeme"
为了简化问题，所有的字母都是小写,而且词典中的所有单词长度都一样。

关于输入

第一行两个正整数，n和m（n，m都不超过100）；
接下来n行，每行一个单词，每个单词长度不超过20；
接下来m行，每行一个字符串，长度不超过1000；

关于输出

m行，表示词库中的单词能否组成该字符串，能输出"Yes"，不能输出"No"。

例子输入

10 5
did
not
and
but
hit
run
cat
dog
pig
cow
cathitdoganddogrun
doghitpigbutpigdidnotrun
pighitcowandcowdidrun
cowhitcatandcatcry
catdogpigandcowarehungry

例子输出

Yes
Yes
Yes
No
No
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 110
#define MAX_WORD_L 30
#define MAX_L 1100

char* dict[MAX_N] = {NULL};     // 字典，使用指针方便排序
int n_dict = 0, l = 0;          // n_dict为字典大小，l为单词长度

/** 对比函数，用于字符串排序 **/
bool cmp(char* a, char* b)
{
    return strncmp(a, b, l) < 0;
}

/** 深度优先搜索，判断是否可以分词 **/
bool dfs(char* s)
{
    int c = 0;
    if (s[0] == '\0')   // 若s已经是空字符串
        return true;    // 说明分词结束，返回true
    for (int i = 0; i < n_dict; i++)    // 遍历dict
    {
        c = strncmp(s, dict[i], l);     // 比对s和c的前l个字符
        if (!c)                         // 若c为0，则相等
            return dfs(s + l);          // 分词，递归深搜
        else if (c < 0)                 // 若c小于0，则dict后面也不可能出现可能的分词
            return false;               // 直接返回false
    }
    return false;
}

int main()
{
    int m = 0;
    char str[MAX_L] = "";

    /** 输入字典并排序 **/
    cin >> n_dict >> m;
    for (int i = 0; i < n_dict; i++)
    {
        dict[i] = new char[MAX_WORD_L];
        cin >> dict[i];
    }
    l = strlen(dict[0]);
    sort(dict, dict + n_dict, cmp);

    while (m--)
    {
        cin >> str;
        if (dfs(str))
            cout << "Yes" <<endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
