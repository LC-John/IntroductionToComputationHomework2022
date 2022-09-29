/*****
��Ŀ����

һ��ʮ������Ȼ��,�����߽�����Ž��Ʊ�ʾ������λ�������߽�����Ž��Ƶ���λ�����ʾ˳�������෴��
��������Ȼ��,�������ʾ.
����Ϊ1ʱ���������Ȼ����ʮ���Ʊ��ʽ������Ϊ2ʱ���������Ȼ�����߽��Ʊ��ʽ������Ϊ3ʱ�����
����Ȼ���ľŽ��Ʊ��ʽ��

��������

����Ϊ1��2��3�е�һ������

�������

���һ�С�

���Ϊʮ���ƻ��߽��ƻ�Ž�����

��������

1

�������
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 5
#define MIN_NUM 100                     // ��С����λ��
#define MAX_NUM 6 * 7 * 7 + 6 * 7 + 6   // ������λ�����߽����µ�666����ʮ���Ʊ�ʾ��

char* get_digit(int num, int base)
{
    char *digit = new char[MAX_LEN];                // new�ַ�������������ֵ
    int l = 0;
    memset(digit, 0x00, MAX_LEN * sizeof(char));    // ��'\0'�ַ���ʼ�������ַ�����
    /** ����ȡ��base�����¸�λ���� **/
    while(num)
    {
        digit[l++] = num % base + '0';
        num /= base;
    }
    /** �ָ�����˳�� **/
    for (int i = 0; i < l / 2; i++)
    {
        digit[i] ^= digit[l - 1 - i];
        digit[l - 1 - i] ^= digit[i];
        digit[i] ^= digit[l - 1 - i];
    }
    return digit;
}

int main()
{
    int option = 0;
    cin >> option;
    for (int num = MIN_NUM; num <= MAX_NUM; num++)
    {
        char *num_7 = get_digit(num, 7);    // ȡ���߽�����
        char *num_9 = get_digit(num, 9);    // ȡ���Ž�����
        bool flag = true;
        for (int i = 0; i < 3; i++)         // �ȶ�����
            if (num_7[i] != num_9[2 - i])
            {
                flag = false;
                break;
            }
        if (flag)
        {
            switch (option)
            {
            case 1: cout << num << endl; break;
            case 2: cout << num_7 << endl; break;
            case 3: cout << num_9 << endl; break;
            default: break;
            }
            return 0;
        }
        delete[] num_7;     // ɾ��new�����߽����ַ���
        delete[] num_9;     // ɾ��new���ľŽ����ַ���
    }
    return 0;
}
