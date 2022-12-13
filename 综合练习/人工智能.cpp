/*****
题目描述

人工智能一直是计算机学所追求的一个很高的境界，全世界的计算机学家们至今仍在不断努力力求达到
这个境界。
这道题也跟“人工智能”有关。
学过初中物理的同学都应该知道物理学中的这个公式P（功率）= U（电压）* I（电流）。如果给定其
中的任意两个值，第三个值都是很容易求的，这个就是本题的任务。

关于输入

既然是人工智能，不要妄想题目会直接告诉你其中的某两个值。
输入的第一行是一个整数，表示有多少组测试数据。以下每一行是一组测试数据，分别为一句英文句子。
你需要从中识别已知和未知，并且求出未知量。需要说明的是，句子中I，U，P三个物理量中已知的两
个一定会以I=xA, U=xV，P=xW这样的样式给出（注意单位以及大小写）。在这样的表达式中，可能会
在单位（A，V，W）的前面出现表示数量级的字母m、k、M，分别表示毫，千，兆。

关于输出

对于每一组数据，按以下格式输出三行：
首先输出"Problem #k"，k表示当前是第k组测试数据。
然后在下一行输出结果，结果要求单位必须为A，V或者W，并且保留两位小数。
最后再输出一个空行。
具体可以参见样例输出。

例子输入

3
If the voltage is U=200V and the current is I=4.5A, which power is generated?
A light-bulb yields P=100W and the voltage is U=220V. Compute the current, please.
bla bla bla lightning strike I=2A bla bla bla P=2.5MW bla bla voltage?

例子输出

Problem #1
P=900.00W

Problem #2
I=0.45A

Problem #3
U=1250000.00V

提示信息

提示：数字后面的m、k、M，分别代表0.001， 1000，1000000.
例如：2m = 2 * 0.001
*****/

#include <iostream>
#include <iomanip>
using namespace std;

double get_value()
{
    double val = 0;
    char c = '\0';
    cin >> val;
    c = cin.get();
    switch(c)
    {
    case 'm': return val * 0.001;
    case 'k': return val * 1000;
    case 'M': return val * 1000000;
    default: return val;
    }
}

int main()
{
    int n;
    cin >> n; cin.get();
    for (int _case = 1; _case <= n; _case++)
    {
        double P = -1, U = -1, I = -1;
        char c = '\0', last_c = '\0';
        while (c = cin.get())
        {
            if (c == '\n')
                break;
            if (c == '=' && last_c == 'I')
                I = get_value();
            if (c == '=' && last_c == 'U')
                U = get_value();
            if (c == '=' && last_c == 'P')
                P = get_value();
            last_c = c;
        }
        cout << "Problem #" << _case << endl;
        if (P < 0)
            cout << "P=" << fixed << setprecision(2) << U * I << "W" << endl << endl;
        else if (I < 0)
            cout << "I=" << fixed << setprecision(2) << P / U << "A" << endl << endl;
        else
            cout << "U=" << fixed << setprecision(2) << P / I << "V" << endl << endl;
    }
    return 0;
}
