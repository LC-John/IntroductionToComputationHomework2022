/*****
��Ŀ����

�Ӽ�������һ���������λ������Ҫ����ȷ�ط������
�İ�λ��ʮλ�͸�λ�������ֱ�����Ļ������������
��ÿ�����һ�����ķ�ʽ�������������š�

��������

һ���������λ����

�������

ÿ�����һ����λ

��������

123

�������

1
2
3
*****/

#include <iostream>
using namespace std;

#define MAX_DIGIT 100

struct DIGIT                // ������ȡ������λ����λ�����Ľṹ��
{
    int digit[MAX_DIGIT];   // ��Ÿ�����λ������
    int n;                  // ��λ����
};

/** �ú���������չ������λ�� **/
struct DIGIT* get_digit(int num)
{
    struct DIGIT *ret = NULL;   // ����ֵָ��
    ret = new struct DIGIT;     // ͨ��new����һ��ָ�룬�ں������غ�new������ָ����Ȼ����
                                // ����ͨ�����ַ�ʽ�����ݽ�Ϊ���ӵķ���ֵ

    ret->n = 0;     // ��ʼ����λ��Ϊ0����->����ʾ����retָ����ָ��Ľṹ���еĳ�Աn
                    // ����һ������£���struct DIGIT tmp;����һ���ṹ�壬����Ҫʹ��tmp.n������tmp�еĳ�Ա

    while(num > 0)                          // ��num��0ʱ
    {
        ret->digit[ret->n++] = num % 10;    // ��ȡnum����λ�������飬��λ����һ
        num /= 10;                          // num����10�������ƶ�һλ
    }
    return ret;
}

int main()
{
    int n = 0;
    struct DIGIT *d = NULL;
    cin >> n;
    d = get_digit(n);
    for (int i = d->n - 1; i >= 0; i--) // �������d->digit
        cout << d->digit[i] << endl;
    delete d;   // �ͷ�d
    return 0;
}
