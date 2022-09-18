/*****
��Ŀ����

������۰��ͬѧ������һ���µ��ı������㷨--���ı�ת��Ϊʮ�����������ʹ�ŵ������
ʹ��������Լ���þ�������������������ҹ涨�ı��н��д�д��ĸ�Ϳո��������Ȱ��������ķ������ı����б��룺
�ո� = 00
A = 01
B = 02
C = 03
......
Y = 25
Z = 26
Ȼ��Ȼ���ջ��ͱ����ķ�������ÿ���ַ���Ӧ�����2λʮ������������������У��������λ��ʹ��0���䡣���磬
������Ϣ��PKU�����ھ�������������3������£������Ϊ��
1 -> 6 -> 1
          |
0 -> 0    1
|         |
0 <- 1 <- 2
�����н������е���������������ɼ��ܹ��̡�Ҳ�������������е���Ϣ���ջᱻ����Ϊ��
161001012

��������

��һ��Ϊ��������R��C���м���һ���ո�������ֱ��ʾ����������������1��R��10��1��C��10��
�ڶ���Ϊһ��ֻ������д��ĸ�Ϳո���ַ����������Կո�ͷ��1���ַ������ȡ�(R * C) / 2��

�������

һ�У�Ϊ���ܺ��ʮ���ƴ�

��������

3 3
PKU

�������

161001012

��ʾ��Ϣ

ע�⣺ǰ��0ҲҪ���
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 20

int arr[MAX_N][MAX_N] = {0};
int num[MAX_N * MAX_N] = {0};
char str[MAX_N * MAX_N] = "\0";
int R = 0, C = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    int pos = 0, x = 0, y = 0, dir = 0;
    memset(arr, -1, sizeof(arr));
    memset(num, -1, sizeof(num));
    cin >> R >> C;
    cin.get();
    cin.getline(str, MAX_N * MAX_N);
    /* Code sequence */
    for (int i = 0; str[i] != '\0'; i++)
    {
        int digit = 0;
        if (str[i] >= 'A' && str[i] <= 'Z')
            digit = str[i] - 'A' + 1;
        num[pos++] = digit / 10;
        num[pos++] = digit % 10;
    }
    /* Zero padding */
    for (; pos < R * C; pos++)
        num[pos] = 0;
    /* Rotationally filling the matrix */
    pos = 0;
    while (pos < R * C)
    {
        int _x = x + dx[dir], _y = y + dy[dir];
        arr[x][y] = num[pos++];
        if (_x < 0 || _x >= R || _y < 0 || _y >= C || arr[_x][_y] >= 0)
        {
            dir = (dir + 1) % 4;
            _x = x + dx[dir], _y = y + dy[dir];
        }
        x = _x;
        y = _y;
    }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cout << arr[i][j];
    return 0;
}
