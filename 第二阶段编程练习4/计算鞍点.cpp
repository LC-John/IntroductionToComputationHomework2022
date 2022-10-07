/*****
��Ŀ����

����һ����ά (5*5)���飬ÿ��ֻ��һ�����ֵ��ÿ��ֻ��һ����Сֵ��
������ڰ��㣬������������ڵ�λ�ã��к��У��������ڰ���ʱ��Ҫ�����not found����
����ָ���������е�һ��Ԫ�أ����������е����ֵ�������������е���Сֵ��
���磺������������У���4�е�1�е�Ԫ�ؾ��ǰ��㣬ֵΪ8 ����
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25

��������

�������һ��5��5�еľ���

�������

������ڰ��㣬����������ڵ��С��м���ֵ����������ڣ����"not found"

��������

11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8  6 4 7 2
15 10 11 20 25

�������

4 1 8
*****/

#include <iostream>
using namespace std;

#define N 5
#define MAX_INT 0x7fffffff
#define MIN_INT 0x80000000

int arr[N + 1][N + 1] = {0};    // �������
int row_max_idx[N + 1] = {0};   // ÿһ�е����ֵ���ڵ���
int col_min_idx[N + 1] = {0};   // ÿһ�е���Сֵ���ڵ���

int main()
{
    bool flag = false;

    /** ��ʼ�� **/
    for (int i = 1; i <= N; i++)
    {
        arr[i][0] = MIN_INT;    // ÿһ�е�0�з���MIN_INT
        arr[0][i] = MAX_INT;    // ÿһ�е�0�з���MAX_INT
    }

    /** �������� **/
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] > arr[i][row_max_idx[i]]) // ����ǰ�����ڵ�ǰ�е����ֵ
                row_max_idx[i] = j;                 // ����µ�ǰ�е�row_max_idx
            if (arr[i][j] < arr[col_min_idx[j]][j]) // ����ǰ��С�ڵ�ǰ�е���Сֵ
                col_min_idx[j] = i;                 // ����µ�ǰ�е�col_min_idx
        }

    /** Ѱ�Ұ��㲢��� **/
    for (int i = 1; i <= N; i++)
        if (col_min_idx[row_max_idx[i]] == i)
        {
            flag = true;
            cout << i << " " << row_max_idx[i] << " " << arr[i][row_max_idx[i]] << endl;
            return 0;
        }
    if (!flag)
        cout << "not found" << endl;
    return 0;
}
