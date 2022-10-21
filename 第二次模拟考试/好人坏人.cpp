/*****
题目描述

小朋友们在玩游戏：2k个小朋友围成一个圈，标号依次从1到2k，其中k个扮演好人，另k个扮演坏人。
游戏规则如下：从第一个小孩开始报数，报到m时，第m个小孩被踢出，然后从下一个小孩开始，重复
前面的过程，直到还剩下k个小孩，停止踢人。我们希望被踢出的都是坏人。已知前k个是好人，后k个
是坏人，现在要求你对于每一个k，确定一个最小的正整数m，使得按游戏规则踢出的k个孩纸都是坏人。

关于输入

输入有多行，每行一个非负整数k，k不大于13。若输入为0，则标志着输入结束。

关于输出

对于每一个正整数k，输出最小的m

例子输入

1
4
0

例子输出

2
30
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

int que[MAX_N] = {0};
int n = 0;

void init_que(int k)
{
    n = 2 * k;
    for (int i = 0; i < n; i++)
        que[i] = i;
}

void remove_que(int idx)
{
    for (int i = idx + 1; i < n; i++)
        que[i - 1] = que[i];
    n--;
}

void print_queue(int curr)
{
    for (int i = 0; i < n; i++)
    {
        if (i == curr)
            cout << "<";
        cout << que[i];
        if (i == curr)
            cout << ">";
        cout << " ";
    }
    cout << endl;
}

int main()
{
    int k = 0;
    int curr = 0;
    while(cin >> k)
    {
        if (!k)
            return 0;
        for (int m = k + 1; true; m++)
        {
            curr = 0;
            init_que(k);
            //print_queue(curr);
            while (n > k)
            {
                curr = (curr + m - 1) % n;
                if (que[curr] < k)
                    break;
                remove_que(curr);
                if (curr >= n)
                    curr -= n;
                //print_queue(curr);
            }
            if (n <= k)
            {
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}
