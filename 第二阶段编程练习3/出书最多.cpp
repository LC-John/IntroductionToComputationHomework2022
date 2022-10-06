/*****
题目描述

假定图书馆新进了m（10 ≤ m ≤ 999）本图书，它们都是由n（2 ≤ n ≤ 26）个作者独立或相互合作编著的。
假设m本图书编号为整数（1到999），作者的姓名为字母（'A'到'Z'），请根据图书作者列表找出参与编著图书最
多的作者和他的图书列表。

关于输入

第一行为所进图书数量m，其余m行，每行是一本图书的信息，其中第一个整数为图书编号，接着一个空格之后是一
个由大写英文字母组成的没有重复字符的字符串，每个字母代表一个作者。

关于输出

输出有多行：
第一行为出书最多的作者字母；
第二行为作者出书的数量；
其余各行为作者参与编著的图书编号（按输入顺序输出）。

例子输入

11
307 F
895 H
410 GPKCV
567 SPIM
822 YSHDLPM
834 BXPRD
872 LJU
791 BPJWIA
580 AGMVY
619 NAFL
233 PDJWXK

例子输出

P
6
410
567
822
834
791
233

提示信息

输入数据保证仅有一个作者出书最多。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_AUTHOR 300
#define MAX_BOOK 1000

int book[MAX_AUTHOR][MAX_BOOK] = {0};   // 记录每个作者写的书的编号，book['D']数组就记录了'D'写过的书
int cnt[MAX_AUTHOR] = {0};              // 记录每个作者写了多少本书，cnt['D']就记录了'D'写过多少本书

int main()
{
    int n = 0, l = 0;
    int max_cnt = 0;
    char max_author = '\0';
    int num = 0;
    char author[MAX_AUTHOR] = "\0";

    cin >> n;
    while(n--)
    {
        cin >> num >> author;
        l = strlen(author);
        for (int i = 0; i < l; i++)
        {
            book[author[i]][cnt[author[i]]++] = num;    // 更新book和cnt数组
            if (cnt[author[i]] > max_cnt)               // 更新max_cnt和max_author
            {
                max_cnt = cnt[author[i]];
                max_author = author[i];
            }
        }
    }

    cout << max_author << endl << max_cnt << endl;
    for (int i = 0; i < cnt[max_author]; i++)
        cout << book[max_author][i] << endl;
    return 0;
}
