/*****
��Ŀ����

�Լ��������� 1 �� n �����������У����� x(0 �� x �� 9)�������˶��ٴΣ�
���磬�� 1 �� 11 �У����� 1��2��3��4��5��6��7��8��9��10��11 �У�����
1 ������ 4 �Σ�����2������1�Ρ�

��������

���빲 1 �У����� 2 ������ n��x��֮����һ���ո������

�������

����� 1 �У�����һ����������ʾ x ���ֵĴ�����

��������

11 1

�������

4

��ʾ��Ϣ

�������е����ݣ�1�� n �� 10000��0�� x �� 9��
*****/

#include <iostream>
using namespace std;

#define MAX_DIGIT 10
int cnt[MAX_DIGIT] = {0};

void count_digit(int num, int base)
{
    while (num)
    {
        cnt[num % base]++;
        num /= base;
    }
}


int main()
{
    int n = 0, x = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        count_digit(i, MAX_DIGIT);
    cout << cnt[x] << endl;
    return 0;
}
