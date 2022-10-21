/*****
��Ŀ����

�й��о�����С������������ɹ������ĳ�˴�1990��1��1����ʼ�����������
��ɹ����������������Ժ��ĳһ�����ǡ����㡱���ǡ�ɹ������
ע��Ҫ��������Ͳ���������������

��������

����Ϊ��������
������ �� �� ����Ϊ֮���ĳһ��

�������

���Ϊ����
����������������
fishing
�������ɹ������
sleeping

��������

1991 10 25

�������

fishing
*****/

#include <iostream>
using namespace std;

#define N_MONTH 12

const int year_nday[2] = {365, 366};
const int month_nday[2][N_MONTH + 1] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap(int y)
{
    if (!(y % 400) || (y % 100 && !(y % 4)))
        return 1;
    return 0;
}

int main()
{
    int year = 0, month = 0, day = 0;
    int cnt = 0, leap = 0;
    while(cin >> year >> month >> day)
    {
        cnt = 0;
        for (int y = 1990; y < year; y++)
            cnt += year_nday[is_leap(y)];
        leap = is_leap(year);
        for (int m = 1; m < month; m++)
            cnt += month_nday[leap][m];
        cnt += day - 1;
        if ((cnt % 5) < 3)
            cout << "fishing" << endl;
        else
            cout << "sleeping" << endl;
    }
    return 0;
}
