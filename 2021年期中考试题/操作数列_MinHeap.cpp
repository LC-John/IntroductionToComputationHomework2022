/*****
题目描述

给定一个初始数字集合，对其做如下两种操作：
1. 添加一个新的数字
2. 将集合中当前最小的数字取出（输出并删除），如果最小的数字有多个，只取出其中一个。

关于输入

输入文件第一行为整数n，接下来n个整数，表示初始的数字集合。
随后是一个整数m，表示操作的个数。接下来m行，每行表示一个操作，有两种输入格式：
ADD x：表示往数字集合中添加一个x
EXTRACT-MIN：表示取出当前数字集合中最小的数
注意数字集合中的数随时都有重复。
n>=0
m>=0
n+m<=200000

关于输出

对于每一个EXTRACT-MIN，输出最小的数值。如果当前EXTRACT-MIN操作时集合为空，则输出"NULL"

例子输入

5
1
2
1
2
3
11
EXTRACT-MIN
EXTRACT-MIN
EXTRACT-MIN
ADD 1
EXTRACT-MIN
EXTRACT-MIN
EXTRACT-MIN
EXTRACT-MIN
ADD 5
EXTRACT-MIN
EXTRACT-MIN

例子输出

1
1
2
1
2
3
NULL
5
NULL

提示信息

自己实现相应的数据结构，不能使用系统的库函数。
*****/

#include <cstdio>

#define LEFT(x)     (x)*2+1 // Left child index of x
#define RIGHT(x)    (x)*2+2 // Right child index of x
#define PARENT(x)   (x-1)/2 // Parent index of x

#define OPT_LEN 100
#define HEAP_SIZE 200200
#define HEAP_BOTTOM 0x80000000

int heap[HEAP_SIZE] = {0};
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

void print_heap()
{
    for (int i = 0; i < _size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}


int main()
{
    int n = 0, num = 0;
    char opt[OPT_LEN] = "\0";

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &num);
        heap[_size++] = num;
    }
    create_heap();
    // print_heap();

    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", opt);
        switch(opt[0])
        {
        case 'E':
            if (!_size)
                printf("NULL\n");
            else
                printf("%d\n", pop_heap());
            // print_heap();
            break;
        case 'A':
            scanf("%d", &num);
            push_heap(num);
            // print_heap();
            break;
        default: break;
        }
    }

    return 0;
}
