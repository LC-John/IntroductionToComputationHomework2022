/*****
题目描述

罗马数字包含以下七种字符：I、V、X、L、C、D和M。
字符 数值
I  1
V  5
X  10
L  50
C  100
D  500
M  1000
例如， 整数2写做II，即为两个并列的I。12写做XII，即为X+II。 27写做XXVII, 即为 XX+V+II。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如4不写做IIII，而是IV。
I在V的左边，所表示的数等于大数5减小数1得到的数值4。同样地，数字9表示为IX。这个特殊的规
则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示4和9。
X 可以放在 L (50) 和 C (100) 的左边，来表示40和90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示400和900。
题目要求：实现罗马数字和整数的转换。
1）如果输入是一个罗马数字，将其转换成整数；
2）如果输入是一个整数，将其转换为罗马数字。
无论是何种输入，整数在1到3999的范围内。

输入输出示例：
输入：III
输出：3

输入：4
输出：IV

输入：IX
输出：9

输入：58
输出：LVIII

输入：MCMXCIV
输出：1994
（M = 1000, CM = 900, XC = 90, IV = 4）

关于输入

一行字符（可能是罗马数字，也可能是正整数）

关于输出

如果输入是罗马数字，输出是正整数；
如果输入是正整数，输出是罗马数字。

例子输入

MCMXCIV

例子输出

1994

提示信息

整数是正整数，数值范围1~3999。罗马数字中的字符是大写的。
可采用第一个字符判断输入是整数（0~9）还是罗马数字（不是0~9）。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 5000
#define MAX_LEN 10

int r2n[MAX_N] = {0};
char n2r[MAX_N] = "\0";

void init()
{
    memset(n2r, 0x00, sizeof(n2r));
    n2r[1] = 'I';
    n2r[5] = 'V';
    n2r[10] = 'X';
    n2r[50] = 'L';
    n2r[100] = 'C';
    n2r[500] = 'D';
    n2r[1000] = 'M';
    memset(r2n, 0x00, sizeof(r2n));
    r2n['I'] = 1;
    r2n['V'] = 5;
    r2n['X'] = 10;
    r2n['L'] = 50;
    r2n['C'] = 100;
    r2n['D'] = 500;
    r2n['M'] = 1000;
}

int roman2num(char* str)
{
    int ret = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i + 1] != '\0' && r2n[str[i]] < r2n[str[i + 1]])
            ret -= r2n[str[i]];
        else
            ret += r2n[str[i]];
    return ret;
}

void num2roman(int n, char* ret)
{
    int base = 1000, idx = 0, c = 0;
    while (base)
    {
        c = n / base;
        switch(c)
        {
        case 9:
            ret[idx++] = n2r[base];
            ret[idx++] = n2r[base * 10];
            break;
        case 4:
            ret[idx++] = n2r[base];
            ret[idx++] = n2r[base * 5];
            break;
        default:
            if (c >= 5)
            {
                ret[idx++] = n2r[base * 5];
                c -= 5;
            }
            for (int i = 0; i < c; i++)
                ret[idx++] = n2r[base];
            break;
        }
        n %= base;
        base /= 10;
    }
}

int main()
{
    char s[MAX_LEN] = "\0";
    int n = 0;
    init();
    while (cin >> s)
    {
        if (s[0] >= '0' && s[0] <= '9')
        {
            sscanf(s, "%d", &n);
            memset(s, 0x00, sizeof(s));
            num2roman(n, s);
            cout << s << endl;
        }
        else
            cout << roman2num(s) << endl;
    }
    return 0;
}
