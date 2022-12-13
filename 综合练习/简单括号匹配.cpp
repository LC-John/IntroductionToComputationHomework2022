/*****
题目描述

在程序设计中，括号常用于表示运算的优先顺序。括号总是成对出现的。当每个正括号的右边有相匹配的反括号，
并且每个反括号的左边有相匹配的正括号时，就认为括号匹配。像式子：(3+4)*(5 以及(3+4))*(5 ，括号就不匹
配。输入带有圆括号的式子后，请检验其中的圆括号是否匹配(假设输入的符号数不超过300个)。若不匹配，则输
出mismatch；若匹配，则输出匹配对（在序列中的位置）
注意：字符串从 0 开始编号，即：起始字符的编号为 0

关于输入

带圆括号的一串符号

关于输出

若圆括号不匹配，则输出 mismatch
否则，输出匹配对，每行输出1对（左括号的位置以及相应的右扩号位置），以逗号间隔；下一行的左括号位置值
大于上一行的左括号位置值

例子输入

(abc+5)def(()edf)

例子输出

0,6
10,16
11,12
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_LEN 1010

char s[MAX_LEN] = "\0";
int st[MAX_LEN] = {0}, n_st = 0;

struct Pair
{
    int l;
    int r;
} ans[MAX_LEN] = {{0, 0}};
int n_ans = 0;

bool cmp(const Pair &a, const Pair &b)
{
    return a.l < b.l;
}

bool match()
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == '(')
            st[n_st++] = i;
        else if (s[i] == ')')
        {
            if (!n_st)
                return false;
            ans[n_ans].l = st[--n_st];
            ans[n_ans++].r = i;
        }
    return !n_st;
}

int main()
{
    cin >> s;
    if (match())
    {
        sort(ans, ans + n_ans, cmp);
        for (int i = 0; i < n_ans; i++)
            cout << ans[i].l << "," << ans[i].r << endl;
    }
    else
        cout << "mismatch" << endl;
    return 0;
}
