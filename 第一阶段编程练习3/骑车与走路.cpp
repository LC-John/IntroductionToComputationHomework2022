/*****
题目描述

在北大校园里,没有自行车,上课办事会很不方便.但实际上,并非去办任何事情都是骑车快,因为骑车总要
找车、开锁、停车、锁车等,这要耽误一些时间.假设找到自行车,开锁并骑上自行车的时间为27秒;停车
锁车的时间为23秒;步行每秒行走1.2米,骑车每秒行走3.0米.请判断走不同的距离去办事,是骑车快还是
走路快.

关于输入

第一行为待处理的数据的数量n
其后每一行整数为一次办事要行走的距离,单位为米.

关于输出

对应每个整数,如果骑车快,输出一行"Bike";如果走路快,输出一行"Walk";如果一样快,输出一行"All".

例子输入

4
50
90
120
180

例子输出

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
