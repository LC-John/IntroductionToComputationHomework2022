/*****
��Ŀ����

��һ��������״�����̣���״�����ǲ�����ģ�����ڷ����ӣ�����û������Ҫ��ڷ�ʱ������������Ӳ��ܷ���
�����е�ͬһ�л���ͬһ�У����������ڸ�����״�ʹ�С�����̣��ڷ�k�����ӵ����п��еİڷŷ���C��

��������

���뺬�ж���������ݡ�
ÿ�����ݵĵ�һ����������������n k����һ���ո��������ʾ�˽���һ��n*n�ľ������������̣��Լ��ڷ����ӵ���
Ŀ�� n <= 8 , k <= n
��Ϊ-1 -1ʱ��ʾ���������
����n�����������̵���״��ÿ����n���ַ������� # ��ʾ�������� . ��ʾ�հ��������ݱ�֤�����ֶ���Ŀ�
���л��߿հ��У���

�������

����ÿһ�����ݣ�����һ�����������ڷŵķ�����ĿC �����ݱ�֤C<2^31����

��������

2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1

�������

2
1
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10
#define AVAILABLE '#'
#define EMPTY '.'

char board[MAX_N][MAX_N] = {""};                                        // ����
int n = 0, ans = 0;                                                     // nΪ���̴�С��ansΪ�������
bool r[MAX_N] = {false}, c[MAX_N] = {false};                            // ��¼�У�r�����У�c���Ƿ�Ź�����
int x[MAX_N * MAX_N] = {0}, y[MAX_N * MAX_N] = {0}, n_available = 0;    // ��¼���������п���λ��

/** ����������� **/
void dfs (int step,int chess)   // step��¼�������ĸ�����λ�ã�chess��¼���м�������Ҫ��
{
    if (chess <= 0) // ��û������Ҫ����
    {
    	ans++;      // ���ҵ�һ�ֿ��еķ��÷�����ans��1
    	return;     // ����
	}
	if (step >= n_available)    // ��û�п���λ����
        return;                 // ��ֱ�ӷ���

	dfs(step + 1, chess);               // stepλ�ò��ţ��������
	if (!r[x[step]] && !c[y[step]])     // ��stepλ�ÿ��Է���
	{
		r[x[step]] = true;              // ��������r��c�ı�ǩ
		c[y[step]] = true;
		dfs(step + 1, chess - 1);       // �������
		r[x[step]] = false;             // ���������󣬻ָ�r��c�ı�ǩ
		c[y[step]] = false;
	}
}
int main ()
{
    int k = 0;
	while (cin >> n >> k)
    {
        if (n < 0 && k < 0)
            return 0;

        /** ��ʼ�� **/
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		ans = 0;
		n_available = 0;

        /** �������̣���¼���п��е�λ�� **/
		for (int i = 0;i < n; i++)
			for (int j = 0;j < n; j++)
            {
				cin >> board[i][j];
				if (board[i][j] == AVAILABLE)
				{
					x[n_available] = i;
					y[n_available++] = j;
				}
			}

        /** ����������� **/
		dfs(0, k);
		cout << ans << endl;
	}
	return 0;
}
