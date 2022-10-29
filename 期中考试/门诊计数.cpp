/*****
��Ŀ����

ҽԺĳ���������Ͽ�����Сʱ����8�㿪ʼ�����Ŷӣ�9�㿪ʼ��ʽ���ÿ��������Ҫ��10����
(�����ʣ�಻��10���ӣ��򲻽�������)��11������������������n��n<=20�������˵ĵ���ʱ
�䣨����8��ķ���������������յõ�����Ĳ�������

��������

��һ��Ϊ������n��
֮����n�У�ÿ��Ϊ���˵����ʱ��

�������

һ���������ܵõ�����Ĳ�����

��������

10
5
10
160
180
20
110
145
70
100
200

�������

8
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define BEGIN_TIME 60
#define END_TIME 180
#define TIME_COST 10

int arrive[MAX_N] = {0};

int main()
{
    int n = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arrive[i];
    sort(arrive, arrive + n);

    for (int curr = 0, time = BEGIN_TIME; curr < n && time < END_TIME; curr++)
    {
        if (arrive[curr] < time)
            time += TIME_COST;
        else
            time = arrive[curr] + TIME_COST;
        if (time < END_TIME)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
