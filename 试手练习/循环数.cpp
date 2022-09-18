/*****
��Ŀ����

��һ��Nλ������X������������ʱ������Ϊѭ������X������һ������1��Y �� N���ʱ��������
��һ��X�ġ�ѭ�����������ֱ������������ĵ�1λ���������1λ��������һ�𣬿��Եõ�һ��
��ͬ������ѭ������Ȼ���������ڸ�����ѭ���е���ʼλ�ò�ͬ�����磬142857��һ��ѭ����
142857 *1 = 142857
142857 *2 = 285714
142857 *3 = 428571
142857 *4 = 571428
142857 *5 = 714285
142857 *6 = 857142

��������

дһ�������ж�һ�������Ƿ���ѭ�����������ļ���һ���������У�ÿ����������Ϊ2~60��ע�⣺
ÿ������ǰ����㱻�����Ǹ�������һ���֣��ڼ���NʱҪͳ�ơ����硰01����һ��2λ����������
��1����һ��1λ��������

�������

��ÿ���������������һ�У�˵���������Ƿ���ѭ������

��������

142857
142856
142858
01
0588235294117647

�������

142857 is cyclic
142856 is not cyclic
142858 is not cyclic
01 is not cyclic
0588235294117647 is cyclic
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_L 200

char num[MAX_L] = "\0";
char mul[MAX_L] = "\0";
int l = 0;

int main()
{
    while (cin >> num)
    {
        bool is_cyclic = true;
        strcpy(mul, num);
        l = strlen(num);
        for (int _Y = 2; _Y <= l; _Y++)
        {
            int carry = 0, st = 0;
            bool found = false;
            if (!is_cyclic)
                break;
            /* Large integer addition */
            for (int i = l - 1; i >= 0; i--)
            {
                mul[i] = num[i] - '0' + mul[i] - '0' + carry;
                carry = mul[i] / 10;
                mul[i] = mul[i] % 10 + '0';
            }
            if (carry)
            {
                is_cyclic = false;
                break;
            }
            /* Check cyclic */
            strncpy(mul + l, mul, l);
            for (int i = 0; i < l; i++)
                if (strncmp(mul + i, num, l) == 0)
                {
                    found = true;
                    break;
                }
            if (!found)
            {
                is_cyclic = false;
                break;
            }
        }
        if (is_cyclic)
            cout << num << " is cyclic" << endl;
        else
            cout << num << " is not cyclic" << endl;
    }
    return 0;
}
