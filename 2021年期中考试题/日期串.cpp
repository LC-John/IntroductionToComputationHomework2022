/*****
题目描述

今天是 2021 年 1 月 3 日，定义日期字符串 s 为把从今天开始到 9999 年 12 月 31 日的日期依次写下得到的字符串：
s = 202101032021010420210105...99991231
现在，给出 n 个数字 a[1] ... a[n]，你需要对于每一个数字求出它第一次在 s 中出现的位置（s 的下标从 1 开始）。

关于输入

第一行输入一个整数 n，表示数字的个数 (1 <= n <= 100)。
接下来每行输入一个整数，表示 a[i] (0 <= a[i] <= 100)。

关于输出

输出 n 行，每行一个整数，表示答案。如果 a[i] 在 s 中没有出现，则输出 -1.

例子输入

5
0
5
9
14
97

例子输出

2
24
56
95
222059
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define S_LEN 50000000
#define A_LEN 10
#define MAX_DIGIT 10

char s[S_LEN] = "\0";
int len = 0;

int month[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

char* get_digit(int num)
{
    char *ret = new char[MAX_DIGIT];
    memset(ret, '0', sizeof(char) * MAX_DIGIT - 1);
    int l = 0;
    while(num > 0)
    {
        ret[l++] = num % 10 + '0';
        num /= 10;
    }
    return ret;
}

int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

int generate_day(int y, int m, int d, int curr)
{
    char* ymd[3] = {get_digit(y), get_digit(m), get_digit(d)};
    int l_ymd[3] = {4, 2, 2};
    for (int j = 0; j < 3; j++)
    {
        for (int i = l_ymd[j] - 1; i >= 0; i--)
            s[curr++] = ymd[j][i];
        delete[] ymd[j];
    }
    s[curr] = '\0';
    return curr;
}

int generate_month(int y, int m, int curr)
{
    int leap = is_leap(y);
    for (int i = 1; i <= month[leap][m]; i++)
        curr = generate_day(y, m, i, curr);
    return curr;
}

int generate_year(int y, int curr)
{
    for (int i = 1; i <= 12; i++)
        curr = generate_month(y, i, curr);
    return curr;
}

void generate_s()
{
    for (int i = 3; i <= 31; i++)
        len = generate_day(2021, 1, i, len);
    for (int i = 2; i <= 12; i++)
        len = generate_month(2021, i, len);
    for (int i = 2022; i <= 2099; i++)
        len = generate_year(i, len);
}

int main()
{
    int n = 0;
    char a[A_LEN] = "\0";
    generate_s();
    cin >> n;
    while(n--)
    {
        cin >> a;
        cout << strstr(s, a) - s + 1 << endl;
    }
    return 0;
}
