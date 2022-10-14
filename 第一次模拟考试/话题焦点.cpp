/*****
题目描述

微博提供了一种便捷的交流平台。一条微博中，可以提及其它用户。例如Lee发出一条微博为：
“期末考试顺利 @Kim @Neo”，则Lee提及了Kim和Neo两位用户。我们收集了N(1 < N < 10000)
条微博，并已将其中的用户名提取出来，用小于100的正整数表示。通过分析这些数据，我们希望
发现大家的话题焦点人物，即被提及最多的人（题目保证这样的人有且只有一个），并找出那些
提及它的人。

关于输入

输入共两部分
第一部分是微博数量N，1 < N < 10000.
第二部分是N条微博，每条微博占一行，表示为：
发送者a,提及人数k(0 < = k < = 20),然后是k个被提及者b1,b2...bk
其中a和b1,b2...bk均为大于0小于100的整数。它们之间用空格分隔。

关于输出

输出分两行
第一行是被提及最多的人
第二行是提及它的人，按序号从小到大，用空格分开

例子输入

5
1 2 3 4
1 0
90 3 1 2 4
4 2 3 2
2 1 3

例子输出

3
1 2 4
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10100
#define MAX_P 1010

int p[MAX_P][MAX_N] = {0};
int cnt[MAX_P] = {0};

int main()
{
    int N = 0;
    int a = 0, b = 0, n = 0;
    int max_cnt = -1, max_p = -1;
    cin >> N;
    while (N--)
    {
        cin >> a >> n;
        while(n--)
        {
            cin >> b;
            p[b][cnt[b]++] = a;
            if (cnt[b] > max_cnt)
            {
                max_cnt = cnt[b];
                max_p = b;
            }
        }
    }
    sort(p[max_p], p[max_p] + max_cnt);

    cout << max_p << endl << p[max_p][0];
    for (int i = 1; i < max_cnt; i++)
        if (p[max_p][i] != p[max_p][i - 1])
            cout << " " << p[max_p][i];
    cout << endl;
    return 0;
}
