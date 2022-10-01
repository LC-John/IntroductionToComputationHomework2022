/*****
��Ŀ����

����һ������ nums����������ÿ��Ԫ�� nums[i]������ͳ�������б���С���������ֵ���Ŀ��
������֮������ÿ�� nums[i] �����������Ч�� j ������������ j ���� j != i �� nums[j] < nums[i]��

��������

��һ����һ������ n����ʾ�����С��
������ n �У�ÿ�б�ʾ�����е�һ������
0 <= n <= 1000, ÿ��������int���Ա�ʾ�ķ�Χ��.

�������

n �У�ÿ�д��������б���С�����ĸ�����
���û��Ҫ��������ݣ����"None"��

��������

5
8
1
2
2
3

�������

4
0
1
1
3
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1010

struct A
{
    int val;
    int idx;
    int less_cnt;
    int same_cnt;
} a[MAX_N] = {{0, 0, 0, 0}};

bool compare_val(struct A a, struct A b)
{
    return a.val < b.val;
}

bool compare_idx(struct A a, struct A b)
{
    return a.idx < b.idx;
}

int main()
{
    int n = 0;
    cin >> n;

    if (!n)
    {
        cout << "None" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].val;
        a[i].idx = i;
        a[i].less_cnt = 0;
        a[i].same_cnt = 1;
    }

    sort(a, a + n, compare_val);

    for (int i = 1; i < n; i++)
        if (a[i].val == a[i - 1].val)
        {
            a[i].less_cnt = a[i - 1].less_cnt;
            a[i].same_cnt = a[i - 1].same_cnt + 1;
        }
        else
            a[i].less_cnt = a[i - 1].less_cnt + a[i - 1].same_cnt;

    sort(a, a + n, compare_idx);

    for (int i = 0; i < n; i++)
        cout << a[i].less_cnt << endl;

    return 0;
}
