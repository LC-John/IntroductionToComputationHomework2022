/*****
题目描述

学校里一共有n个学生。这n个学生里一共有m对朋友关系。
在流感发作期，每个健康学生都要看望当天他生病的朋友（如果有的话），并在第二天被传
染上疾病（除非他在免疫期内）；
每个生病的学生在第二天都会痊愈，并在这一天具有免疫性。从第三天起，看望生病的朋友
将再次使他染上流感。
初始时（第一天），只有一个学生患有流感。试问多少天后流感会自动结束。

关于输入

第一行输入两个正整数n和m。
接下来m行每行两个正整数x,y，表示编号为x的学生和编号为y的学生是一对朋友。输入数据
保证每一对朋友关系只描述一次。
最后一行输入一个正整数，代表初始时患有流感的学生的编号。
n,m <= 100,000。

关于输出

输出多少天后流感会结束。
如果天数超过2,000,000,000，则视为流感不会结束，输出-1。

例子输入

4 4
1 2
2 3
3 4
2 4
1

例子输出

3

提示信息

第一天1号学生生病，2号学生访问他；
第二天2号学生生病，其它三个学生访问他，由于1号处于免疫期，未患流感；
第三天3、4号学生生病，2号学生访问他们。
第四天3、4号学生痊愈，流感结束。
*****/

#include <iostream>
using namespace std;

#define MAX_D 2000000000
#define MAX_N 100100
#define MAX_M 3000

#define HEA 0   // Healthy
#define ILL 1   // Sick
#define IMM 2   // Immune

int stu[MAX_N][MAX_M] = {0};
int status[MAX_N] = {0};
int n = 0, m = 0;
int cur = 0, ill[2][MAX_N] = {0};

int main()
{
    int d = 0;
    bool flag = true;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        stu[x][++stu[x][0]] = y;
        stu[y][++stu[y][0]] = x;
    }
    cin >> ill[cur][1];
    ill[cur][0] = 1;
    while (d < MAX_D)
    {
        int nxt = 1 - cur;
        if (ill[cur][0] == 0)
        {
            cout << d;
            flag = false;
            break;
        }
        ill[nxt][0] = 0;
        /* Infect the healthy */
        for (int i = 1; i <= ill[cur][0]; i++)
            for (int j = 1; j <= stu[ill[cur][i]][0]; j++)
                if (status[stu[ill[cur][i]][j]] == HEA)
                {
                    ill[nxt][++ill[nxt][0]] = stu[ill[cur][i]][j];
                    status[stu[ill[cur][i]][j]] = ILL;
                }
        /* Lost immunity */
        for (int i = 1; i <= ill[cur][0]; i++)
            for (int j = 1; j <= stu[ill[cur][i]][0]; j++)
                if (status[stu[ill[cur][i]][j]] == IMM)
                    status[stu[ill[cur][i]][j]] = HEA;
        /* Recover & gain immunity */
        for (int i = 1; i <= ill[cur][0]; i++)
            status[ill[cur][i]] = IMM;
        d++;
        cur = nxt;
    }
    if (flag)
        cout << -1;
    return 0;
}
