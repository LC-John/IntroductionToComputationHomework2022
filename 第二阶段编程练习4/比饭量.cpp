/*****
题目描述

3个人比饭量，每人说了两句话：
A说：B比我吃的多，C和我吃的一样多
B说：A比我吃的多，A也比C吃的多
C说：我比B吃得多，B比A吃的多。
事实上，饭量和正确断言的个数是反序的关系。
请编程按饭量的大小输出3个人的顺序（可按升序输出）。
备注：三人的饭量和正确断言数都各不相同

关于输入

无输入

关于输出

按照饭量大小输出3人顺序，比如：
ABC

例子输入

无

例子输出

无
*****/

#include <iostream>
using namespace std;

int main()
{
    for (int A = 1; A <= 3; A++)
    for (int B = 1; B <= 3; B++)
    for (int C = 1; C <= 3; C++)
    {
        if (A == B || A == C || B == C)  // 排除相同饭量
            continue;
        int pA = (B > A) + (A == C);    // A预测对的数目
        int pB = (A > B) + (A > C);     // B预测对的数目
        int pC = (C > B) + (B > A);     // ...
        if (pA == pB || pA == pC || pB == pC)    // 排除相同断言数目
            continue;
        if ((A > B && pA > pB) || (A < B && pA < pB))   // 判断AB的饭量和断言正确数目是否反序
            continue;
        if ((A > C && pA > pC) || (A < C && pA < pC))   // 判断AC的饭量和断言正确数目是否反序
            continue;
        if ((B > C && pB > pC) || (B < C && pB < pC))   // ...
            continue;

        if (A > B && A > C && B > C)
            cout << "CBA";
        else if (A > B && A > C && C > B)
            cout << "BCA";
        else if (B > A && B > C && A > C)
            cout << "CAB";
        else if (B > A && B > C && C > A)
            cout << "ACB";
        else if (C > A && C > B && A > B)
            cout << "BAC";
        else if (C > A && C > B && B > A)
            cout << "ABC";
    }
    return 0;
}
