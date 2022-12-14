/*****
题目描述

计算表达式(a+b)*c的值，其中a, b, c均为整数，且a,b,c的值介于-10000和
10000之间（不含-10000和10000）

关于输入

输入仅一行，包括三个整数a, b和c

关于输出

输出也是一行，即表达式的值

例子输入

2 3 5

例子输出

25
*****/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;    // 考虑一下数据类型是使用32位的int还是64位的long long
                    // 32位的int（带符号）的表示范围是-2147483648到2147483647
                    // 即便a、b、c都取到最极端情况，也不会发生溢出
                    // 因此可以使用int类型
    cin >> a >> b >> c;
    cout << (a + b) * c << endl;
    return 0;
}
