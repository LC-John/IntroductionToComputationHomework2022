/*****
��Ŀ����

����һ�ּ��ܷ�ʽ������Ҫһ�����ⳤ�ȵ�ԭ�� m ����Կ key������Ҫ��ԭ�ĺ���Կֻ������
д��Сд��Ӣ���ַ���
���ȶ����ַ�֮��ļ��ܣ����ַ� a ȥ�����ַ� b �Ľ���ǣ�
1. ���Ȱ� a �� b ת������ x �� y��ת���Ĺ����ǣ�Сд��ĸ a �� z ���ζ�Ӧ 0 �� 25��
��д��ĸ���ζ�Ӧ 26 �� 51��
2. ���� x �� y �ĺ� z���� 52 ȡģ�������� (x + y) % 52��
3. �������� z ��Ӧ���ַ���
���������������Կ key ������ԭ�� m��
1. �����Կ�� key �ĳ���С�� m����ô��ͣ�ظ� key ֱ�����Ȳ�С�� m Ϊֹ��������˵����
��ԭ���� beijing����Կ�� PKUSAA����ô��Կ��Ҫ���ظ��� PKUSAAPKUSAA��
2. ����ԭ�ĵĳ����� n����ô����ÿһ�� 1~n ������ i������ key �ĵ� i ���ַ�ȥ���� m
�ĵ� i ���ַ���
3. ���ؽ����
��ô�� PKUSAA ȥ���� beijing �Ľ�����ǣ�QOcbINV
���ڻ�ɽ���� n ���ַ�����s[1] �� s[n]��������Щ�ַ������� m �μ��ܲ������� i �μ��ܲ�
���õ� s[x[i]] ȥ���� s[y[i]]������ s[y[i]] �滻�ɼ��ܽ����
�������θ��� m �μ��ܲ������Լ����ܲ���������ÿһ���ַ�����ģ��������Ի�ԭ���� n ��
�ַ���ԭ����ģ����

��������

��һ�������������� n,m (1 <= n,m <= 1000)��
������ m ��ÿ�������������� x[i],y[i]����ʾ���μ��ܲ�������֤ x[i] ������ y[i]��
������ n ��ÿ������һ���ַ�������ʾ�������Ľ�����ַ����ĳ����� 1 �� 100 ֮�䣬ֻ��
����СдӢ���ַ���

�������

��� n �У�ÿ��һ���ַ�������ʾԭ�����ַ�����

��������

2 1
1 2
PKUSAA
QOcbINV

�������

PKUSAA
beijing
*****/

#include <iostream>
using namespace std;

#define MAX_N 1010
#define MAX_L 110

int xi[MAX_N], yi[MAX_N];
char str[MAX_N][MAX_L];

int letter2digit(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else
        return c - 'A' + 26;
}

char digit2letter(int x)
{
    x = (x + 52) % 52;
    if (x >= 26)
        return 'A' + x - 26;
    else
        return 'a' + x;
}

char rev(char a, char b_)
{
	return digit2letter(letter2digit(b_) - letter2digit(a));
}

void crack(int a, int b)
{
	for (int i = 0, j = 0; str[b][j] != '\0'; i++, j++)
    {
		if (str[a][i] == '\0')
			i = 0;
		str[b][j] = rev(str[a][i], str[b][j]);
	}
}


int main()
{
	int n, m;
	while (cin >> n >> m)
    {
		for (int i = 0; i < m; ++i)
			cin >> xi[i] >> yi[i];
		for (int i = 0; i < n; ++i)
			cin >> str[i];
		for (int i = m - 1; i >= 0; --i)
			crack(xi[i] - 1, yi[i] - 1);
		for (int i = 0; i < n; ++i)
			cout << str[i] << endl;
	}
	return 0;
}
