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

char num[MAX_LEN] = "\0", rev_num[MAX_LEN] = "\0";

int main()
{
    cin >> num;             // �����ַ���num
    strcpy(rev_num, num);   // ��num������rev_num��
    reverse(rev_num, rev_num + strlen(rev_num));    // ��תrev_num
    if (!strcmp(rev_num, num))  // �Ա�num��rev_num
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
