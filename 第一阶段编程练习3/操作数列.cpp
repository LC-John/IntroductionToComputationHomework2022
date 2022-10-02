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

#include<cstdio>

#define OPT_LEN 20

class Node
{
public:
    int val;
    int cnt;
    Node* lt;   // Less than
    Node* gt;   // Greater than
    Node* p;    // Parent

    Node(int num)   // Constructor
    {
        val = num;
        cnt = 1;
        lt = NULL;
        gt = NULL;
        p = NULL;
    }

    void print()
    {
        for (int i = 0; i < cnt; i++)
            printf("%d ", val);
    }
};

Node* root = NULL;
Node* min_node = NULL;

void set_min_node(Node* node)
{
    if (!node)
    {
        min_node = NULL;
        return;
    }
    if (!node->lt)
    {
        min_node = node;
        return;
    }
    return set_min_node(node->lt);
}

void insert_node(int num, Node* node)
{
    if (!root)
    {
        root = new Node(num);
        set_min_node(root);
        return;
    }
    if (num == node->val)
    {
        node->cnt++;
        return;
    }
    else if (num < node->val)
    {
        if (!node->lt)
        {
            node->lt = new Node(num);
            node->lt->p = node;
            set_min_node(min_node);
            return;
        }
        insert_node(num, node->lt);
    }
    else
    {
        if (!node->gt)
        {
            node->gt = new Node(num);
            node->gt->p = node;
            return;
        }
        insert_node(num, node->gt);
    }
}

void remove_min_node()
{
    Node *tmp_p = NULL, *tmp_gt = NULL;
    if (!min_node)
        return;
    min_node->cnt--;
    if (min_node->cnt)
        return;
    tmp_p = min_node->p;
    tmp_gt = min_node->gt;
    delete min_node;
    if (!tmp_p)
    {
        root = tmp_gt;
        if (root)
            root->p = NULL;
        set_min_node(root);
    }
    else
    {
        tmp_p->lt = tmp_gt;
        if (tmp_gt)
            tmp_gt->p = tmp_p;
        set_min_node(tmp_p);
    }
}

void traverse_print_node(Node *node)
{
    if (!node)
        return;
    traverse_print_node(node->lt);
    node->print();
    traverse_print_node(node->gt);
}

void print_tree()
{
    if (!root)
        printf("NULL\n");
    else
    {
        traverse_print_node(root);
        printf("   MIN=%d\n", min_node->val);
    }
}

int main()
{
    int n = 0, num = 0;
    char opt[OPT_LEN] = "\0";

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &num);
        insert_node(num, root);
    }
    // print_tree();

    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", opt);
        switch(opt[0])
        {
        case 'E':
            if (min_node)
                printf("%d\n", min_node->val);
            else
                printf("NULL\n");
            remove_min_node();
            // print_tree();
            break;
        case 'A':
            scanf("%d", &num);
            insert_node(num, root);
            // print_tree();
            break;
        default: break;
        }
    }

    return 0;
}
