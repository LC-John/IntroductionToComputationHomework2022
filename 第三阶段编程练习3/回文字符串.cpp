/*****
��Ŀ����

���ľ��������ͷ�����һ�����ַ���,����"radar", "a man, a plan, a canal, panama"(���Կո�ͱ�����).
���д���򣬶���һ���ַ�������Ϊ���ģ������"true"���������"false".

��������

�����������У�ÿ��һ���ַ���,���Ȳ�����100

�������

��Ӧ��ÿһ�����룬���"true"��"false"
ע�⣺�����ַ����еĿո�ͱ�����

��������

radar
  ,  rada     .'" r
radAr

�������

true
true
false
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 110

/** �Ƴ�����src�����пո�ͱ�㣬��������tgt�� **/
void remove_space_and_punctuation(char *src, char *tgt)
{
    for (int i = 0, j = 0; src[i] != '\0'; i++)
        if ((src[i] >= 'a' && src[i] <= 'z') ||
            (src[i] >= 'A' && src[i] <= 'Z') ||
            (src[i] >= '0' && src[i] <= '9'))
            tgt[j++] = src[i];
}

int main()
{
    char buffer[MAX_LEN] = "", str[MAX_LEN] = "";
    while(cin.getline(buffer, MAX_LEN, '\n'))
    {
        /** �Ƴ��ո�ͱ�� **/
        memset(str, '\0', sizeof(str));
        remove_space_and_punctuation(buffer, str);

        /** �жϻ��Ĵ� **/
        strcpy(buffer, str);
        reverse(buffer, buffer + strlen(buffer));
        if (!strcmp(buffer, str))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
