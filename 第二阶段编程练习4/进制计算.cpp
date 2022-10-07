/*****
��Ŀ����

�������������Ƶ�����ͣ�����ĳ���Ƶķ�ʽ���
(���Ϊ 16���ƣ�����9�����ֱַ��� a��b��c��d��e��f��ʾ)

��������

���빲���У���һ����������һ��Ϊ��������һ��Ϊ�ý��Ƶ���ֵ
�ڶ��к͵�һ�к�����ͬ
������Ϊ����Ľ�����

�������

���Ϊ�������ĺͣ�����Ҫ��Ľ��ƴ�ӡ

��������

5 3
9 8
16

�������

b
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_LEN 100

/** k�����ַ���ת��Ϊʮ������ **/
long long k2ten(char* num, int k)
{
    long long ret = 0;
    for (int i = 0; num[i] != '\0'; i++)
        if (num[i] >= '0' && num[i] <= '9')
            ret = ret * k + (num[i] - '0');
        else
            ret = ret * k + (num[i] - 'a' + 10);
    return ret;
}

/** ʮ������ת��Ϊk�����ַ��� **/
void ten2k(long long num, int k, char* ret)
{
    int idx = 0;
    memset(ret, 0, sizeof(char) * strlen(ret));
    while (num > 0)
    {
        if (num % k < 10)
            ret[idx++] = num % k + '0';
        else
            ret[idx++] = num % k - 10 + 'a';
        num /= k;
    }
    reverse(ret, ret + strlen(ret));    // ��ת����ret�ַ���
}

char str[MAX_LEN] = "\0";

int main()
{
    long long val = 0;
    int k = 0;
    cin >> k >> str;
    val = k2ten(str, k);
    cin >> k >> str;
    val += k2ten(str, k);
    cin >> k;
    ten2k(val, k, str);
    cout << str;
    return 0;
}
