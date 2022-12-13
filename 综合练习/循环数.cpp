/*****
题目描述

当一个N位的整数X满足下列条件时，称其为循环数：X与任意一个整数1≤Y ≤ N相乘时，都将产生一
个X的“循环”。即：分别将这两个整数的第1位数字与最后1位数字连在一起，可以得到一个相同的数
字循环；当然两个整数在该数字循环中的起始位置不同。例如，142857是一个循环数
142857 *1 = 142857
142857 *2 = 285714
142857 *3 = 428571
142857 *4 = 571428
142857 *5 = 714285
142857 *6 = 857142

关于输入

写一个程序判断一个整数是否是循环数。输入文件是一个整数序列，每个整数长度为2~60。注意：每
个整数前面的零被看作是该整数的一部分，在计算N时要统计。例如“01”是一个2位的整数，而“1”
是一个1位的整数。

关于输出

对每个输入整数，输出一行，说明该整数是否是循环数。

例子输入

142857
142856
142858
01
0588235294117647

例子输出

142857 is cyclic
142856 is not cyclic
142858 is not cyclic
01 is not cyclic
0588235294117647 is cyclic
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_L 200

char num[MAX_L] = "\0";
char mul[MAX_L] = "\0";
int l = 0;

int main()
{
    while (cin >> num)
    {
        bool is_cyclic = true;
        strcpy(mul, num);
        l = strlen(num);
        for (int _Y = 2; _Y <= l; _Y++)
        {
            int carry = 0, st = 0;
            bool found = false;
            if (!is_cyclic)
                break;
            for (int i = l - 1; i >= 0; i--)
            {
                mul[i] = num[i] - '0' + mul[i] - '0' + carry;
                carry = mul[i] / 10;
                mul[i] = mul[i] % 10 + '0';
            }
            if (carry)
            {
                is_cyclic = false;
                break;
            }
            strncpy(mul + l, mul, l);
            for (int i = 0; i < l; i++)
                if (strncmp(mul + i, num, l) == 0)
                {
                    found = true;
                    break;
                }
            if (!found)
            {
                is_cyclic = false;
                break;
            }
        }
        if (is_cyclic)
            cout << num << " is cyclic" << endl;
        else
            cout << num << " is not cyclic" << endl;
    }
    return 0;
}
