/*****
��Ŀ����

��һ��Ӣ�Ķ��ģ�����֮���Կո�ָ���ÿ������Ӧ������ǰ����ڵı����ţ����뽫���������Ű棬Ҫ�����£�
ÿ�в�����80���ַ���ÿ�����ʾ���ͬһ���ϣ���ͬһ�еĵ���֮����һ���ո�ָ������׺���β��û�пո�

��������

��һ����һ������n����ʾӢ�Ķ����е��ʵ���Ŀ. �����n���Կո�ָ���Ӣ�ĵ��ʣ����ʰ�����ǰ����ڵı����ţ���ÿ�����ʳ��ȶ�������40����ĸ����

�������

�Ű��Ķ����ı���ÿ���ı��ַ������80���ַ�������֮����һ���ո�ָ���ÿ���ı���β��û�пո�

��������

84
One sweltering day, I was scooping ice cream into cones and told my four children they could "buy" a cone from me for a hug. Almost immediately, the kids lined up to make their purchases. The three youngest each gave me a quick hug, grabbed their cones and raced back outside. But when my teenage son at the end of the line finally got his turn to "buy" his ice cream, he gave me two hugs. "Keep the changes," he said with a smile.

�������

One sweltering day, I was scooping ice cream into cones and told my four
children they could "buy" a cone from me for a hug. Almost immediately, the kids
lined up to make their purchases. The three youngest each gave me a quick hug,
grabbed their cones and raced back outside. But when my teenage son at the end
of the line finally got his turn to "buy" his ice cream, he gave me two hugs.
"Keep the changes," he said with a smile.
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100
#define MAX_N 1000

char s[MAX_N][MAX_LEN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int curidx = 0;
	for (int i = 0; i < n; ++i)
    {
		int l = strlen(s[i]);
		if (curidx + l + 1 <= 80)
		{
			if (curidx != 0)
            {
				cout << ' ';
				curidx += 1;
			}
			cout << s[i];
			curidx += l;
		}
        else
		{
			cout << endl << s[i];
			curidx = l;
		}
	}
	return 0;
}
