/*****
题目描述

输入4行全部由大写字母组成的文本，输出一个垂直直方图，给出每个字符出现的次数。
注意：只用输出字符的出现次数，不用输出空白字符，数字或者标点符号的输出次数。

关于输入

输入：包括4行由大写字母组成的文本，每行上字符的数目不超过80个。

关于输出

输出：包括若干行。其中最后一行给出26个大写英文字母，这些字母之间用空格隔开。
前面的几行包括空格和星号，每个字母出现几次，就在这个字母的上方输出一个星号。
注意：输出的第一行不能是空行。每行的末尾不能有空格。每行以#开始

例子输入

THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!

例子输出

#                             *
#                             *
#         *                   *
#         *                   *     *   *
#         *                   *     *   *
# *       *     *             *     *   *
# *       *     * *     * *   *     * * *
# *       *   * * *     * *   * *   * * * *
# *     * * * * * *     * * * * *   * * * *     * *
# * * * * * * * * * * * * * * * * * * * * * * * * * *
# A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 100
#define N_CHAR 300
#define BAR '#'
#define PAD ' '
#define HIST '*'

char str[MAX_LEN] = "";
int cnt[N_CHAR] = {0};

int main()
{
    int max_cnt = 0, n_pad = 0;
    while (cin >> str)
    {
        for (int i = 0; str[i] != '\0'; i++)
            if (max_cnt < ++cnt[str[i]])
                max_cnt = cnt[str[i]];
    }
    for (int i = max_cnt - 1; i >= 0; i--)
    {
        n_pad = 0;
        cout << BAR;
        for (char c = 'A'; c <= 'Z'; c++)
            if (cnt[c] > i)
            {
                for (int j = 0; j < n_pad; j++)
                    cout << " " << PAD;
                cout << " " << HIST;
                n_pad = 0;
            }
            else
                n_pad++;
        cout << endl;
    }
    cout << BAR;
    for (char c = 'A'; c <= 'Z'; c++)
        cout << " " << c;
    cout << endl;
    return 0;
}
