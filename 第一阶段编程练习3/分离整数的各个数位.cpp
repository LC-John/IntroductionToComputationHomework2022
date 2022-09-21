/*****
题目描述

从键盘输入一个任意的三位整数，要求正确地分离出它
的百位、十位和个位数，并分别在屏幕上输出，输出采
用每行输出一个数的方式，不带其它符号。

关于输入

一个任意的三位整数

关于输出

每行输出一个数位

例子输入

123

例子输出

1
2
3
*****/

#include <iostream>
using namespace std;

#define MAX_DIGIT 100

struct DIGIT                // 用来存取各个数位及数位总数的结构体
{
    int digit[MAX_DIGIT];   // 存放各个数位的数组
    int n;                  // 数位总数
};

/** 该函数方便扩展至任意位数 **/
struct DIGIT* get_digit(int num)
{
    struct DIGIT *ret = NULL;   // 返回值指针
    ret = new struct DIGIT;     // 通过new创建一个指针，在函数返回后，new出来的指针依然存在
                                // 可以通过这种方式来传递较为复杂的返回值

    ret->n = 0;     // 初始化总位数为0；“->”表示访问ret指针所指向的结构体中的成员n
                    // 在另一种情况下，“struct DIGIT tmp;”是一个结构体，则需要使用tmp.n来访问tmp中的成员

    while(num > 0)                          // 当num非0时
    {
        ret->digit[ret->n++] = num % 10;    // 则取num最右位放入数组，总位数加一
        num /= 10;                          // num除以10，向右移动一位
    }
    return ret;
}

int main()
{
    int n = 0;
    struct DIGIT *d = NULL;
    cin >> n;
    d = get_digit(n);
    for (int i = d->n - 1; i >= 0; i--) // 倒序输出d->digit
        cout << d->digit[i] << endl;
    delete d;   // 释放d
    return 0;
}
