/*****
题目描述

将 1 到 9 这九个数字分成三个 3 位数，要求第一个 3 位数，正好是
第二个 3 位数的一半，是第三个 3 位数的三分之一，问所有的分法。

关于输入

没有输入。

关于输出

由小到大输出满足条件的三个数字，每个数字之间用一个空格分开。
不同的分法之间，用换行隔开。
假如第一种分法是xxx xxx xxx
第二种分法是*** *** ***
第三种分法是### ### ###
……
那么输出是
xxx xxx xxx
*** *** ***
### ### ###
……

例子输入

没有输入。

例子输出

就不告诉大家答案了: )
*****/

#include <iostream>
using namespace std;

/** 使用递归求解，比九层循环方便 **/
void func(int num, bool *digit)     // num存储三个数字，十进制下每三位对应一个三位数
                                    // digit数组各个记录数码是否被使用过
{
    bool flag = true;   // 记录是否找到未被使用的数码
                        // 若所有数码都被使用过，则应当终止递归

    for (int i = 1; i <= 9; i++)        // 搜索所有数码
        if (!digit[i])                  // 若当前数码未被使用
        {                               // 则
            flag = false;               // flag置为false，表示找到未被使用的数码，继续递归
            digit[i] = true;            // digit[i]置为true，表示该数码被使用过
            func(num * 10 + i, digit);  // 进入下一层递归
            digit[i] = false;           // 从上一层递归退出后，digit数组复原，以便继续搜索
        }

    if (flag)                               // 若所有数码都已经被使用过
    {                                       // 则将num拆解为三个三位数
        int num1 = num / 1000000；
        int num2 = (num / 1000) % 1000；
        int num3 = num % 1000;
        if (num1 * 2 == num2 && num1 * 3 == num3)   // 并判断是否符合条件
            cout << num1 << " " << num2 << " " << num3 << endl;
        return;                                     // 递归终止
    }
}

int main()
{
    bool digit[10] = {false};
    func(0, digit);
    return 0;
}
