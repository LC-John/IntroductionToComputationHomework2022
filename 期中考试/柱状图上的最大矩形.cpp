/*****
��Ŀ����

����n���Ǹ�������������״ͼ��ÿ�����ĸ߶ȣ���Ⱦ�Ϊ1�����������״ͼ�����ľ��������
�����������"2 1 5 6 2 3"��������Ϊ10������ͼ��

��������

��һ����һ������n�������ж��ٸ����Σ�nС�ڵ���20000
�ڶ�����n������������Ϊÿ�����εĸ߶�

�������

һ�����֣��������״ͼ�����ľ�������������󲻳���int�ı�ʾ��Χ

��������

6
2 1 5 6 2 3

�������

10
*****/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 20010

int num[MAX_N];

int main()
{
	int n = 0, res = 0;
	int minh = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++) {
		minh = num[i];
		for (int j = i; j < n; j++) {
			minh = min(minh, num[j]);
			res = max(res, minh * (j - i + 1));
		}
	}
	cout << res << endl;
	return 0;
}
