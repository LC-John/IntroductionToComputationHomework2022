/*****
题目描述

有9个时钟，排成一个3*3的矩阵。

现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。
如右表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。
移动 影响的时钟
1 ABDE
2 ABC
3 BCEF
4 ADG
5 BDEFH
6 CFI
7 DEGH
8 GHI
9 EFHI

关于输入

从标准输入设备读入9个整数，表示各时钟指针的起始位置。0=12点、1=3点、2=6点、
3=9点。

关于输出

输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号大小，
输出结果。

例子输入

3 3 0
2 2 2
2 1 2

例子输出

4 5 8 9
*****/

#include <iostream>
using namespace std;

#define N_CLOCK 9
#define MAX_STATE 0xfffff   // more than 18 ones
#define N_OP 9
#define MAX_OP_LEN 10

int visit[MAX_STATE] = {0};
int q[MAX_STATE] = {0}, q_back = 0, q_front = 0;    // Queue

const char op[N_OP + 1][MAX_OP_LEN] =           // Operation
{
    "", "ABDE", "ABC", "BCEF", "ADG", "BDEFH",  // 1-5
    "CFI", "DEGH", "GHI", "EFHI"                // 6-9
};

/** Check if the queue is empty **/
bool q_empty()
{
    return q_back == q_front;
}

/** Push item into the queue **/
void q_push(int enc)
{
    q[q_back++] = enc;
}

/** Pop item from the queue **/
int q_pop()
{
    return q[q_front++];
}

/** Update a single clock **/
int update_clock(int enc, char id, int clock_wise)
{
    int i = (id - 'A') * 2;
    return (((((enc >> i) & 3) + clock_wise) & 3) << i) | (~(3 << i) & enc);
}

/** Update multiple clocks according to the operation **/
int update(int enc, int op_idx, int clock_wise)
{
    for (int i = 0; op[op_idx][i] != '\0'; i++)
        enc = update_clock(enc, op[op_idx][i], clock_wise);
    return enc;
}

/** Bit encoding of the clocks **/
int encode()
{
    int n = 0, enc = 0;
    for (int i = 0; i < N_CLOCK; i++)
    {
        cin >> n;
        enc = enc + (n << (i * 2));
    }
    return enc;
}

void decode(int enc)
{
    for (int i = 0; i < N_CLOCK; i++)
        cout << (char)('A' + i) << " ";
    cout << endl;
    for (int i = N_CLOCK - 1; i >= 0; i--)
    {
        cout << (enc & 3) << " ";
        enc = (enc >> 2);
    }
    cout << endl;
}

/** Print the operation sequence **/
void output_op(int enc, int init_enc)
{
    int op_idx = visit[enc];
    enc = update(enc, op_idx, -1);  // Reverse the operation to recover the previous encoding
    if (enc == init_enc)
    {
        cout << op_idx;
        return;
    }
    output_op(enc, init_enc);
    cout << " " << op_idx;
}

int main()
{
    int init_enc = encode(), enc = 0, tmp_enc = 0;
    q_push(init_enc);
    visit[init_enc] = -1;
    while(!q_empty())
    {
        enc = q_pop();
        for (int i = 1; i <= N_OP; i++)
        {
            tmp_enc = update(enc, i, 1);
            if (visit[tmp_enc])
                continue;
            visit[tmp_enc] = i; // Recording the last operation in visit
            if (!tmp_enc)
            {
                output_op(tmp_enc, init_enc);
                cout << endl;
                return 0;
            }
            q_push(tmp_enc);
        }
    }
    return 0;
}
