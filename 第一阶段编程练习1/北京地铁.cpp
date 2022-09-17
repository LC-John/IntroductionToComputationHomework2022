/*****
题目描述

北京地铁涨价了，现在的地铁票价计算方法如下：
6公里内 3元 （包括6公里）
6-12 公里 4元 （不包括6公里，包括12公里）
12-32 公里 每10公里加1元（不包括12公里，包括32公里，不满10公里按10公里算）
32公里以上 每20公里加1元（不包括32公里，不满20公里按20公里算）
比如，50公里时，需要 4+2+1=7元

同时，北京地铁也给出了优惠方案：
每个自然月内，使用交通卡满100元，则票价可打8折；满150元，则票价可打5折；满400元，则票价不打折。

现在，小明有一张公交卡，小明想知道自己现在坐地铁的票价是多少？请你写程序完成这个功能。

关于输入

输入有两个整数，一个是小明现在这个月的累计消费，一个是小明本次乘坐的里程数

关于输出

输出为本次乘坐的票价，保留两位小数

例子输入

120 20

例子输出

4.00
*****/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int expense = 0;    // 本月累计花费
    int dist = 0;       // 乘坐距离
    double price = 0;   // 本次票价
    cin >> expense >> dist;

    /** 根据距离计算票价，此时暂不考虑交通卡打折 **/
    if (dist <= 6)
        price = 3;
    else if (dist <= 12)
        price = 4;
    else if (dist <= 32)
        price = 4 + ceil((dist-12.)/10.);
    else
        price = 4 + 2 + ceil((dist-32.)/20.);

    /** 考虑累计花费，在上一步的票价之上进行打折 **/
    if (expense >= 100 && expense < 150)
        price *= 0.8;
    else if (expense >= 150 && expense < 400)
        price *= 0.5;

    /** 输出两位小数的票价 **/
    cout << setiosflags(ios::fixed) << setprecision(2) << price << endl;
    return 0;
}
