/*****
��Ŀ����

��n��Ӳ���ų�һ�ţ�ÿ��Ӳ������һ�����ֱ�ʶ�����ļ�ֵ��ÿ��Ҫ�������߻������ұ���
��һ��Ӳ�ҡ��ܹ���k�Σ�дһ���㷨��ʹ���õ���Ӳ�ҵļ�ֵ�����

��������

����������У���һ��Ϊn�� k��
�ڶ��а���n�����֣���ʾn��Ӳ�ҵļ�ֵ��
1 <= k <= n <= 100000
����Ӳ�ҵļ�ֵ����0�Ҳ�����10000.

�������

��������õ���k��Ӳ�����ļ�ֵ�͡�

��������

6 3
5 4 3 2 1 6

�������

15

��ʾ��Ϣ

����߿�ʼ����ȡ����Ӳ�ң��ұ�ȡһ��Ӳ�Ҽ��ɡ�
*****/

#include <iostream>
using namespace std;

#define MAX_N 100010

int val[MAX_N] = {0};

int main()
{
    int n = 0, k = 0, t = 0;
    int sum_t = 0, min_sum_t = 0, sum = 0;
    cin >> n >> k;
    t = n - k;
    for (int i = 0; i < t; i++)
    {
        cin >> val[i];
        sum_t += val[i];
        min_sum_t += val[i];
        sum += val[i];
    }
    for (int i = t; i < n; i++)
    {
        cin >> val[i];
        sum += val[i];
        sum_t += val[i] - val[i - t];
        if (sum_t < min_sum_t)
            min_sum_t = sum_t;
    }
    cout << sum - min_sum_t;
    return 0;
}
