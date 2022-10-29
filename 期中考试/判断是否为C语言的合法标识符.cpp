/*****
��Ŀ����

C�����еĺϷ���ʶ���Ķ���Ϊ�����»��߻���ĸ��ͷ����ĸ���ִ������»��ߣ���
���һ������ʵ�ֶ������n���ַ��������ж����Ƿ�ΪC���ԵĺϷ���ʶ��������������1�����������0

��������

����ĵ�һ��Ϊһ�����֣������м��������ִ���
����ÿһ��Ϊһ�����Ȳ�����80���ַ�����

�������

������������ַ��������жϣ��ǺϷ���ʶ�������1���س����������0���س���

��������

5
hello_world
my god
i
_stdio
008A

�������

1
0
1
1
0
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 100
#define VALID 1
#define INVALID 0

bool is_letter_or_underline(char c)
{
    return c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int check_valid_identifier(char* id)
{
    if (!is_letter_or_underline(id[0]))
        return INVALID;
    for (int i = 1; id[i] != '\0'; i++)
        if (!(is_digit(id[i]) || is_letter_or_underline(id[i])))
            return INVALID;
    return VALID;
}

int main()
{
    char id[MAX_LEN];
    int n = 0;
    cin >> n;
    cin.get();
    while(n--)
    {
        cin.getline(id, MAX_LEN, '\n');
        cout << check_valid_identifier(id) << endl;
    }
    return 0;
}
