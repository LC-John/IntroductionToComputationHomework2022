/*****
��Ŀ����

ĳ����������λ������ѣ����ǿ���ʹ���С�Ӣ��������4�����ԡ�����֪��
A���ס��ҡ��������������ԣ���ֻ��һ�����ԣ�
B����һ������4������3�˶��᣻
C���׻��������������Ҳ���Ӣ�
D������������붡����ֱ�ӽ�̸�����������ֱ�ӽ�̸��
E��û���˼Ȼ�����ֻᷨ�
���ʣ����ұ�������ʲô���ԣ�

��������

��

�������

���ռ��ұ�����˳��������Ǹ��Ի�����ԡ�ÿ�������һ�У��������������ÿո�ָ���У��С�Ӣ����������ֱ���1��2��3��4��ʾ��

��������


�������

��
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
        if (A1 == FRA && A2 == JPN) // �׼Ȼ������ֻᷨ��
            continue;
        for (int B1 = 1; B1 < 4; B1++)
        for (int B2 = B1 + 1; B2 <= 4; B2++)
        {
            if (B1 == FRA && B2 == JPN) // �ҼȻ������ֻᷨ��
                continue;
            for (int C1 = 1; C1 < 4; C1++)
            for (int C2 = C1 + 1; C2 <= 4; C2++)
            {
                if (C1 == FRA && C2 == JPN) // ���Ȼ������ֻᷨ��
                    continue;
                for (int D = 1; D <= 4; D++)
                {
                    int cnt[MAX_N] = {0};
                    if (!(A1 == JPN || A2 == JPN))  // �ײ�������
                        continue;
                    if (!(D != JPN))                // ��������
                        continue;
                    if (!(B1 != ENG && B2 != ENG))  // �һ�Ӣ��
                        continue;
                    if (!(A1 != C1 && A1 != C2 && A2 != C1 && A2 != C2))    // ��������Խ�̸
                        continue;
                    if (!(D != C1 && D != C2))    // ���붡���Խ�̸
                        continue;
                    if (!(B1 == C1 || B1 == C2 || B2 == C1 || B2 == C2))    // ��������ܽ�̸
                        continue;
                    cnt[A1]++;
                    cnt[A2]++;
                    cnt[B1]++;
                    cnt[B2]++;
                    cnt[C1]++;
                    cnt[C2]++;
                    cnt[D]++;
                    for (int i = 1; i <= 4; i++)
                        if (cnt[i] == 3)    // ��һ���������˻ὲ
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
