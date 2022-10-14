/*****
题目描述

随着人们生活水平的日益提高，健康越来越受到大家的关注。营养搭配，合理膳食，开始成为人们日常
饮食追求的目标。营养学家希望能在计算机上开发一套饮食指导系统，来帮助人们检查每日饮食搭配是
否合理，并提出指导意见。
假设我们只考虑一种营养成分：钙。已知人体每天需摄入600-1000毫克钙。钙的主要来源有：豆腐，
110毫克/100克；牛奶，120毫克/100克；海带，2250毫克/100克；虾米，880毫克/100克。当用户输入
四种食物每天的摄入量后，系统就会判断钙的摄入量是否合理。

关于输入

一行，4个整数，分别表示用户每日摄入的豆腐、牛奶、海带、虾米的量，单位克

关于输出

一行，饮食指导系统的反馈结果
如果摄入过量，输出"OVER"；如果摄入不足，输出"UNDER"；如果适量，输出"FINE"

例子输入

50 250 20 10

例子输出

FINE
*****/

#include <iostream>
using namespace std;

#define N 4
#define LOWER 600
#define UPPER 1000

double food_cal[N] = {1.1, 1.2, 22.5, 8.8};

int main()
{
    double cal = 0, m = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> m;
        cal += m * food_cal[i];
    }
    if (cal < LOWER)
        cout << "UNDER" << endl;
    else if (cal > UPPER)
        cout << "OVER" << endl;
    else
        cout << "FINE" << endl;
    return 0;
}
