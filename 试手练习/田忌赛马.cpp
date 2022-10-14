/*****
��Ŀ����

��һ�������������Ĺ��°ɣ�
���3ƥ����1000ƥ��������Ȼ�����������ŵ��ӵ�˳���������ɿ��԰�����˳��ѡ���������������Ӯһ�֣�
��ɿ��Եõ�200�����ӣ���һ�֣���ɾ�Ҫ���200�����ӣ�ƽ�ֵĻ����䲻Ӯ��
������������Ӯ��������?

��������

������������������.
ÿ��������ݵĵ�һ����һ������n(1<=n<=1000),��ʾ��ɺ�������ӵ��nƥ��������һ����n����������ʾ���
������ٶȣ���һ��Ҳ��n����������ʾ����������ٶȡ�

����������һ��0��ʾ������

�������

��ÿ�����ݣ����һ����������ʾ����������Ӯ�������ӣ�������Ӯ���ˣ������һ����������ʾ�������Ҫ��
�������ӡ�

��������

3
92 83 71
95 87 74
2
20 20
20 20
2
20 19
22 18
0

�������

200
0
0
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define UNIT 200
#define MAX_N 1010

int ji[MAX_N] = {0}, king[MAX_N] = {0};
int n = 0;

int main()
{
    int ji_fast_idx = 0, ji_slow_idx = 0;
    int king_fast_idx = 0, king_slow_idx = 0;
    int bonus = 0;
    while (cin >> n)
    {
        if (!n)
            return 0;
        ji_fast_idx = n - 1;
        ji_slow_idx = 0;
        king_fast_idx = n - 1;
        king_slow_idx = 0;
        bonus = 0;

        for (int i = 0; i < n; i++)
            cin >> ji[i];
        for (int i = 0; i < n; i++)
            cin >> king[i];
        sort(ji, ji + n);
        sort(king, king + n);

        while(n--)
            if (ji[ji_slow_idx] < king[king_slow_idx])  // King defeats Ji's slowest with King's fastest
            {
                bonus -= UNIT;
                ji_slow_idx++;
                king_fast_idx--;
            }
            else if (ji[ji_slow_idx] > king[king_slow_idx]) // Ji defeats King's slowest with his own slowest
            {
                bonus += UNIT;
                ji_slow_idx++;
                king_slow_idx++;
            }
            else if (ji[ji_fast_idx] > king[king_fast_idx]) // Ji defeats King's fastest with his own fastest
            {
                bonus += UNIT;
                ji_fast_idx--;
                king_fast_idx--;
            }
            else if (ji[ji_slow_idx] < king[king_fast_idx]) // King defeats Ji's slowest with King's fastest
            {
                bonus -= UNIT;
                ji_slow_idx++;
                king_fast_idx--;
            }
            else    // King's fastest vs. Ji's slowest. Tie.
            {
                ji_slow_idx++;
                king_fast_idx--;
            }
        cout << bonus << endl;
    }
    return 0;
}
