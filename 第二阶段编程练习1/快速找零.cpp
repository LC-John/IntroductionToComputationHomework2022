/*****
题目描述

J.P.Flathead的杂货店在收银台上雇佣廉价的劳动力。他雇的人（常常是高中的孩子）常常找错钱给顾客。Flathead是个小气鬼，
估计他找错的钱比他挣的还要多，也就是说，雇员往往找更多的钱给客户。
Flathead想要你编写一个程序来计算他应该找多少quarters（$0.25）、dimes($0.10)、nickel($0.05)和pennies($0.01)给顾
客。如果要找的钱是5.00美元或者更少，Flathead尽量找给他们硬币。他也想找给顾客最少数量的硬币。比如，要找给顾客的钱是
1.24美元，那么，顾客应当拿到4quarters、2dimes、0nickels和4pennies。

关于输入

输入数据的第一行是一个正整数N，表示下面数据集的个数。每个数据集是由一个整数组成，占一行，这个整数代表cents（美分），
C（1 <= C <= 500）

关于输出

对于每个数据集，打印出数据集的序号，一个空格和下面这串字符串：
Q QUARTER(S), D DIME(S),n NICKEL(S),P PENNY(S)
这里，Q是quarters数目，D是dimes数目，n是nickels数目，而P是pennies数目。

例子输入

3
124
25
194

例子输出

1 4 QUARTER(S),2 DIME(S),0 NICKEL(S),4 PENNY(S)
2 1 QUARTER(S),0 DIME(S),0 NICKEL(S),0 PENNY(S)
3 7 QUARTER(S),1 DIME(S),1 NICKEL(S),4 PENNY(S)
*****/

#include <iostream>
using namespace std;

#define MAX_N 4
#define MAX_L 100
int value[MAX_N] = {25, 10, 5, 1};  // 各个面值大小
char currency[MAX_N][MAX_L] = {     // 各个面值对应名称
    "QUARTER(S)", "DIME(S)", "NICKEL(S)", "PENNY(S)"
};

int main()
{
    int n = 0, change = 0, cnt = 0;
    cin >> n;
    for (int _case = 1; _case <= n; _case++)
    {
        cout << _case << " ";
        cin >> change;
        /** 按面值从大到小贪心找钱即可 **/
        for (int v = 0; v < MAX_N; v++)
        {
            cnt = change / value[v];
            change = change % value[v];
            if (v > 0)
                cout << ",";
            cout << cnt << " " << currency[v];
        }
        cout << endl;
    }
    return 0;
}
