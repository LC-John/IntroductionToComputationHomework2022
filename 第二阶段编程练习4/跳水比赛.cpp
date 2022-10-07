/*****
题目描述

5位跳水高手将参加10米跳台决赛，有好事者让5人据实力预测比赛结果：
A选手说：B第二；我第三。
B选手说：我第二；E第四。
C选手说：我第一；D第二。
D选手说：C最后；我第三。
E选手说：我第四；A第一。

决赛成绩公布之后，每位选手的预测都只对了一半，即一对一错。
请编程解出比赛的实际名次。

关于输入

无。

关于输出

输出5行。第1行输出A的名次，名次从高到低分别用1、2、3、4、5表示；第2、3、4、5行分别输出B、C、D、E的名次。

例子输入

[empty]

例子输出

1
2
3
4
5
*****/

#include <iostream>
using namespace std;

int main()
{
    for (int A = 1; A <= 5; A++)
    for (int B = 1; B <= 5; B++)
    for (int C = 1; C <= 5; C++)
    for (int D = 1; D <= 5; D++)
    for (int E = 1; E <= 5; E++)
    {
        if (A == B || A == C || A == D || A == E || B == C
            || B == D || B == E || C == D || C == E || D == E)  // 排除相同名次
            continue;
        int pA = (B == 2) + (A == 3);   // A预测对的数目
        int pB = (B == 2) + (E == 4);   // B预测对的数目
        int pC = (C == 1) + (D == 2);   // ...
        int pD = (C == 5) + (D == 3);
        int pE = (E == 4) + (A == 1);
        if (pA == pB && pB == pC && pC == pD && pD == pE && pE == 1)
            cout << A << endl << B << endl << C << endl << D << endl << E << endl;
    }
    return 0;
}
