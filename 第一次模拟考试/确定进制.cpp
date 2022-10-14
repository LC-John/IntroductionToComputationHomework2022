/*****
��Ŀ����

6*9 = 42 ����ʮ������˵�Ǵ���ģ����Ƕ���13������˵����ȷ�ġ���Ϊ, 6(13) * 9(13) = 42(13)��
�� 42(13) = 4 * 13 + 2 = 54(10)
���������дһ�γ��������������p, q�� r��Ȼ��ȷ��һ������ B (2<=B<=16) ʹ�� p * q = r. ��
�� B�кܶ�ѡ��, �����С��һ�������磺  p = 11, q = 11, r = 121. ���� 11(3) * 11(3) = 121(3)
��Ϊ 11(3) = 1 * 3 + 1 = 4(10) �� 121(3) = 1 * 3^2 + 2 * 3 + 1 = 16(10)�� ���ڽ��� 10,��
11(10) * 11(10) = 121(10)����������£�Ӧ����� 3�����û�к��ʵĽ��ƣ������ 0��

��������

������ T����������� T�ڵ�һ�и�����ÿһ���������ռһ�У�������������p, q, r�� p, q, r ����
��λ�������֣�����1<=p,q, r<=1,000,000

�������

����ÿ�������������һ�С����а���һ����������ʹ��p * q = r��������С��B�����û�к��ʵ�B����
��� 0��

��������

3
6 9 42
11 11 121
2 2 2

�������

13
3
0
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100

int char2int[MAX_LEN] = {0};

int trans(char* num, int base)
{
    int sum = 0;
    for (int i = 0; num[i] != '\0'; i++)
        if (char2int[num[i]] >= base)
            return -1;
        else
            sum = sum * base + char2int[num[i]];
    return sum;
}

int main()
{
    int n_case = 0;
    memset(char2int, 0xff, sizeof(char2int));
    for (int i = '0'; i <= '9'; i++)
        char2int[i] = i - '0';
    for (int i = 'a'; i <= 'f'; i++)
        char2int[i] = i - 'a' + 10;
    for (int i = 'A'; i <= 'F'; i++)
        char2int[i] = i - 'A' + 10;
    cin >> n_case;
    while (n_case--)
    {
        char a[MAX_LEN] = "\0", b[MAX_LEN] = "\0", c[MAX_LEN] = "\0";
        bool flag = true;
        cin >> a >> b >> c;
        for (int B = 2; B <= 16; B++)
        {
            int _a = trans(a, B), _b = trans(b, B), _c = trans(c, B);
            if (_a < 0 || _b < 0 || _c < 0)
                continue;
            if (_a * _b == _c)
            {
                cout << B << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << 0 << endl;
    }
    return 0;
}
