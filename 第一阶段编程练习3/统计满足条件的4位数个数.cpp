/*****
��Ŀ����

��д���򣬶������ɸ���λ����С��30����������������������������ĸ�����
��λ���ϵ����ּ�ȥǧλ���ϵ����֣��ټ�ȥ��λ���ϵ����֣� �ټ�ȥʮλ��
�ϵ����ֵĽ�������㡣

��������

����Ϊ���У���һ��Ϊ��λ���ĸ������ڶ���ΪҪ�������λ��

�������

���Ϊһ�У���������������λ���ĸ���

��������

5
1234 1349 6119 2123 5017

�������

3
*****/

#include <iostream>
#include <cstring>
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

    memset(ret->digit, 0x00, sizeof(int) * MAX_DIGIT);  // ��ʼ��ret->digit����ȫ��Ϊ0
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
    int n = 0, num = 0, res = 0;
    struct DIGIT *d = NULL;
    cin >> n;
    while(n--)
    {
        cin >> num;
        d = get_digit(num);
        if (d->digit[0] - d->digit[1] - d->digit[2] - d->digit[3] > 0)
            res++;
        delete d;
    }
    cout << res << endl;
    return 0;
}
