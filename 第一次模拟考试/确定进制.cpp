/*****
题目描述

6*9 = 42 对于十进制来说是错误的，但是对于13进制来说是正确的。因为, 6(13) * 9(13) = 42(13)，
而 42(13) = 4 * 13 + 2 = 54(10)
你的任务是写一段程序读入三个整数p, q和 r，然后确定一个进制 B (2<=B<=16) 使得 p * q = r. 如
果 B有很多选择, 输出最小的一个。例如：  p = 11, q = 11, r = 121. 则有 11(3) * 11(3) = 121(3)
因为 11(3) = 1 * 3 + 1 = 4(10) 和 121(3) = 1 * 3^2 + 2 * 3 + 1 = 16(10)。 对于进制 10,有
11(10) * 11(10) = 121(10)。这种情况下，应该输出 3。如果没有合适的进制，则输出 0。

关于输入

输入有 T组测试样例。 T在第一行给出。每一组测试样例占一行，包含三个整数p, q, r。 p, q, r 的所
有位都是数字，并且1<=p,q, r<=1,000,000

关于输出

对于每个测试样例输出一行。该行包含一个整数，即使得p * q = r成立的最小的B。如果没有合适的B，则
输出 0。

例子输入

3
6 9 42
11 11 121
2 2 2

例子输出

13
3
0
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100

int char2int[MAX_LEN] = {0};

int trans(char* num, int base)
{
    int sum = 0;
    for (int i = 0; num[i] != '\0'; i++)
        if (char2int[num[i]] >= base)
            return -1;
        else
            sum = sum * base + char2int[num[i]];
    return sum;
}

int main()
{
    int n_case = 0;
    memset(char2int, 0xff, sizeof(char2int));
    for (int i = '0'; i <= '9'; i++)
        char2int[i] = i - '0';
    for (int i = 'a'; i <= 'f'; i++)
        char2int[i] = i - 'a' + 10;
    for (int i = 'A'; i <= 'F'; i++)
        char2int[i] = i - 'A' + 10;
    cin >> n_case;
    while (n_case--)
    {
        char a[MAX_LEN] = "\0", b[MAX_LEN] = "\0", c[MAX_LEN] = "\0";
        bool flag = true;
        cin >> a >> b >> c;
        for (int B = 2; B <= 16; B++)
        {
            int _a = trans(a, B), _b = trans(b, B), _c = trans(c, B);
            if (_a < 0 || _b < 0 || _c < 0)
                continue;
            if (_a * _b == _c)
            {
                cout << B << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << 0 << endl;
    }
    return 0;
}
