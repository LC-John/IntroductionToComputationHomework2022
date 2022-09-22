/*****
题目描述

用牛顿迭代方法求一个数number的平方根，输出根以及迭代次数
注意: (迭代中止条件为 error<=1E-6 )
初始x=1.0
输出格式如下：
引入iostream
引入iomanip
cout << i << ' '
<< setprecision(2)
<< setiosflags(ios::fixed)
<< root << endl;

关于输入

一个数字,double/int均可

关于输出

输出两个数字: 迭代次数 和 根
迭代次数为一个整数
根为一个浮点数,保留小数点后两位

例子输入

12
25
144

例子输出

6 3.46
7 5.00
8 12.00

提示信息

使用 while (cin >> number) 输入数据
*****/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
    double a;
    while (cin >> a)
    {
        double b = 1, c = 0;
        int cnt = 0;
        /** 牛顿法 **/
        while (true)
        {
            c = (b + a / b) / 2;
            cnt++;
            if(fabs(c - b) < 0.000001)
                break;
            b = c;
        }
        cout << cnt << ' ' << setprecision(2)
            << setiosflags(ios::fixed) << c << endl;
    }
}
