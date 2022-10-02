/*****
��Ŀ����

����һ������A[m,n](100 �� m �� 1,100 �� n �� 1) ����һ������B[r,s],��0 < r �� m, 0 < s �� n��A��B����
Ԫ��ֵ����С��100������������A�к�B��ƥ��ľ���C[r,s]����ν��ƥ����ָB��C�Ķ�ӦԪ�ز�ֵ�ľ���ֵ֮����С��
����ж�����ƥ��ֻ�������һ�����к���С���к���ͬʱ���к���С����

��������

��һ����m��n���Կո����
����m��ÿ����n����������ʾA�����еĸ���
��m+2��Ϊr��s���Կո����
����r��ÿ����s����������ʾB�����еĸ���

�������

���A�к�B��ƥ��ľ���C�����֮
ע�⣺ÿһ�����ֺ��涼�пո񣬰���һ���е����һ������

��������

3 3
3 4 5
5 3 4
8 2 4
2 2
7 3
4 9

�������

4 5
3 4
*****/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_SIZE 110
#define MAX_INT 0x7fffffff

int A[MAX_SIZE][MAX_SIZE] = {0};
int B[MAX_SIZE][MAX_SIZE] = {0};

int main()
{
    int m = 0, n = 0, r =  0, s = 0;
    int diff = 0;
    int min_diff = MAX_INT, min_row = -1, min_col = -1;

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    cin >> r >> s;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < s; j++)
            cin >> B[i][j];

    for (int i = 0; i + r <= m; i++)
        for (int j = 0; j + s <= n; j++)
        {
            diff = 0;
            for (int _i = 0; _i < r; _i++)
                for (int _j = 0; _j < s; _j++)
                    diff += abs(A[i + _i][j + _j] - B[_i][_j]);
            // cout << i << " " << j << " " << diff << endl;
            if (diff < min_diff)
            {
                min_diff = diff;
                min_row = i;
                min_col = j;
            }
        }

    for (int i = min_row; i < min_row + r; i++)
    {
        for (int j = min_col; j < min_col + s; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}
