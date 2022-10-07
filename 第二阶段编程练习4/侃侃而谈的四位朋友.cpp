/*****
题目描述

某宾馆来了四位外宾朋友，他们可能使用中、英、法、日4种语言。现已知：
A．甲、乙、丙各会两种语言，丁只会一种语言；
B．有一种语言4人中有3人都会；
C．甲会日语，丁不会日语，乙不会英语；
D．甲与丙、丙与丁不能直接交谈，乙与丙可以直接交谈；
E．没有人既会日语，又会法语。
请问：甲乙丙丁各会什么语言？

关于输入

无

关于输出

按照甲乙丙丁的顺序，输出他们各自会的语言。每个人输出一行，如会多种语言则用空格分割。其中，中、英、法、日语分别用1、2、3、4表示。

例子输入


例子输出

略
*****/

#include <iostream>
using namespace std;

#define MAX_N 10
#define CHN 1
#define ENG 2
#define FRA 3
#define JPN 4

int main()
{
    for (int A1 = 1; A1 < 4; A1++)
    for (int A2 = A1 + 1; A2 <= 4; A2++)
    {
        int cnt[MAX_N] = {0};
        if (A1 == FRA && A2 == JPN) // 甲既会日语又会法语
            continue;
        for (int B1 = 1; B1 < 4; B1++)
        for (int B2 = B1 + 1; B2 <= 4; B2++)
        {
            if (B1 == FRA && B2 == JPN) // 乙既会日语又会法语
                continue;
            for (int C1 = 1; C1 < 4; C1++)
            for (int C2 = C1 + 1; C2 <= 4; C2++)
            {
                if (C1 == FRA && C2 == JPN) // 丙既会日语又会法语
                    continue;
                for (int D = 1; D <= 4; D++)
                {
                    int cnt[MAX_N] = {0};
                    if (!(A1 == JPN || A2 == JPN))  // 甲不会日语
                        continue;
                    if (!(D != JPN))                // 丁会日语
                        continue;
                    if (!(B1 != ENG && B2 != ENG))  // 乙会英语
                        continue;
                    if (!(A1 != C1 && A1 != C2 && A2 != C1 && A2 != C2))    // 甲与丙可以交谈
                        continue;
                    if (!(D != C1 && D != C2))    // 丙与丁可以交谈
                        continue;
                    if (!(B1 == C1 || B1 == C2 || B2 == C1 || B2 == C2))    // 乙与丙不能交谈
                        continue;
                    cnt[A1]++;
                    cnt[A2]++;
                    cnt[B1]++;
                    cnt[B2]++;
                    cnt[C1]++;
                    cnt[C2]++;
                    cnt[D]++;
                    for (int i = 1; i <= 4; i++)
                        if (cnt[i] == 3)    // 有一种语言三人会讲
                        {
                            cout << A1 << " " << A2 << endl;
                            cout << B1 << " " << B2 << endl;
                            cout << C1 << " " << C2 << endl;
                            cout << D << endl;
                        }
                }
            }
        }
    }
    return 0;
}
