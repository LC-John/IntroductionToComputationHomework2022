/*****
��Ŀ����

����һ����������������9λ�����ж����Ƿ�Ϊ����������ν��������ָ������������ȵ�����
�磬123454321��12344321�����ǣ����yes,�����ǣ����no

��������

һ��������

�������

���ǣ����yes
�����ǣ����no

��������

135797531

�������

yes
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 100
char str[MAX_LEN] = "", rev_str[MAX_LEN] = "";

int main()
{
    cin >> str;
    strcpy(rev_str, str);
    reverse(rev_str, rev_str + strlen(rev_str));
    if (!strcmp(str, rev_str))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
