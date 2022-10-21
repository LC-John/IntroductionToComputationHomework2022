/*****
��Ŀ����

���� n �������� [ai; bi]������i=1,2,...,n�� ���ǿ���ͨ�����һЩ��������ʹ��Щ���������һ�������
�ı���������ʾ�����ǵ��������ҳ���Щ��Ҫ��ӵı������е���С�ļ��ϣ���С�ļ�����ָ��Щ�������������
�����ܺ���С���������䰴�������������ν���򣬼���������[a;b]��[c;d]������ģ����ҽ���a �� b < c �� d����
�����Щ���䱾���Ϳ�����һ������������ʾ���������Not Needed����

��������

��һ��Ϊһ������n��3 �� n �� 50000����ʾ����������������ڵ�i+1���ϣ�1 �� i �� n����Ϊ�������� ai
�� bi ������֮����һ���ո�ָ�����ʾ���� [ai; bi]������ 1 �� ai �� bi �� 100000����

�������

���Ӧ�������ҵ��Ľ�������е�ȫ����ÿ��Ϊһ�����䣬�����������м���һ���ո�ָ���ʾ��������������Ϊ
������Ŀ�ʼ���ͽ�β������Щ�����������˳������������������������һ������������ʾ���������Not
Needed��

��������

5
5 6
1 4
13 15
6 9
8 10

�������

4 5
10 13
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000

struct Range
{
    int l;
    int r;
} range[MAX_N] = {{0, 0}};

bool cmp(Range &a, Range &b)
{
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}

int main()
{
    int n = 0;
    bool flag = true;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> range[i].l >> range[i].r;
    sort(range, range + n, cmp);
    for (int i = 1, l = range[0].r; i < n; i++)
        if (l < range[i].l)
        {
            cout << l << " " << range[i].l << endl;
            l = range[i].r;
            flag = false;
        }
        else if (l < range[i].r)
            l = range[i].r;
    if (flag)
        cout << "Not Needed" << endl;
    return 0;
}
