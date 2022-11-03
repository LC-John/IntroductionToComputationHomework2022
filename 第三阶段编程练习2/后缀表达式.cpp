/*****
题目描述

后缀表达式是指这样的一个表达式：式中不使用括号，运算符号放在两个运算对象之后，
所有计算按运算符号出现的顺序，严格地由左而右新进行（不用考虑运算符的优先级）
如：3*(5-2)+7对应的后缀表达式为：3 5 2 - *  7 + @。’@’为表达式的结束符号。
注意，运算过程中请使用整型进行运算。

关于输入

多行，每行一个用空格分割的后缀表达式。保证表达式长度不超过1000个字符。

关于输出

输出多行，为对应表达式的值。
如果在运算过程中出现除0，则输出NaN。

例子输入

3 5 2 - *  7 + @

例子输出

16
*****/

#include <cstdio>
#include <cstring>
#define MAX_LEN 1010


char buf[MAX_LEN] = "\0";           // 当前输入的数字或符号
long long _stack[MAX_LEN] = {0};    // 当前输入以左的未完成运算的数字
int l = 0;                          // _stack中数字的个数
/** 每当遇到操作符，就取出_stack的最后两个数字进行该运算，并将结果放在_stack末尾 **/

/** Debug **/
void print()
{
    for (int i = 0; i < l; i++)
        printf("%ld ", _stack[i]);
    printf("\t%s\n", buf);
}

int main()
{
    bool nan = false;   // 记录是否出现NaN
    while (scanf("%s", buf) != EOF)
    {
        if (buf[0] != '@' && nan)   // 若已经NaN，则跳过所有操作（除了输出操作）
            continue;
        switch (buf[0])     // 则根据操作符来执行不同的操作
        {
        case '@':                           // 输出操作
            if (nan)                        // 已经NaN
                printf("NaN\n");            // 则输出NaN
            else if (l == 1)                // 否则应该所有运算都结束，此时_stack中应该只有一个数
                printf("%ld\n", _stack[0]); // 若是，则输出_stack中的该数
            else                            // 否则，说明运算出错或输入有误
                printf("Error\n");          // 输出Error
            /** 初始化 **/
            memset(_stack, 0x00, sizeof(_stack));
            l = 0;
            nan = false;
            break;
        case '+': _stack[l - 2] = _stack[l - 2] +  _stack[l - 1]; l--; break;   // 加法操作
        case '-': _stack[l - 2] = _stack[l - 2] -  _stack[l - 1]; l--; break;   // 减法操作
        case '*': _stack[l - 2] = _stack[l - 2] *  _stack[l - 1]; l--; break;   // 乘法操作
        case '/':               // 除法操作
            if (!_stack[l - 1]) // 检查除数不能为零
                nan = true;     // 否则出现NaN
            else
            {
                _stack[l - 2] = _stack[l - 2] /  _stack[l - 1];
                l--;
            }
            break;
        default:                            // 输入的是数字
            sscanf(buf, "%ld", &_stack[l]); // 将其存在_stack末尾等待运算
            l++;
        }
        //print();
    }
    return 0;
}
