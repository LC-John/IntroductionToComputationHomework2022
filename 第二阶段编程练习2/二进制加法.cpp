/*****
��Ŀ����

���������������� a �� b ������ a + b ֮�ͣ�����͵Ķ����Ʊ�ʾ��

��������

������ 2n + 1 �У���һ���� n������2n�У�ÿ����һ�飬��һ���Ƕ������� a���ڶ����Ƕ������� b��a �� b
������ 0 �Ҳ���ǰ�� 0 ��a��b ��λ�������� 100 λ��

�������

��� n �� a + b �Ľ�����ö����Ʊ�ʾ��

��������

2
1110011
11111111000
1010101
101010

�������

100001101011
1111111

��ʾ��Ϣ

�� n ��ȡֵû���ر�����ƣ�ֻ��Ҫ��֤ n ����Ȼ�����ɡ�
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 300


int debug(char* str, int len)
{
    for (int i = 0; i < len; i++)
        cout << str[i];
    cout << endl;
    return 0;
}

/** ��ת�ַ������������֧��strrev���� **/
char* str_reverse(char* str, int len)
{
    int i = len / 2;
    if (len % 2 == 1)
        i++;
    for (; i < len; i++)
    {
        str[i] = str[i] ^ str[len-1-i];
        str[len-1-i] = str[i] ^ str[len-1-i];
        str[i] = str[i] ^ str[len-1-i];
    }
    return str;
}

int main()
{
    int n_case = 0;
    char *a = NULL, *b = NULL;  // �������ַ�����ʹ��ָ�룬������н���
    char c = '0';               // ��¼��λ
    int la = 0, lb = 0;         // �����ĳ���
    cin >> n_case;
    while(n_case--)
    {
        /** ��ʼ��&�������� **/
        c = '0';
        a = new char[MAX_N];    // new���㹻���ȵ��ַ�����
        b = new char[MAX_N];
        memset(a, 0, sizeof(char) * MAX_N);     // ��'\0'��ʼ���ַ����������λ��
        memset(b, 0, sizeof(char) * MAX_N);
        cin >> a >> b;
        la = strlen(a);     // strlen�����ַ������ȣ���Ҫcstring
        /**
       la = 0;
       while (a[la++] != '\0'); // Ҳ����ʹ����һ�������㳤��
       **/
        lb = strlen(b);

        /** ׼������ **/
        if (la < lb)        // ��a����b
        {
            char* tmp = a;  // �򽻻�a��b��ָ��
            a = b;
            b = tmp;
            la = strlen(a); // ������a��b�ĳ���
            lb = strlen(b);
        }
        a = str_reverse(a, la);  // ��תa��b��ʹ���λ����
        b = str_reverse(b, lb);
        memset(b + lb, '0', sizeof(char) * (la - lb));  // ��'0'����b��ʹ��b��aһ����
        //debug(a, la);
        //debug(b, la);

        /** ��λ���� **/
        for (int i = 0; i < la; i++)                    // ʹ��a[i]��b[i]��c��λ���м���
            switch ((a[i] - '0') + (b[i] - '0') + c)    // ����õ���λ�������a[i]��
            {                                            // ��λ���´���c��
                case '0': a[i] = '0'; c = '0'; break;
                case '1': a[i] = '1'; c = '0'; break;
                case '2': a[i] = '0'; c = '1'; break;
                case '3': a[i] = '1'; c = '1'; break;
            }

        /** ������&�ͷſռ� **/
        if (c > '0')    // ��c����0,
            cout << c;  // ��˵��������һλ�������c
        for (int i = la - 1; i >= 0; i--)   // ����a���λ��ǰ����˵������a
            cout << a[i];
        cout << endl;
        delete[] a; // �ͷ�new�����ַ�����
        delete[] b;
    }
    return 0;
}
