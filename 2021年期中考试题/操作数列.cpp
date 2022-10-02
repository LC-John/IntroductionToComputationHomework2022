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

#define MAX_INT 200200
#define OPT_LEN 20

int bucket[MAX_INT] = {0};
int _min = MAX_INT, _size = 0;

void load(int num)
{
    bucket[num]++;
    if (num < _min)
        _min = num;
    _size++;
}

int unload_min()
{
    int ret = 0;
    if (!bucket[_min])
        while(!bucket[_min])
            _min++;
    ret = _min;
    bucket[_min]--;
    _size--;
    return ret;
}

int main()
{
    int n = 0, num = 0;
    char opt[OPT_LEN] = "\0";

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &num);
		load(num);
	}

    scanf("%d", &n);
	while(n--)
    {
	    scanf("%s", opt);
	    switch(opt[0])
	    {
        case 'E':
            if(_size)
                printf("%d\n", unload_min());
			else
				printf("NULL\n");
            break;
        case 'A':
            scanf("%d", &num);
			load(num);
            break;
        default: break;
	    }
	}

	return 0;
}
