/*****
��Ŀ����

�������ַ���S,S1,S2�����У�S���Ȳ�����300,S1��S2�ĳ��Ȳ�����10������S1��S2�Ƿ�ͬʱ��S�г��֣�
��S1λ��S2����ߣ�����S�л������棨����S1���ұ߽����S2����߽�����ࣩ����������������������
���ࣨ������������룺���ұߵ�S2����ʼ��������ߵ�S1����ֹ��֮����ַ���Ŀ�������û������
������ż��S1��S2���ڣ������ -1
���磬S = "abcd123ab888efghij45ef67kl", S1="ab", S2="ef"�����У�S1��S�г�����2�Σ�S2Ҳ��S��
������2�Σ��������Ϊ��18

��������

��������S, S2, S3������Զ��ż����ע�⣬S, S2, S3�о��������ţ���

�������

S1��S2��S����ࣻ����S��û������������S1��S2�������-1

��������

abcd123ab888efghij45ef67kl,ab,ef

�������

18
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 1000

char s[MAX_LEN] = "", s1[MAX_LEN] = "", s2[MAX_LEN] = "";

int main()
{
    int l = 0, l1 = 0, l2 = 0;
    int left = 0, right = 0;    // left��¼s�д�������s1��һ�γ��ֵĽ�βλ��
                                // right��¼s�д�������s2��һ�γ��ֵĿ�ʼλ��

    /** �������ݣ�Ԥ��������ַ������� **/
    cin.getline(s, MAX_LEN, ',');
    cin.getline(s1, MAX_LEN, ',');
    cin.getline(s2, MAX_LEN, '\n');
    l = strlen(s);
    l1 = strlen(s1);
    l2 = strlen(s2);

    /** ��s�д�������ƥ��s1 **/
    for (int left1 = 0; left < l; left++)
    {
        if (s1[left1] == s[left])
            left1++;
        else
            left1 = 0;
        if (left1 >= l1)
            break;
    }

    /** ��s�д�������ƥ��s2 **/
    right = l - 1;
    for (int right2 = l2 - 1; right >= 0; right--)
    {
        if (s2[right2] == s[right])
            right2--;
        else
            right2 = l2 - 1;
        if (right2 < 0)
            break;
    }

    if (left >= l || right < 0 || right - left <= 0)    // ��s���޷�ƥ��s1��s2������s1��s2�Ҳ����
        cout << -1 << endl;                             // �򲻷���Ҫ�����-1
    else                                                // ����
        cout << right - left - 1 << endl;               // ������
    return 0;
}
