/*****
��Ŀ����

����ͬѧϲ�������Σ��Ȱ�����ɱ��������ɱ�У���ʱ�����ơ����硱��Ч�����������硱������������һ
���ж���Ϊ������������ֵ��2��9֮�䣨����2��9�������ڸ�������һ���ж��ƵĻ�ɫ�Լ���ֵ�������ж�
һ������ͬѧ�Ƿ�������磿

��������

һ�У��ƵĻ�ɫ���С����ɫ�ڣ�heitao, hongtao, fangpian, meihua����Χ�ڣ���С��1-13��Χ�ڡ�

�������

һ�У������������yes�����������no

��������

heitao 3

�������

yes
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define CORRECT_COLOR "heitao"
#define RANGE_L 2
#define RANGE_R 9
#define MAX_LEN 10

int main()
{
    char color[MAX_LEN] = "";
    int num = 0;
    cin >> color >> num;
    if (!strcmp(CORRECT_COLOR, color) && num >= RANGE_L && num <= RANGE_R)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
