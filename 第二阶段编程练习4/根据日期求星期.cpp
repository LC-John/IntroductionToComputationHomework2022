/*****
题目描述

在不同的国家和地区，时间表示方法各不相同。例如同是2006年5月1日，可以表示为2006-May-01、May-01-2006、01-May-2006等等。
现假定年使用形如 yyyy 的四个数字表示、月使用形如 Mmm 的英文月份简写表示，日使用形如 dd 的两个数字表示，他们之间使用符号
- 或 / 分隔。但他们的在日期中出现的前后顺序不定，请写一个程序，对任意满足本题约束的日期字符串，求该日期是星期几。

关于输入

输入有多行，第一行是一个整数n，表示有多少个待处理的日期字符串。
接着是n行日期字符串，每行一个。
日期范围从1900年1月1日至2099年12月31日。

关于输出

输出有n行，输出对应日期的星期的英文缩写。缩写前后不应有空白字符或其他字符。

例子输入

3
2006-Jun-07
May-01-2006
2006-01-Sep

例子输出

Wed.
Mon.
Fri.
提示信息

星期的英文缩写表：
Sun Mon Tue Wed Thu Fri Sat
月份的英文缩写表：
Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
1900年1月1日是星期一，可以此为基准日期。
注意闰年问题，闰年判定条件为年份能被4整除但不能被100整除，或能被400整除。
本题原理简单，但过程较复杂，需要通过结构化程序设计思想，利用不同的函数处理不同的步骤，实现不同的功能。
*****/

#include <cstdio>
#include <cstring>

#define MAX_LEN 100
#define N_MONTH 12
#define N_WEEK 7


char str[MAX_LEN] = "\0";

const int month_day[2][N_MONTH + 1] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
const int year_day[2] = {365, 366};
const char month_abbr[N_MONTH + 1][MAX_LEN] = {
    "\0", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
const char week_abbr[N_WEEK][MAX_LEN] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

/** 将输入str的字符串解析为年月日 **/
void parse_date(int* y, int* m, int* d) // 通过参数中传入的指针，返回多个数值
{
    char buffer[MAX_LEN] = "\0";
    for(int _begin = 0, _end = 0; true; _end++) // _begin和_end对应字符串中能直接读取的片段（例如年、月或日），区间左闭右开
    {
        if (str[_end] == '-' || str[_end] == '/' || str[_end] == '\0')  // 当_end读到'-'、'/'或'\0'时
        {                                                               // 说明当前能直接读取的片段已经终止，后面是一个新的片段
            memset(buffer, '\0', sizeof(char) * MAX_LEN);
            strncpy(buffer, str + _begin, _end - _begin);   // 将当前片段的字符串拷贝至buffer中
            switch(_end - _begin)           // 检查片段长度
            {
            case 4:                         // 片段长度为4
                sscanf(buffer, "%d", y);    // 则说明该片段对应的是年份，将buffer中的内容写入到y指针中
                break;
            case 3:                                     // 片段长度为3
                for (int i = 1; i <= N_MONTH; i++)      // 则说明该片段对应的是月份
                    if (!strcmp(buffer, month_abbr[i])) // 检查所有月份缩写
                    {
                        *m = i;                         // 将正确的月份写入m指针中
                        break;
                    }
                break;
            case 2:                         // 片段长度为2
                sscanf(buffer, "%d", d);    // 则说明该片段对应的是日期，将buffer中的内容写入到d指针中
                break;
            default: break;
            }
            if (str[_end] == '\0')  // 若此时_end是'\0'
                return;             // 则说明字符串已经解析完毕，函数返回
            _begin = _end + 1;      // 已经完成当前片段的处理，_end后面是一个新的片段，更新_begin为_end+1
        }
    }
}

/** 检查闰年 **/
int is_leap(int y)
{
    if (((y % 100) && !(y % 4)) || !(y % 400))
        return 1;
    return 0;
}

/** 计算日期 **/
int get_week(int year, int month, int day)
{
    int ret = 0, leap = is_leap(year);
    for (int y = 1900; y < year; y++)   // 从1900年起，当year为止（不算year当年）
        ret += year_day[is_leap(y)];    // 共过去了多少天
    for (int m = 1; m < month; m++)     // year当年中，到month为止（不算month当月）
        ret += month_day[leap][m];      // 共过去了多少天
    ret += day;     // year当年，month当月，到day共过去了多少天
                    // 注意计算过去多少天还需要减1，而为了计算星期需要加上1900年1月1日的星期一（即加一）
                    // 一加一减抵消掉，因此可以不作处理
    return ret % N_WEEK;
}

int main()
{
    int n = 0;
    int year = 0, month = 0, day = 0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", str);
        parse_date(&year, &month, &day);    // &表示取year，month，day的内存地址（相当于指针）
        printf("%s.\n", week_abbr[get_week(year, month, day)]);
    }
    return 0;
}
