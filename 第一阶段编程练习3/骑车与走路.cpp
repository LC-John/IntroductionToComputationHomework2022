/*****
��Ŀ����

�ڱ���У԰��,û�����г�,�Ͽΰ��»�ܲ�����.��ʵ����,����ȥ���κ����鶼���ﳵ��,��Ϊ�ﳵ��Ҫ
�ҳ���������ͣ����������,��Ҫ����һЩʱ��.�����ҵ����г�,�������������г���ʱ��Ϊ27��;ͣ��
������ʱ��Ϊ23��;����ÿ������1.2��,�ﳵÿ������3.0��.���ж��߲�ͬ�ľ���ȥ����,���ﳵ�컹��
��·��.

��������

��һ��Ϊ����������ݵ�����n
���ÿһ������Ϊһ�ΰ���Ҫ���ߵľ���,��λΪ��.

�������

��Ӧÿ������,����ﳵ��,���һ��"Bike";�����·��,���һ��"Walk";���һ����,���һ��"All".

��������

4
50
90
120
180

�������

Walk
Walk
Bike
Bike
*****/

#include <iostream>
using namespace std;

#define UNLOCK 27
#define LOCK 23
#define V_WALK 1.2
#define V_BIKE 3.0

int main()
{
    int n = 0;
    double d = 0, t_walk = 0, t_bike = 0;
    cin >> n;
    while(n--)
    {
        cin >> d;
        t_walk = d / V_WALK;
        t_bike = d / V_BIKE + UNLOCK + LOCK;
        if (t_walk < t_bike)
            cout << "Walk" << endl;
        else if (t_walk == t_bike)
            cout << "All" << endl;
        else
            cout << "Bike" << endl;
    }
    return 0;
}
