/*****
��Ŀ����

��ţ�ٵ���������һ����number��ƽ������������Լ���������
ע��: (������ֹ����Ϊ error<=1E-6 )
��ʼx=1.0
�����ʽ���£�
����iostream
����iomanip
cout << i << ' '
<< setprecision(2)
<< setiosflags(ios::fixed)
<< root << endl;

��������

һ������,double/int����

�������

�����������: �������� �� ��
��������Ϊһ������
��Ϊһ��������,����С�������λ

��������

12
25
144

�������

6 3.46
7 5.00
8 12.00

��ʾ��Ϣ

ʹ�� while (cin >> number) ��������
*****/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
    double a;
    while (cin >> a)
    {
        double b = 1, c = 0;
        int cnt = 0;
        /** ţ�ٷ� **/
        while (true)
        {
            c = (b + a / b) / 2;
            cnt++;
            if(fabs(c - b) < 0.000001)
                break;
            b = c;
        }
        cout << cnt << ' ' << setprecision(2)
            << setiosflags(ios::fixed) << c << endl;
    }
}
