/*****
��Ŀ����

���ڱ���δ��BBS�Ƚ�֪�������������ڿ͹�������ˣ���ÿ���˵��˻����ԣ�
����Խ���ӣ����ڿ��ƽ�Ŀ����Ծ�Խ�͡�ͨ�����ԣ����������ɲ���������
�ַ���ɣ������¹����ж������Ƿ�ȫ��
1. ������볤��С��6λ���򲻰�ȫ
2. ������������ַ�ֻ��һ�࣬�򲻰�ȫ
3. ������������ַ������࣬��Ϊ�жȰ�ȫ
4. ������������ַ�����������ϣ���Ϊ��ȫ
ͨ���������֡���д��ĸ��Сд��ĸ���������Ź�Ϊ���಻ͬ���ַ���

��������

����ĵ�һ����һ������n������������n���������롣����n��ÿ�д���һ
�����룬ÿ������ĳ��Ⱦ�С��50���ַ��������ո񣩡�

�������

���ÿһ�������жϲ�������Ƿ�ȫ�����ڲ���ȫ���������"Not safe"��
�����жȰ�ȫ���������"Medium safe"�����ڰ�ȫ���������"Safe"

��������

5
1234
abcdefg
123safe
432*fe+93
AD7doiuo31

�������

Not safe
Not safe
Medium safe
Safe
Safe
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 100

enum CharType
{
    NUMBER = 0,
    LOWER,
    UPPER,
    OTHER,
    CHAR_TYPE_COUNT
};

enum SafeLevel
{
    NOT_SAFE,
    MEDIUM_SAFE,
    SAFE
};

CharType getCharType(char c)
{
    if (c >= '0' && c <= '9')
        return NUMBER;
    if (c >= 'a' && c <= 'z')
        return LOWER;
    if (c >= 'A' && c <= 'Z')
        return UPPER;
    return OTHER;
}

SafeLevel getSafeLevel(char* str)
{
    bool type[CHAR_TYPE_COUNT] = {false};
    int cnt = 0, l = 0;
    for (l = 0; str[l] != '\0'; l++)
        type[getCharType(str[l])] = true;
    if (l < 6)
        return NOT_SAFE;
    for (int i = 0; i < CHAR_TYPE_COUNT; i++)
        if (type[i])
            cnt++;
    switch(cnt)
    {
    case 1: return NOT_SAFE;
    case 2: return MEDIUM_SAFE;
    default: return SAFE;
    }
}

int main()
{
    int n = 0;
    char password[MAX_LEN] = "";
    cin >> n;
    while(n--)
    {
        cin >> password;
        switch(getSafeLevel(password))
        {
        case NOT_SAFE:
            cout << "Not safe" << endl;
            break;
        case MEDIUM_SAFE:
            cout << "Medium safe" << endl;
            break;
        case SAFE:
            cout << "Safe" << endl;
            break;
        default: break;
        }
    }
    return 0;
}
