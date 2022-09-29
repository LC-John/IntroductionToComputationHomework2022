/*****
题目描述

给定两个年月日，计算之间的天数.
比如2010-1-1和2010-1-3 之间差2天。
year=1,2,...,3000.
补充：
闰年是：(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)，
闰年的2月份有29天。

关于输入

第一行
startYear startMonth startDay
第二行
endYear endMonth endDay

关于输出

输出只有一行是两个日期之间的天数

例子输入

2008 1 1
2009 1 1

例子输出

366
*****/

#include <iostream>
using namespace std;

const int year[2] = {365, 366};     // 平年或闰年的全年天数
const int month[2][13] = {                                 // 各个月份的天数
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    // 平年
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}     // 闰年
};

/** 检查是否是闰年 **/
int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))    // 是闰年
        return 1;                                                  // 返回1
    return 0;                                                      // 否则返回0
}

int main()
{
    int sy = 0, sm = 0, sd = 0;     // 起始年月日
    int ey = 0, em = 0, ed = 0;     // 终止年月日
    int cnt = 0;                    // 天数
    int leap = 0;                   // 是否是闰年
    cin >> sy >> sm >> sd >> ey >> em >> ed;

    /** 从起始年1月1日起到终止年12月31日为止，共计有多少天 **/
    for (int y = sy; y <= ey; y++)
        cnt += year[is_leap(y)];

    /** 去除起始年月日之前的天数 **/
    leap = is_leap(sy);
    for (int m = 1; m < sm; m++)    // 去掉起始月之前的月份（不含起始月）的天数
        cnt -= month[leap][m];
    cnt -= sd;                      // 去除起始日之前，当月的天数（含起始日）

    /** 去除终止年月日之后的天数 **/
    leap = is_leap(ey);
    for (int m = em; m <= 12; m++)  // 去除终止月之后的月份（含终止月）的天数
        cnt -= month[leap][m];
    cnt += ed;                      // 加回来终止日之前，当月的天数（含终止日）
    cout << cnt;
    return 0;
}
