/*****
题目描述

给定一个正整数（不超过9位），判断其是否为回文数。所谓回文数是指正向看与逆向看相等的数。
如，123454321，12344321。若是，输出yes,若不是，输出no

关于输入

一个正整数

关于输出

若是，输出yes
若不是，输出no

例子输入

135797531

例子输出

yes
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100

char num[MAX_LEN] = "\0";

/** 递归检查回文 **/
bool check_palindrome(int l, int r) // l和r分别为左右对称位置的下标
{
    if (l >= r)             // 若l超过r，说明已经全都检查完，且之前的部分都满足对称
        return true;        // 则递归终止，返回true
    if (num[l] != num[r])   // 一旦l和r的字符不同，则说明不对称（不是回文）
        return false;       // 则递归终止，直接返回false
    return check_palindrome(l + 1, r - 1);  // l右移一位，r左移一位，递归
}

int main()
{
    cin >> num;
    if (check_palindrome(0, strlen(num) - 1))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
