/*****
题目描述

萧桥同学喜欢玩桌游，尤爱三国杀。在三国杀中，延时锦囊牌“闪电”生效（即“中闪电”）的条件是下一
张判定牌为黑桃且牌面数值在2到9之间（包含2和9）。现在告诉你下一张判定牌的花色以及数值，你来判断
一下萧桥同学是否会中闪电？

关于输入

一行，牌的花色与大小。花色在（heitao, hongtao, fangpian, meihua）范围内，大小在1-13范围内。

关于输出

一行，中闪电则输出yes，不中则输出no

例子输入

heitao 3

例子输出

yes
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define CORRECT_COLOR "heitao"
#define RANGE_L 2
#define RANGE_R 9
#define MAX_LEN 10

int main()
{
    char color[MAX_LEN] = "";
    int num = 0;
    cin >> color >> num;
    if (!strcmp(CORRECT_COLOR, color) && num >= RANGE_L && num <= RANGE_R)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
