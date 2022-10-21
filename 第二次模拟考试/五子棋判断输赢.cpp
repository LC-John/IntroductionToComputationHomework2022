/*****
��Ŀ����

��һ��N��N���������������壬����һ��������ڰ������������ (x0,y0),(x1,y1), ..., ��xn,yn�����ж��ߵ����ٲ�ʱ���ķ���ʤ��

��������

��һ�����������������̵Ĵ�СN���������еĳ���n��
�������ÿ���������֣��ֱ��ʾ�������������������ϵ�λ�á�
������һ������ģ�����һ���ֳܷ���Ӯ������Ϊ����˫��û���жϳ���Ӯ��������������

�������

���Ϊһ�У�����������������һ���������жϳ���Ӯʱ����Ĳ������ڶ������ֱ�ʾ��ʤ��������ڷ���ʤ�����0������׷���ʤ�����1��

��������

10 12
0 0
1 0
0 1
2 0
0 2
3 0
0 3
4 0
0 4
5 0
0 5
6 0

�������

9 0

��ʾ��Ϣ

���������Ƚϸ��ӣ���������ֻҪ��������У�˭����������5���Ӿ���Ӯ�������Ƿ���ֹ�����Լ���Ľ��֡�ÿ���嶼��ʤ�������
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000
#define BLACK '$'
#define WHITE '*'
#define EMPTY '#'

char arr[MAX_N][MAX_N] = {""};
int N = 0;

void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j];
        cout << endl;
    }
}

bool check_win(int r, int c)
{
    const int nd = 4;
    const int n_win = 5;
    int cnt = 0;
    int dr[nd] = {0, 1, 1, 1};
    int dc[nd] = {1, 0, 1, -1};
    // print();
    for (int d = 0; d < nd; d++)
    {
        cnt = 1;
        for (int _r = r + dr[d], _c = c + dc[d];
              _r >= 0 && _r < N && _c >= 0 && _c < N && arr[_r][_c] == arr[r][c];
              _r += dr[d], _c += dc[d], cnt++);
        for (int _r = r - dr[d], _c = c - dc[d];
              _r >= 0 && _r < N && _c >= 0 && _c < N && arr[_r][_c] == arr[r][c];
              _r -= dr[d], _c -= dc[d], cnt++);
        if (cnt >= n_win)
            return true;
    }
    return false;
}

int main()
{
    int n = 0, r = 0, c = 0;
    char curr = BLACK;
    bool finish = false;
    memset(arr, EMPTY, sizeof(arr));
    cin >> N >> n;
    for (int step = 1; step <= n; step++)
    {
        cin >> r >> c;
        if (finish)
            continue;
        arr[r][c] = curr;
        if (check_win(r, c))
        {
            cout << step;
            switch(curr)
            {
                case BLACK: cout << " 0" << endl; break;
                case WHITE: cout << " 1" << endl; break;
                default: break;
            }
            finish = true;
        }
        switch(curr)
        {
                case BLACK: curr = WHITE; break;
                case WHITE: curr = BLACK; break;
                default: break;
        }
    }
    return 0;
}
