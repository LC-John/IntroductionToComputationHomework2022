/*****
题目描述

某医院有N位医生（编号依次为1，2，…，N）负责接诊。挂号医师把新来的病人安排到排队人数最少的医生处就诊，
如果两位医生的排队人数相同，则优先安排到编号小的医生处就诊。现给出N位医生的初始排队人数，请输出下一位
到来的病人所就诊医生的编号。

关于输入

共N+1行输入。
第1行包含一个整数：N，医生数量，0 < N <＝ 100。
第2, 3, ..., N+1行，每行包含一个非负整数，依次对应于编号为1,2, ..., N的医生的当前排队人数。

关于输出

输出1行，是下一位病人所就诊的医生编号。

例子输入

10
4
3
2
1
6
5
4
3
2
1

例子输出

4
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
#define MAX_INT 0x7fffffff

int cnt[MAX_N] = {0};

int main()
{
    int n = 0, min_cnt = MAX_INT;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cnt[i];
        if (cnt[i] < min_cnt)
            min_cnt = cnt[i];
    }
    for (int i = 0; i < n; i++)
        if (cnt[i] == min_cnt)
        {
            cout << i+1;
            break;
        }
    return 0;
}
