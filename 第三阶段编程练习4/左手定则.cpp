/*****
题目描述

玩过RPG（尤其是国产RPG）的童鞋都应该对迷宫这种神棍的设定深恶痛绝，尤其是当你转了半小时之后发现回到
了原地，这种感觉真是无比的痛苦。。。万一游戏还中途崩溃了那真是连掀桌子、砸键盘、摔鼠标的心都有了……
经过无数次的TRIAL AND ERROR之后，玩家终于下定决心认定迷宫存在的意义就是延长游戏时间，SO，他决定借
鉴著名的左手定则（就是在每一个路口，我们都选择最左边的方向，左转的优先级最高，其次为向前，最后为右
转，如果实在走进了一个死胡同，那就连续右转两次，回头向后走。稍微研究一下这种走迷宫的方法，我们就发
现在这个过程中，事实上我们的左手可以始终放在墙上。）对迷宫进行探索。
但是呢，左手定则并不能保证遍历到迷宫中的每一个点。悲剧的是，某项重要的通关道具被放在了这个迷宫中……
幸运的是，游戏迷宫的地图可以绘制出来，现在请求你的帮助。对于一个给定的地图，他想知道是不是能够通过
左手定则取得这件道具。

关于输入

多组数据。
对于每组数据，第一行有两个整数N,M代表接下来有n行字符串，每行m个字符，其中0<n<=100,0<m<=100表示一个
n×m的迷宫。
其中‘#’表示墙，‘S’表示起点，‘T’表示道具，‘.’表示空地。
接下来是一个方向（NSWE），表示起始面向的方向。
数据保证最外一圈都是墙。

关于输出

对于每组数据输出一行。‘YES’表示可以到达，‘NO’表示无法到达。

例子输入

8 10
##########
#...T....#
#.####...#
#.#..#.#.#
#.#....#.#
#.####.#.#
#......#S#
##########
N
8 10
##########
#........#
#.####...#
#.#T.#.#.#
#.#....#.#
#.####.#.#
#......#S#
##########
N
8 10
##########
#....#...#
#..#.#...#
#..#.....#
#..#.#S###
#..#.#...#
#....#T..#
##########
N

例子输出

YES
NO
YES
*****/

#include<iostream>
#include<cstring>
using namespace std;

#define MAX_N 210
#define ND 4
#define NCHAR 26

bool v[MAX_N][MAX_N][ND];           // visit数组
int d[ND][2] = {                    // 方向
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}    // 北，东，南，西
};
char maze[MAX_N][MAX_N];            // 迷宫
int n = 0, m = 0;


/** 按左手定则向下一个位置行走 **/
void trans(int &x, int &y, int &dir, int dir_to) // 通过引用直接修改x，y和dir
{
    dir = (dir + dir_to + ND) % ND;
    x += d[dir][0];
    y += d[dir][1];
}

bool dfs(int x, int y, int dir)
{
    if(maze[x][y] == 'T')   // 走到目的地
        return true;        // 返回true
    for(int i  = -1; i < 3; i++)    // -1左，0前，1右，2后
    {
        int dx = x,dy = y, d = dir;
        trans(dx, dy, d, i);        // 得到下一位置和方向
        if(v[dx][dy][d])    // 若已经走过
            return false;   // 则说明进入了循环，返回false
        if(maze[dx][dy] != '#' && !v[dx][dy][d])    // 走到下一位置
        {
            v[dx][dy][d] = true;
            return dfs(dx, dy, d);  // 递归调用
        }
    }
    return false;
}

int main()
{
    int ss[NCHAR];      // 字符到方向的转换
    int sx = 0, sy = 0; // 起始位置
    char dir = '\0';
    ss['N' - 'A'] = 0;
    ss['E' - 'A'] = 1;
    ss['S' - 'A'] = 2;
    ss['W' - 'A'] = 3;
    while(cin >> n >> m)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
                if(maze[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
            }
        cin >> dir;
        memset(v, 0x00, sizeof(v));
        if(dfs(sx, sy, ss[dir - 'A']))
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
    }
}
