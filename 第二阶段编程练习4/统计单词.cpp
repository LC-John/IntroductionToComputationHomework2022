/*****
题目描述

计算机信息管理免不了要涉及到文本处理的问题，而在众多处理方式中对一句（段）话中单词数的统计是非常基本也是十分重要的一个环节。

关于输入

一句话，由英文字母，数字及常用标点符号组成。

关于输出

统计句子中各单词出现的次数，并按单词在句子中第一次出现的顺序输出。
输出包括若干行，每一行是一个单词，空格再跟着该单词在句子中出现的次数。

例子输入

A truly great book should be read in youth, again in maturity and once more in old age, as a fine building should be seen by morning light, at noon and by moonlight.

例子输出

A 1
truly 1
great 1
book 1
should 2
be 2
read 1
in 3
youth 1
again 1
maturity 1
and 2
once 1
more 1
old 1
age 1
as 1
a 1
fine 1
building 1
seen 1
by 2
morning 1
light 1
at 1
noon 1
moonlight 1

提示信息

注意一些细节比如单词之间不一定是用空格呀，用空格也不一定只有一个呀，还有整个句子前和最后的标点符号等，注意将这些_从一个整体考虑_，就可以编出比较完美的程序了。^_^
大家加油！
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10000
#define MAX_L 100

char str[MAX_L * MAX_N];
char word[MAX_N][MAX_L];
int cnt[MAX_N];
int n = 0;

bool is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '\'';
}

int main()
{
    int len = 0;
    bool new_word = true;
    bool flag = true;

    /** 读入数据并进行预处理 **/
    memset(word, '\0', sizeof(word));
    memset(cnt, '\0', sizeof(cnt));
    cin.getline(str, MAX_L * MAX_N);
    len = strlen(str);
    for (int i = 0; i < len; i++)   // 遍历字符串
        if (!is_letter(str[i]))     // 若字符不是字母
            str[i] = '\0';          // 则用'\0'标记
                                    // 此时字符串中所有单词被'\0'分隔开，即每个单词都是独立的字符串

    for (int i = 0; i < len; i++)

        /** 当前位置对应了一个单词 **/
        if (is_letter(str[i]))      // 若是字母
        {
            if (new_word)           // 若是单词
            {
                flag = true;        // 该单词是新出现的单词的标记
                new_word = false;   // 后面的字母不再是单词
                for (int j = 0; j < n; j++)
                    if (!strcmp(word[j], str+i))    // 与已经出现过的单词比对
                    {
                        cnt[j]++;
                        flag = false;
                        break;
                    }
                if (flag)   // 该单词是新出现的单词
                {
                    strcpy(word[n], str+i);
                    cnt[n++] = 1;
                }
            }
        }

        /** 后面出现的是完整单词 **/
        else                    // 当前字符不是字母，则后面出现的字母一定是完整的单词
            new_word = true;

    for (int i = 0; i < n; i++)
        cout << word[i] << " " << cnt[i] << endl;
    return 0;
}
