/*****
��Ŀ����

�������룺 ��ȡһ�������ٰ�������������������������ӣ�Ȼ�����������ٵ���������ԭ������
�ӣ��ظ��˹��̣�һ���ܻ��һ������������ 68 �������� 86
        68+86= 154��154+451= 605�� 605+506=1111 (����)
��̣�����������������������������һ��������Ϊ��������������7�������Ƿ��ܵõ�һ��������
Ҫ��
�������н��ռ������ݣ���ʾ�������䵹���ĺͣ����ÿһ�����㲽�衣
�Ӻ���1����������ĵ�����
�Ӻ���2����֤���Ƿ�Ϊ������

��������

����Ϊint��

�������

�������ÿ��������̣�����߲���
���7�����Ƿ�õ�һ��������Y/N��

��������

68

�������

68+86=154
154+451=605
605+506=1111
Y
*****/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 100
#define MAX_STEP 7

char s[MAX_LEN] = "", r[MAX_LEN] = "";

/** ����n�ĵ����ַ��� **/
void get_reverse(int n)
{
    sprintf(s, "%d", n);
    strcpy(r, s);
    reverse(r, r + strlen(r));
}

/** �ж�n�Ƿ���� **/
bool is_palindromic(int n)
{
    get_reverse(n);
    if (!strcmp(s, r))
        return true;
    return false;
}

int main()
{
    int num = 0, n = 0, rev_num = 0;
    scanf("%d", &num);
    while (n++ < MAX_STEP)
    {
        if (is_palindromic(num))    // ��num����
        {
            printf("Y\n");          // �����Y
            return 0;               // ����ֱ�ӷ���
        }
        sscanf(r, "%d", &rev_num);                          // ��r�е����ַ���תΪint���ʹ����rev_num��
        printf("%d+%d=%d\n", num, rev_num, num + rev_num);  // ��ӡ���㲽��
        num += rev_num;                                     // ����num
    }
    if (is_palindromic(num))    // �ж�num�Ƿ����
    {
        printf("Y\n");
        return 0;
    }
    printf("N\n");  // �޷���MAX_STEP����ɣ����N
    return 0;
}
