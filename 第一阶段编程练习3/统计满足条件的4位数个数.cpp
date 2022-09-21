/*****
题目描述

编写程序，读入若干个四位数（小于30），求出其中满足以下条件的数的个数：
个位数上的数字减去千位数上的数字，再减去百位数上的数字， 再减去十位数
上的数字的结果大于零。

关于输入

输入为两行，第一行为四位数的个数，第二行为要读入的四位数

关于输出

输出为一行，即满足条件的四位数的个数

例子输入

5
1234 1349 6119 2123 5017

例子输出

3
*****/

#include <iostream>
#include <cstring>
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

    memset(ret->digit, 0x00, sizeof(int) * MAX_DIGIT);  // 初始化ret->digit数组全部为0
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
    int n = 0, num = 0, res = 0;
    struct DIGIT *d = NULL;
    cin >> n;
    while(n--)
    {
        cin >> num;
        d = get_digit(num);
        if (d->digit[0] - d->digit[1] - d->digit[2] - d->digit[3] > 0)
            res++;
        delete d;
    }
    cout << res << endl;
    return 0;
}
