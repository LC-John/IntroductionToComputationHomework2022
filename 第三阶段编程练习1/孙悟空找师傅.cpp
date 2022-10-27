/*****
题目描述

“大师兄，师傅又被妖怪抓走了！”，沙师弟说道。悟空听到这个消息，便立刻前去救师傅。可是当悟空来到妖怪洞府时，
发现妖怪给自己设了一个阵，只有成功破解这个阵，悟空才能救出师傅。请帮悟空判断他能否救出师傅。

关于输入

输入第一行是两个数字m和n，表示该阵为m*n大小（0 < m,n <= 50，m为行，n为列）。接下来是一个m*n的矩阵表示这个
阵。其中0为该阵中可走的路，1为墙（即不能走的位置），2为悟空的位置，3为师傅的位置。悟空只有四个可行的行走方
向：即，上、下、左、右，不能斜对角线穿越。每行输入的数据之间都是空格间隔。

关于输出

输出只有一行，"Yes"或"No"表示悟空是否可以成功救出师傅（悟空能走到师傅的位置即可救出师傅）。

例子输入

8 7
1 1 1 1 1 1 3
1 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 0 0 1 1 1
1 1 1 0 0 0 1
1 0 0 0 1 0 1
1 0 1 1 1 0 1
2 0 1 1 1 0 0

例子输出

Yes
*****/

#include <iostream>
using namespace std;

#define MAX_N 100
#define EMPTY 0
#define WALL 1
#define WUKONG 2
#define SIFU 3
#define DIR_N 4

int arr[MAX_N][MAX_N] = {0};
int n = 0, m = 0;
int dr[DIR_N] = {0, 0, 1, -1};
int dc[DIR_N] = {1, -1, 0, 0};

void print()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout <<endl;
}

/** 遍历数组，将所有EMPTY或者SIFU标记为WUKONG **/
void traverse(int r, int c, int step)
{
    // print();
    if ((arr[r][c] == WUKONG && step) || arr[r][c] == WALL) // 撞墙或者回到走过的地方
        return;                                             // 终止
    arr[r][c] = WUKONG;                             // 标记当前位置为WUKONG，表示已经走过了
    for (int d = 0; d < DIR_N; d++)                 // 向四个方向
        traverse(r + dr[d], c + dc[d], step + 1);   // 递归遍历
}

int main()
{
    int st_r = 0, st_c = 0;
    int end_r = 0, end_c = 0;

    /** 读入数据 **/
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == WUKONG)
            {
                st_r = i;
                st_c = j;
            }
            if (arr[i][j] == SIFU)
            {
                end_r = i;
                end_c = j;
            }
        }

    /** 在迷宫四周设置一圈WALL **/
    for (int i = 1; i <= m; i++)
        arr[i][0] = arr[i][n + 1] = WALL;
    for (int j = 1; j <= n; j++)
        arr[0][j] = arr[m + 1][j] = WALL;

    /** 从WUKONG开始遍历标记整个迷宫 **/
    traverse(st_r, st_c, 0);

    /** 检查SIFU位置是否被标记为WUKONG **/
    if (arr[end_r][end_c] ==  WUKONG)   // 若被标记
        cout << "Yes" << endl;          // 则说明可以找到
    else                                // 否则
        cout << "No" << endl;           // 说明找不到
    return 0;
}
