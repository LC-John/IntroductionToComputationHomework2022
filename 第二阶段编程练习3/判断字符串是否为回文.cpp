/*****
��Ŀ����

��̣�����һ���ַ�����������ַ����Ƿ���ġ�

��������

����Ϊһ���ַ������ַ�����û�пհ��ַ����ַ������Ȳ�����100����

�������

����ַ����ǻ��ģ����yes���������no��

��������

abcdedcba

�������

yes

��ʾ��Ϣ

������ָ˳���͵�����һ�����ַ�����
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 1000
char str[MAX_LEN] = "\0", str_rev[MAX_LEN] = "\0";

/** ��ת�ַ��� **/
void my_strrev(char* s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)   // �����Գ�λ�õ��ַ�
    {
        s[i] ^= s[len - 1 - i];
        s[len - 1 - i] ^= s[i];
        s[i] ^= s[len - 1 - i];
    }
}

int main()
{
    cin >> str;
    strcpy(str_rev, str);   // ��str���Ƶ�str_rev��
    //strrev(str_rev);  // �������֧��ʹ��strrev���������ֻ���Լ�ʵ��һ��my_strrev����������ת�ַ���
    my_strrev(str_rev);     // ��str_rev��ת
    if (!strcmp(str_rev, str))  // �ȶ�str��str_rev�Ƿ�һ��
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
