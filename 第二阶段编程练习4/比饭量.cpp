/*****
��Ŀ����

3���˱ȷ�����ÿ��˵�����仰��
A˵��B���ҳԵĶ࣬C���ҳԵ�һ����
B˵��A���ҳԵĶ࣬AҲ��C�ԵĶ�
C˵���ұ�B�Եö࣬B��A�ԵĶࡣ
��ʵ�ϣ���������ȷ���Եĸ����Ƿ���Ĺ�ϵ��
���̰������Ĵ�С���3���˵�˳�򣨿ɰ������������
��ע�����˵ķ�������ȷ��������������ͬ

��������

������

�������

���շ�����С���3��˳�򣬱��磺
ABC

��������

��

�������

��
*****/

#include <iostream>
using namespace std;

int main()
{
    for (int A = 1; A <= 3; A++)
    for (int B = 1; B <= 3; B++)
    for (int C = 1; C <= 3; C++)
    {
        if (A == B || A == C || B == C)  // �ų���ͬ����
            continue;
        int pA = (B > A) + (A == C);    // AԤ��Ե���Ŀ
        int pB = (A > B) + (A > C);     // BԤ��Ե���Ŀ
        int pC = (C > B) + (B > A);     // ...
        if (pA == pB || pA == pC || pB == pC)    // �ų���ͬ������Ŀ
            continue;
        if ((A > B && pA > pB) || (A < B && pA < pB))   // �ж�AB�ķ����Ͷ�����ȷ��Ŀ�Ƿ���
            continue;
        if ((A > C && pA > pC) || (A < C && pA < pC))   // �ж�AC�ķ����Ͷ�����ȷ��Ŀ�Ƿ���
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
