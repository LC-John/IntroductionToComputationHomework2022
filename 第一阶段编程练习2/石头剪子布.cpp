/*****
��Ŀ����

ʯͷ���Ӳ���һ�ֺܼ򵥵���Ϸ��
ʯͷʤ����
����ʤ��
��ʤʯͷ
A��B��ȭ����֪���ǳ�ȭ�����У�������˭ʤ˭����

��������

��һ����һ��������n(n<200)������A��Bһ������n��ȭ��
��������n�У�ÿ�����������֣��ֱ��ʾA��B����β�ȭ�г���ʲô��0��ʾʯͷ��1��ʾ������2��ʾ����

�������

���һ�У�"A"��ʾAʤ��"B"��ʾBʤ��"Tie"��ʾƽ�֡�

��������

4
1 0
2 2
1 2
2 0

�������

A
*****/

#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int n_a_win = 0;
    int a = 0, b = 0;

    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        switch((a - b + 3) % 3) // ʹ����ģ�������
        {
        case 1:         // A��BӮ������A1B0��A2B1��A0B2
            n_a_win--;
            break;      // ע��ʹ��break����switch��䣬����˳��ִ�к���ĳ���
        case 2:         // AӮB�䣬����A0B1��A1B2��A2B0
            n_a_win++;
            break;      // break����
        case 0:         // ƽ�֣�����A0B0��A1B1��A2B2
        default:        // switch��������default��ΪĬ�����
                        // ����ƽ�ֺ�default�ĳ�����Ϊ��һ�µģ���˿��Ժϲ�
            ; // ����䣬���·���...
        }
    }
    if (n_a_win > 0)
        cout << "A" << endl;
    else if (n_a_win < 0)
        cout << "B" << endl;
    else
        cout << "Tie" << endl;
    return 0;
}
