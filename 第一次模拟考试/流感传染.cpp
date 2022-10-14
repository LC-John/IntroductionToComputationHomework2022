/*****
��Ŀ����

��һ���׸���Ⱥס������״���������ڣ�������Ϊn*n�ľ���ÿ�����Ϊһ�����䣬���������ס�ˣ�Ҳ���ܿ��š�
�ڵ�һ�죬��Щ��������˵������У��Ժ�ÿ�죬�����е��˻�ʹ���ھӴ�Ⱦ�����У����Ѿ��ò��Ĳ��䣩���շ���
���ᴫȾ���������m������е�������

��������

��һ��һ������n��n������100����ʾ��n*n�����᷿�䡣
��������n�У�ÿ��n���ַ�����.����ʾ��һ��÷���ס�Ž������ˣ���#����ʾ�÷�����ţ���@����ʾ��һ��÷���
ס�ŵ����е��ˡ�
��������һ����һ������m��m������100.

�������

�����m�죬�����е�����

��������

5
....#
.#.@.
.#@..
#....
.....
4

�������

16
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1010
#define HEA '.'
#define EMP '#'
#define ILL '@'
#define TOBEILL '$'

char room[MAX_N][MAX_N] = {""};
int n = 0;

void infect()
{
    const int nd = 4;
    int di[nd] = {1, -1, 0, 0};
    int dj[nd] = {0, 0, 1, -1};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (room[i][j] == ILL)
                for (int d = 0; d < nd; d++)
                    if (room[i + di[d]][j + dj[d]] == HEA)
                        room[i + di[d]][j + dj[d]] = TOBEILL;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (room[i][j] == TOBEILL)
                room[i][j] = ILL;
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << room[i][j];
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int d = 0, cnt = 0;
    memset(room, EMP, sizeof(char) * MAX_N * MAX_N);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> room[i][j];
    cin >> d;
    while (--d)
    {
        infect();
        // print();
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (room[i][j] == ILL)
                cnt ++;
    cout << cnt << endl;
    return 0;
}
