/*****
题目描述

中国有句俗语叫“三天打鱼两天晒网”。某人从1990年1月1日起开始“三天打鱼两
天晒网”，问这个人在以后的某一天中是“打鱼”还是“晒网”。
注意要区分闰年和不是闰年的两种情况

关于输入

输入为三个整数
按照年 月 日 输入为之后的某一天

关于输出

输出为单词
如果今天渔夫打鱼就是
fishing
如果今天晒网就是
sleeping

例子输入

1991 10 25

例子输出

fishing
*****/

#include <iostream>
using namespace std;

#define N_MONTH 12

const int year_nday[2] = {365, 366};
const int month_nday[2][N_MONTH + 1] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap(int y)
{
    if (!(y % 400) || (y % 100 && !(y % 4)))
        return 1;
    return 0;
}

int main()
{
    int year = 0, month = 0, day = 0;
    int cnt = 0, leap = 0;
    while(cin >> year >> month >> day)
    {
        cnt = 0;
        for (int y = 1990; y < year; y++)
            cnt += year_nday[is_leap(y)];
        leap = is_leap(year);
        for (int m = 1; m < month; m++)
            cnt += month_nday[leap][m];
        cnt += day - 1;
        if ((cnt % 5) < 3)
            cout << "fishing" << endl;
        else
            cout << "sleeping" << endl;
    }
    return 0;
}
