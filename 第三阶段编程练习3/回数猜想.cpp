/*****
题目描述

回数猜想： 任取一个数，再把它倒过来，并把这两个数相加，然后把这个和数再倒过来，与原和数相
加，重复此过程，一定能获得一个回数。例： 68 倒过来是 86
        68+86= 154，154+451= 605， 605+506=1111 (回数)
编程，输入任意整数，按上述方法产生一个回数，为简便起见，最多计算7步，看是否能得到一个回数。
要求：
主函数中接收键盘数据，显示该数与其倒数的和，输出每一步计算步骤。
子函数1，计算该数的倒数。
子函数2，验证和是否为回数，

关于输入

输入为int型

关于输出

换行输出每步计算过程（最多七步）
输出7步内是否得到一个回数（Y/N）

例子输入

68

例子输出

68+86=154
154+451=605
605+506=1111
Y
*****/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 100
#define MAX_STEP 7

char s[MAX_LEN] = "", r[MAX_LEN] = "";

/** 生成n的倒序字符串 **/
void get_reverse(int n)
{
    sprintf(s, "%d", n);
    strcpy(r, s);
    reverse(r, r + strlen(r));
}

/** 判断n是否回文 **/
bool is_palindromic(int n)
{
    get_reverse(n);
    if (!strcmp(s, r))
        return true;
    return false;
}

int main()
{
    int num = 0, n = 0, rev_num = 0;
    scanf("%d", &num);
    while (n++ < MAX_STEP)
    {
        if (is_palindromic(num))    // 若num回文
        {
            printf("Y\n");          // 则输出Y
            return 0;               // 函数直接返回
        }
        sscanf(r, "%d", &rev_num);                          // 将r中倒序字符串转为int类型存放在rev_num中
        printf("%d+%d=%d\n", num, rev_num, num + rev_num);  // 打印计算步骤
        num += rev_num;                                     // 更新num
    }
    if (is_palindromic(num))    // 判断num是否回文
    {
        printf("Y\n");
        return 0;
    }
    printf("N\n");  // 无法在MAX_STEP内完成，输出N
    return 0;
}
