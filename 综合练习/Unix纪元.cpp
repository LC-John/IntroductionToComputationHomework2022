/*****
题目描述

在著名的unix系统中，使用了一种简洁高效的时间表示方法，即：
将1970年1月1日0点作为“unix纪元”的原点，从1970年1月1日开始经过的秒数存储为一个32位整数
请编写一个程序，帮助把一个unix时间辍，转换成形如"YYYY-mm-dd HH:ii:ss"的格式，其中的字母分别代表
YYYY    4 位数字完整表示的年份
mm      数字表示的月份，有前导零的 2 位数字
dd        月份中的第几天，有前导零的2位数字
HH       小时，24 小时格式，有前导零
ii          有前导零的分钟数
ss         秒数，有前导零

关于输入

输入数据有若干行，每行包含一个整数t，(0<=t<2^31)

关于输出

对每一行输入数据，输出一行，为形如“YYYY-mm-dd HH:ii:ss”格式的时间

例子输入

10
1234567890

例子输出

1970-01-01 00:00:10
2009-02-13 23:31:30
*****/

#include <cstdio>

#define N_MONTH 12
#define MINUTE_SEC 60
#define HOUR_SEC (60 * 60)
#define DAY_SEC (24 * 60 * 60)

int month[2][N_MONTH + 1] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int year[2] = {365, 366};

int is_leap(int y)
{
    if (((y % 100) && !(y % 4)) || !(y % 400))
        return 1;
    return 0;
}

int main()
{
	unsigned int t = 0;
	int ss = 0, ii = 0, hh = 0, dd = 0, mm = 0, yyyy = 0;
	int days = 0, secs = 0;
	while (scanf("%u", &t) != EOF)
    {
        days = t / DAY_SEC;
        secs = t % DAY_SEC;
        ss = secs % MINUTE_SEC;
        ii = (secs % HOUR_SEC) / MINUTE_SEC;
        hh = secs / HOUR_SEC;
        yyyy = 1970;
        for (yyyy = 1970; days >= year[is_leap(yyyy)]; days -= year[is_leap(yyyy)], yyyy++);
        for (mm = 1; days >= month[is_leap(yyyy)][mm]; days -= month[is_leap(yyyy)][mm], mm++);
        dd = days + 1;
        printf("%d-%02d-%02d %02d:%02d:%02d\n", yyyy, mm, dd, hh, ii, ss);
    }
	return 0;
}
