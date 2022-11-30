/*****
题目描述

Dzx从日本回来了，并为TN准备了礼物----一个恐龙模型。TN想把它尽快拼好，但是由于模型很庞大，
TN又实在比较懒，所以他希望你为他寻找一个最节省时间的拼装方案。
模型是由N个零件组成的，每次TN可以选取两个零件拼装在一起来组成一个新的零件，直到得到完整的
模型。由于零件的复杂程度不同，TN每次拼装所需要的时间也是不同的，对于两个零件A和B，假设他
们的复杂程度分别为a和b，则TN要将这两个零件拼装在一起所需要的时间为a+b，而这由两个零件所组
成的新零件的复杂程度为a+b。
现在TN已经统计出了每个零件的复杂程度，你能告诉他最快的拼装方法需要多少时间么？

关于输入

Line 1： N (1 <= N <= 10000)，零件数目
Line 2： N Integers，表示每个零件的复杂程度

关于输出

最快的拼装方案所需要的时间

例子输入

3
1 2 9

例子输出

15

提示信息

每次都选择当前最小的两个零件。
*****/

#include <iostream>
using namespace std;

#define LEFT(x)     (x)*2+1 // Left child index of x
#define RIGHT(x)    (x)*2+2 // Right child index of x
#define PARENT(x)   (x-1)/2 // Parent index of x

#define HEAP_SIZE 200200
#define HEAP_BOTTOM 0x80000000

int heap[HEAP_SIZE] = {0};  // min_heap, where parent <= left and parent <= right
int _size = 0;

void swap_heap(int i, int j)
{
    int tmp = heap[j];
    heap[j] = heap[i];
    heap[i] = tmp;
}

void push_heap(int num)
{
    int i = _size;
    heap[_size++] = num;
    while(i > 0 && heap[i] < heap[PARENT(i)])
    {
        swap_heap(i, PARENT(i));
        i = PARENT(i);
    }
}

void min_heap(int i)
{
    int l = LEFT(i), r = RIGHT(i), small = i;
    if (l < _size && heap[l] < heap[small])
        small = l;
    if (r < _size && heap[r] < heap[small])
        small = r;
    if (i != small)
    {
        swap_heap(i, small);
        min_heap(small);
    }
}

void create_heap()
{
    for (int i = PARENT(_size - 1); i >= 0; i--)
        min_heap(i);
}

int pop_heap()
{
    if (!_size)
        return HEAP_BOTTOM;
    _size--;
    int r = heap[0];
    swap_heap(0, _size);
    min_heap(0);
    return r;
}

int main()
{
    int ans = 0, t = 0;
    cin >> _size;
    for (int i = 0; i < _size; i++)
        cin >> heap[i];
    create_heap();
    while (_size > 1)
    {
        t = pop_heap() + pop_heap();
        ans += t;
        push_heap(t);
    }
    cout << ans << endl;
    return 0;
}
