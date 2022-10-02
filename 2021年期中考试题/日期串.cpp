/*****
��Ŀ����

������ 2021 �� 1 �� 3 �գ����������ַ��� s Ϊ�Ѵӽ��쿪ʼ�� 9999 �� 12 �� 31 �յ���������д�µõ����ַ�����
s = 202101032021010420210105...99991231
���ڣ����� n ������ a[1] ... a[n]������Ҫ����ÿһ�������������һ���� s �г��ֵ�λ�ã�s ���±�� 1 ��ʼ����

��������

��һ������һ������ n����ʾ���ֵĸ��� (1 <= n <= 100)��
������ÿ������һ����������ʾ a[i] (0 <= a[i] <= 100)��

�������

��� n �У�ÿ��һ����������ʾ�𰸡���� a[i] �� s ��û�г��֣������ -1.

��������

5
0
5
9
14
97

�������

2
24
56
95
222059
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define S_LEN 50000000
#define A_LEN 10
#define MAX_DIGIT 10

char s[S_LEN] = "\0";
int len = 0;

int month[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

char* get_digit(int num)
{
    char *ret = new char[MAX_DIGIT];
    memset(ret, '0', sizeof(char) * MAX_DIGIT - 1);
    int l = 0;
    while(num > 0)
    {
        ret[l++] = num % 10 + '0';
        num /= 10;
    }
    return ret;
}

int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

int generate_day(int y, int m, int d, int curr)
{
    char* ymd[3] = {get_digit(y), get_digit(m), get_digit(d)};
    int l_ymd[3] = {4, 2, 2};
    for (int j = 0; j < 3; j++)
    {
        for (int i = l_ymd[j] - 1; i >= 0; i--)
            s[curr++] = ymd[j][i];
        delete[] ymd[j];
    }
    s[curr] = '\0';
    return curr;
}

int generate_month(int y, int m, int curr)
{
    int leap = is_leap(y);
    for (int i = 1; i <= month[leap][m]; i++)
        curr = generate_day(y, m, i, curr);
    return curr;
}

int generate_year(int y, int curr)
{
    for (int i = 1; i <= 12; i++)
        curr = generate_month(y, i, curr);
    return curr;
}

void generate_s()
{
    for (int i = 3; i <= 31; i++)
        len = generate_day(2021, 1, i, len);
    for (int i = 2; i <= 12; i++)
        len = generate_month(2021, i, len);
    for (int i = 2022; i <= 2099; i++)
        len = generate_year(i, len);
}

int main()
{
    int n = 0;
    char a[A_LEN] = "\0";
    generate_s();
    cin >> n;
    while(n--)
    {
        cin >> a;
        cout << strstr(s, a) - s + 1 << endl;
    }
    return 0;
}
