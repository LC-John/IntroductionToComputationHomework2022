/*****
��Ŀ����

����Ŀ�����ݴ������ֲ�����
1. ��ָ�������������һ�����Σ����Ժ���ǰ���еľ����ص�����
2 .ѯ��һ�������Ƿ�����ӵ����о����γɵ�������ȫ���ǡ�
д���������Ӿ��β�����������Եڶ���ѯ�ʲ�������������ǣ��������Yes���������������No��

��������

��һ����һ������n (1<=n<=500)��������n��������
����������n�У�
ÿһ�е�һ������Ϊ0ʱ������ò�Ҫ����¾��Σ����������ĸ�����x1,y1,x2,y2 (0 <= x1 <= 500,
0 <= x2 <= 500, ��x1С��x2 ;  0 <= y1 <= 500, 0 <= y2 <= 500, ��y1С��y2)��
������¾��ε����½�����Ϊ(x1,y1)�����Ͻ�����Ϊ(x2,y2)��
ÿһ�е�һ������Ϊ1ʱ������ò�Ҫ����ѯ�ʣ����������ĸ�����x1,y1,x2,y2 (0 <= x1 <= 500,
0 <= x2 <= 500, ��x1С��x2 ;  0 <= y1 <= 500, 0 <= y2 <= 500, ��y1С��y2)��
������Ҫ��ѯ�ʵľ��ε����½�����Ϊ(x1,y1)�����Ͻ�����Ϊ(x2,y2)��

�������

����ÿһ��ѯ�ʲ������������ľ��α�֮ǰ��ӵľ��θ��ǣ���ô�����Yes��,���������No����

��������

7
1 1 1 3 3
0 1 1 3 2
0 1 1 2 3
1 1 1 2 2
1 1 1 3 3
0 2 2 3 3
1 1 1 3 3

�������

No
Yes
No
Yes
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000
#define EMPTY '#'
#define PAINT '*'

char arr[MAX_N][MAX_N] = {""};

bool check(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            if (arr[i][j] != PAINT)
                return false;
    return true;
}

void paint(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            arr[i][j] = PAINT;
}

int main()
{
    int n = 0, opt = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    memset(arr, EMPTY, sizeof(arr));
    cin >> n;
    while (n--)
    {
        cin >> opt >> x1 >> y1 >> x2 >> y2;
        switch(opt)
        {
        case 0:
            paint(x1, y1, x2, y2);
            break;
        case 1:
            if (check(x1, y1, x2, y2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        default: break;
        }
    }
    return 0;
}
