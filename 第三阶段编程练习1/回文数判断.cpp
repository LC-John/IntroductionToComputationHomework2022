/*****
��Ŀ����

����һ����������������9λ�����ж����Ƿ�Ϊ����������ν��������ָ������������ȵ�����
�磬123454321��12344321�����ǣ����yes,�����ǣ����no

��������

һ��������

�������

���ǣ����yes
�����ǣ����no

��������

135797531

�������

yes
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100

char num[MAX_LEN] = "\0";

/** �ݹ������ **/
bool check_palindrome(int l, int r) // l��r�ֱ�Ϊ���ҶԳ�λ�õ��±�
{
    if (l >= r)             // ��l����r��˵���Ѿ�ȫ������꣬��֮ǰ�Ĳ��ֶ�����Գ�
        return true;        // ��ݹ���ֹ������true
    if (num[l] != num[r])   // һ��l��r���ַ���ͬ����˵�����Գƣ����ǻ��ģ�
        return false;       // ��ݹ���ֹ��ֱ�ӷ���false
    return check_palindrome(l + 1, r - 1);  // l����һλ��r����һλ���ݹ�
}

int main()
{
    cin >> num;
    if (check_palindrome(0, strlen(num) - 1))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
