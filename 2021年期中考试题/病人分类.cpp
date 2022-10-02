/*****
题目描述

就医时对不同症状的病人分类是非常重要的，这样可以为病人找最专业的医生来就诊。目前一共有n个病人，编号是1~n，最开始每
个病人的症状未被分类。每个病人属于一个单独的集合。
现在要进行m个操作，操作共有两种：
“M a b”，由于症状相同，将编号为a和b的两个病人所在集合合并，如果两个病人已经在同一个集合中，则忽略这个操作；
“Q a b”，询问编号为a和b的两个病人是否在同一个集合中；

关于输入

第一行输入整数n和m，1≤n,m≤100
接下来m行，每行包含一个操作指令，指令为“M a b”或“Q a b”中的一种。

关于输出

对于每个询问指令”Q a b”，都要输出一个结果，如果a和b在同一集合内，则输出“Yes”，否则输出“No”。每个结果占一行。

例子输入

4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4

例子输出

Yes
No
Yes
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
int category[MAX_N] = {0};

void debug(int n)
{
    for (int i = 1; i <= n; i++)
        cout << i << "(" << category[i] << ")" << " ";
    cout << endl;
}

int main()
{
    int n = 0, m = 0, a = 0, b = 0;
    char opt = '\0';

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        category[i] = i;

    while(m--)
    {
        cin >> opt >> a >> b;
        switch(opt)
        {
        case 'M':
            if (category[a] == category[b])
                break;
            for (int i = 1; i <= n; i++)
                if (i != b && category[i] == category[b])
                    category[i] = category[a];
            category[b] = category[a];
            break;
        case 'Q':
            if (category[a] == category[b])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        default: break;
        }
        // debug(n);
    }

    return 0;
}
