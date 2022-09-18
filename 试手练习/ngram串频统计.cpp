/*****
����

���ı������г��õ�n-gram��Ƶͳ�Ʒ���������ͳ�����ڵ�n ����Ԫ���絥�ʡ����֡������ַ���
�������ı��г��ֵ�Ƶ�ʡ�������һ���ַ����������ַ�Ϊ��λ��n-gram ͳ�Ƴ���Ϊn���Ӵ���
�ֵ�Ƶ�ȣ���������Ƶ���Լ�Ƶ����ߵ��Ӵ����趨�������ַ���������500���ַ�����1<n<5��
����ж���Ӵ�Ƶ����ߣ���������������е�һ�γ��ֵĴ�����������
ÿ�����һ����������Ƶ�Ȳ�����1�������NO
���磬n=3�������Ĵ��ǣ�abcdefabcd��
�����е� 3-gram�ǣ�abc,bcd,cde,def,efa,fab,abc,bcd��������cd�������γ�3-gram����
�����ǡ�������abc��bcd��������2�Σ������ֻ������1�Σ����ǣ�������Ӧ���ǣ�
2
abc
bcd

��������

��һ��Ϊn
�ڶ���Ϊ�ַ���

�������

������Ƶ���Լ�Ƶ����ߵ������Ӵ���

��������

3
abcdefabcd

�������

2
abc
bcd
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10
#define MAX_L 510

char sub[MAX_L][MAX_N] = {'\0'};
int cnt[MAX_L] = {0};
char str[MAX_L] = "\0";

int main()
{
    int n_sub = 0;
    int n = 0, l =0;

    cin >> n_sub;
    cin.get();
    cin.getline(str, MAX_L);
    l = strlen(str);
    /* Count n-gram sub-sequences */
    strncpy(sub[n], str, n_sub);
    cnt[n++] = 1;
    for (int i = 1; i <= l - n_sub; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
            if (strncmp(sub[j], str + i, n_sub) == 0)
            {
                cnt[j]++;
                found = true;
                break;
            }
        if (!found)
        {
            strncpy(sub[n], str + i, n_sub);
            cnt[n++] = 1;
        }
    }
    /* Sort n-gram sub-sequences */
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (cnt[i] > cnt[j])
            {
                char tmp[MAX_N];
                strncpy(tmp, sub[i], n_sub);
                strncpy(sub[i], sub[j], n_sub);
                strncpy(sub[j], tmp, n_sub);
                cnt[i] = cnt[i] ^ cnt[j];
                cnt[j] = cnt[i] ^ cnt[j];
                cnt[i] = cnt[i] ^ cnt[j];
            }

    if (cnt[0] <= 1)
        cout << "NO";
    else
    {
        cout << cnt[0] << endl;
        for (int i = 0; i < n && cnt[i] == cnt[0]; i++)
            cout << sub[i] << endl;
    }
    return 0;
}
