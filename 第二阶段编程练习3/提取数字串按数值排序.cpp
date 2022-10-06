/*****
题目描述

输入一串不超过300个字符的符号序列，请将其中的所有数字串提出，并将每个数字串作为整数看待
（假设可以用int 表示），按从小到大顺序输出结果，输出的整数之间以逗号间隔。如果没有数字，
则输出0；例如：*1234.345#6781ad9jk81-11101?aght88ir09kp，其中的整数包括：1234，345，
6781，9，81，11101，88，9，从小到大排序后，应该输出：
9，9，81，88，345，1234，6781，11101

关于输入

在一行内输入一串符号

关于输出

从小到大排序的整数序列，如果没有数字，则输出0；

例子输入

*1234.345#6781ad9jk81-11101?aght88ir09kp

例子输出

9,9,81,88,345,1234,6781,11101
*****/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 1000
char str[MAX_LEN] = "\0";
int num[MAX_LEN] = {0};
int cnt = 0;

bool is_digit(char c)   // 判断字符是否是一个数码
{
    return c >= '0' && c <= '9';
}

int main()
{
    scanf("%[^\n]", str);   // 整行读入字符串

    for (int i = 0; str[i] != '\0'; i++)                        // 从起始位置起遍历整个字符串
        if (is_digit(str[i]) && (!i || !is_digit(str[i-1])))    // 若当前位置是一个数字的起始位置
            sscanf(str + i, "%d", &num[cnt++]);                 // 则使用sscanf将数字从str中读入到num数组

    if (!cnt)   // 没有数字的特殊情况
    {
        printf("0\n");
        return 0;
    }

    sort(num, num + cnt);   // 对num数组排序

    printf("%d", num[0]);
    for (int i = 1; i < cnt; i++)
        printf(",%d", num[i]);
    printf("\n");

    return 0;
}
