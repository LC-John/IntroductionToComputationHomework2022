/*****
��Ŀ����

�ٶ�ͼ����½���m��10 �� m �� 999����ͼ�飬���Ƕ�����n��2 �� n �� 26�������߶������໥���������ġ�
����m��ͼ����Ϊ������1��999�������ߵ�����Ϊ��ĸ��'A'��'Z'���������ͼ�������б��ҳ��������ͼ����
������ߺ�����ͼ���б�

��������

��һ��Ϊ����ͼ������m������m�У�ÿ����һ��ͼ�����Ϣ�����е�һ������Ϊͼ���ţ�����һ���ո�֮����һ
���ɴ�дӢ����ĸ��ɵ�û���ظ��ַ����ַ�����ÿ����ĸ����һ�����ߡ�

�������

����ж��У�
��һ��Ϊ��������������ĸ��
�ڶ���Ϊ���߳����������
�������Ϊ���߲��������ͼ���ţ�������˳���������

��������

11
307 F
895 H
410 GPKCV
567 SPIM
822 YSHDLPM
834 BXPRD
872 LJU
791 BPJWIA
580 AGMVY
619 NAFL
233 PDJWXK

�������

P
6
410
567
822
834
791
233

��ʾ��Ϣ

�������ݱ�֤����һ�����߳�����ࡣ
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_AUTHOR 300
#define MAX_BOOK 1000

int book[MAX_AUTHOR][MAX_BOOK] = {0};   // ��¼ÿ������д����ı�ţ�book['D']����ͼ�¼��'D'д������
int cnt[MAX_AUTHOR] = {0};              // ��¼ÿ������д�˶��ٱ��飬cnt['D']�ͼ�¼��'D'д�����ٱ���

int main()
{
    int n = 0, l = 0;
    int max_cnt = 0;
    char max_author = '\0';
    int num = 0;
    char author[MAX_AUTHOR] = "\0";

    cin >> n;
    while(n--)
    {
        cin >> num >> author;
        l = strlen(author);
        for (int i = 0; i < l; i++)
        {
            book[author[i]][cnt[author[i]]++] = num;    // ����book��cnt����
            if (cnt[author[i]] > max_cnt)               // ����max_cnt��max_author
            {
                max_cnt = cnt[author[i]];
                max_author = author[i];
            }
        }
    }

    cout << max_author << endl << max_cnt << endl;
    for (int i = 0; i < cnt[max_author]; i++)
        cout << book[max_author][i] << endl;
    return 0;
}
