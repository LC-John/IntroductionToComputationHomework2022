/*****
��Ŀ����

ҩѧԺ����Сѧ��2018�꽫�����ʽ����У԰�γ̣�Ҫ�����пγ̾�Ҫ��ϱ�̽��н�ѧ�����ǣ���ʦҩ�۸Ǹ�ͬѧ��
������һ����ͥ��ҵ��Ҫ�����ñ�̣�ͳ�Ƴ�һ�������еĴ�д��ĸ������Сд��ĸ�����Լ����ָ�������ҩ��ʦ�Լ�
�����̣������鷳���æдһ����Ϊ��׼�𰸡�

��������

һ�г���Ϊn��Ӣ����ĸ��0 < n <=256��

�������

һ�У���д��ĸ������Сд��ĸ�����Լ����ָ�������Ϊ����������֮����һ���ո����

��������

AbCdEf gHiJkL 123456

�������

6 6 6

��ʾ��Ϣ

����������а����ո�
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 1000

#define OTHER 0     // ������ĸ������
#define UPPER 1     // ��д��ĸ
#define LOWER 2     // Сд��ĸ
#define DIGIT 3     // ����

/** ����ַ��Ǵ�Сд���֡����ֻ������� **/
int check_char(char c)
{
    if (c >= 'A' && c <= 'Z')
        return UPPER;   // ����UPPER����1
    if (c >= 'a' && c <= 'z')
        return LOWER;   // ����LOWER����2
    if (c >= '0' && c <= '9')
        return DIGIT;   // ����DIGIT����3
    return OTHER;       // ����OTHER����0
}

int main()
{
    int l = 0;                  // �ַ�������
    int cnt[DIGIT + 1] = {0};   // �����ַ�����
    char str[MAX_LEN] = "\0";   // ������ַ���

    /** ����һ���ַ��� **/
    cin.getline(str, MAX_LEN, '\n');    // �ڳ���MAX_LEN�����'\n'ʱ��ֹ

    /** �����ַ����� **/
    while (str[l] != '\0')
        cnt[check_char(str[l++])]++;
    /** // �����ַ������ȵķ���
    l = 0;
    while (str[l++] != '\0');
    **/

    for (int i = UPPER; i <= DIGIT; i++)
    {
        if (i != UPPER)
            cout << " ";
        cout << cnt[i];
    }
    cout << endl;
    return 0;
}
