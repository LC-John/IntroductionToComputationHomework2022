/*****
题目描述

有一个N x N（N为奇数，且1<=N<=10）的矩阵，矩阵中的元素都是字符。这个矩阵可能会按照如下的几种变幻法则之一进行变幻（只会变幻一次）。
现在给出一个原始的矩阵，和一个变幻后的矩阵，请编写一个程序，来判定原始矩阵是按照哪一种法则变幻为目标矩阵的。
1. 按照顺时针方向旋转90度；
如：
1 2 3          7 4 1
4 5 6  变幻为  8 5 2
7 8 9          9 6 3
2. 按照逆时针方向旋转90度；
如：
1 2 3         3 6 9
4 5 6  变幻为  2 5 8
7 8 9          1 4 7
3. 中央元素不变（如下例中的 5），其他元素（如下例中的3）与“以中央元素为中心的对应元素”（如下例中的7）互换；
如：
1 2 3         9 8 7
4 5 6  变幻为  6 5 4
7 8 9          3 2 1
4. 保持原始矩阵，不变幻；
5. 如果 从原始矩阵 到 目标矩阵 的变幻，不符合任何上述变幻，请输出5

关于输入

第一行：矩阵每行/列元素的个数 N；
第二行到第N+1行：原始矩阵，共N行，每行N个字符；
第N+2行到第2*N+1行：目标矩阵，共N行，每行N个字符；

关于输出

只有一行，从原始矩阵 到 目标矩阵 的所采取的 变幻法则的编号。

例子输入

5
a b c d e
f g h i j
k l m n o
p q r s t
u v w x y
y x w v u
t s r q p
o n m l k
j i h g f
e d c b a

例子输出

3
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

char arr[2][MAX_N][MAX_N] = {""};
char tgt[MAX_N][MAX_N] = {""};
int n = 0;

/** 输出矩阵arr[cur]矩阵，用于debug **/
void print(int cur)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[cur][i][j] << " ";
        cout << endl;
    }
}

/** 比对arr[cur]和tgt是否一样 **/
bool cmp(int cur)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[cur][i][j] != tgt[i][j])
                return false;
    return true;
}

/** 将arr[cur]顺时针转90度，结果储存在arr[nxt]中，返回nxt **/
int rotate90_clockwise(int cur)
{
    int nxt = 1 - cur;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[nxt][j][n - 1 - i] = arr[cur][i][j];
    return nxt;
}

/** 将arr[cur]中心对称，结果储存在arr[nxt]中，返回nxt **/
int centrosymmetrize(int cur)
{
    int nxt = 1 - cur;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[nxt][n - 1 - i][n - 1 - j] = arr[cur][i][j];
    return nxt;
}

int main()
{
    int cur = 0;

    /** 读入数据 **/
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[cur][i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> tgt[i][j];

    /** 操作4，保持不动 **/
    if (cmp(cur))
    {
        cout << 4 << endl;
        return 0;
    }

    /** 操作3，中心对称 **/
    cur = centrosymmetrize(cur);
    if (cmp(cur))
    {
        cout << 3 << endl;
        return 0;
    }
    cur = centrosymmetrize(cur);    // 矩阵复原

    /** 操作1，顺时针旋转90度 **/
    cur = rotate90_clockwise(cur);
    if (cmp(cur))
    {
        cout << 1 << endl;
        return 0;
    }

    /** 操作2，逆时针旋转90度 **/
    cur = rotate90_clockwise(cur);  // 在顺时针旋转90度的基础之上，再旋转两次
    cur = rotate90_clockwise(cur);  // 等同于逆时针旋转90度
    if (cmp(cur))
    {
        cout << 2 << endl;
        return 0;
    }

    /** 操作5，其它 **/
    cout << 5 << endl;
    return 0;
}
