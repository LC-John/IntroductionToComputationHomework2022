/*****
��Ŀ����

С�����������ڴ������� a ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� b ƿ�ơ�
����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�
�����������ܺȵ�����ƿ�ơ�

��������

�ÿո�ֿ��������������ֱ�Ϊa��b��
1 < a <= 1000000000,
0 <= b <= 1000000000.

�������

�ܺȵ�����ƿ�ơ�

��������

3 9

�������

13
*****/

#include <iostream>
using namespace std;


int main()
{
    long long exchange = 0, wine = 0;
    long long cnt = 0, _empty = 0;

    cin >> exchange >> wine;

    while(wine)
    {
        cnt += wine;
        _empty += wine;
        wine = _empty / exchange;
        _empty = _empty % exchange;
    }

    cout << cnt << endl;
    return 0;
}
