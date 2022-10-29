/*****
��Ŀ����

��һ��ϸ����ΪA��B�������֣����ǵ���������������ȫ��ͬ�������ڷ�ֳ���������������
A���ַ�ֳ�����ǳ�ǿ��B���ֵķ�ֳ������������һ��Ϊʱһ��Сʱ��ϸ����ֳʵ���У�ʵ��Ա
���������ϸ������������ˣ������дһ�����򣬸���ʵ���������������ֵ����������·�
�����顣

��������

�����ж��У���һ��Ϊ����n��n��100������ʾ��n��������
����n�У�ÿ���������������ֱ�����������ţ�����ǰϸ�������������ϸ��������

�������

����ж��У�
��һ�����A��������������������ÿ�����A����������ı�ţ�����ֳ���������С�
Ȼ��һ�����B��������������������ÿ�����B����������ı�ţ�Ҳ����ֳ���������С�

��������

5
1 10 3456
2 10 5644
3 10 4566
4 20 234
5 20 232

�������

3
1
3
2
2
5
4

��ʾ��Ϣ

�����ڲ���ϸ����ֳ��������ԶԶС������֮��ϸ����ֳ�����Ĳ��졣
Ҳ����˵�����ּ��κ�����ϸ���ķ�ֳ��֮��������ڲ�����ϸ���ķ�ֳ��֮���
*****/

#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 110

struct Group
{
	double grow;
	int id;
} g[MAX_N];

bool cmp(const Group &a, const Group &b)
{
	return a.grow < b.grow || a.grow == b.grow && a.id < b.id;
}

int main()
{
	int n = 0;
	double a = 0, b = 0;
	double avg = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
    {
		cin >> g[i].id;
		cin >> a >> b;
		g[i].grow = b / a;
	}
	sort(g, g + n, cmp);

	avg = (g[0].grow + g[n - 1].grow) / 2;
	int split = 0;
	while (split < n && g[split].grow < avg)
		split++;

	cout << n - split << endl;
	for (int i = split; i < n; i++)
		cout << g[i].id << endl;
	cout << split << endl;
	for (int i = 0; i < split; i++)
		cout << g[i].id << endl;
	return 0;
}
