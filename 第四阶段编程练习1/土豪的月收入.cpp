/*****
题目描述

阿福因为程序写的好，阿拉伯酋长希望拉他去当王子，条件是让阿福写个程序统计国家每个月卖石油的收入。
阿福觉得这个机会也可以让他成为没有大学文凭却走上人生巅峰的众多传奇人物中的一员。乔布斯，比尔盖茨
不都没有大学毕业嘛！可是按照当地的货币单位，每个月的收入太大了用int以至于long long也存不下了，
为了成功娶到名叫钱多多的阿拉伯公主，阿福决定拼一把。
每个月的账单包括n条收入记录，每条记录是长度不大于200的一个正整数，设计一个程序，计算出每个月的
总收入。

关于输入

输入第一行为一个整数n，代表共有n个收入记录，输入保证n大于2但不大于100
接下来是n行，每行为一个长度不大于200的正整数

关于输出

输出为一行，代表所有收入的总和，结果中不能有多余的前导0。

例子输入

5
18446744073709551616
4294967296
0088888888888888888888888
1233211234567
12345567896666666661666616

例子输出

12434475232300866766308983
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_LEN 300
char *a = NULL, *b = NULL;

void add()
{
    int c = 0;
    reverse(a, a + strlen(a));
    reverse(b, b + strlen(b));
    if (strlen(a) < strlen(b))
        for (int i = strlen(a); b[i] != '\0'; i++)
            a[i] = '0';
    else
        for (int i = strlen(b); a[i] != '\0'; i++)
            b[i] = '0';
    for (int i = 0; a[i] != '\0'; i++)
    {
        a[i] = a[i] - '0' +  b[i] - '0' + c;
        c = a[i] / 10;
        a[i] = '0' + (a[i] % 10);
    }
    if (c)
        a[strlen(a)] = '0' + c;
    reverse(a, a + strlen(a));
}

int main()
{
    int n = 0;
    a = new char[MAX_LEN];
    b = new char[MAX_LEN];
    cin >> n;
    cin >> a;
    while(--n)
    {
        cin >> b;
        add();
    }
    cout << a << endl;
    return 0;
}
