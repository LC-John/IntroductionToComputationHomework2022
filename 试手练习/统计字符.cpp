/*****
��Ŀ����

����һ������С��1000�ַ�����ͳ������ַ����С�*�� ��@�����ֵĴ�����

��������

ֻ��һ�У�һ���������ܰ����˶����*������@��

�������

һ�����У��ֱ�������ַ��ŵĸ�����

��������

@sfw3241*��&@*#(!(@$!

�������

*������2��;
@������3��.

��ʾ��Ϣ

�����ַ�����Ҫ�õ�gets������
*****/

#include <iostream>
using namespace std;

#define N_ASCII 300

char ch[N_ASCII] = {'*', '@'};
int n_ch = 2;
int cnt[N_ASCII] = {0};

int main()
{
    int cnt[N_ASCII] = {0};
    char c = '\0';

    while(cin >> c)
        cnt[c]++;

    for (int c = 0; c < n_ch; c++)
    {
        cout << ch[c] << "������" << cnt[ch[c]] << "��";
        if (c < n_ch - 1)
            cout << ";" << endl;
        else
            cout << "." << endl;
    }
    return 0;
}
