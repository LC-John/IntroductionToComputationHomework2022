/*****
��Ŀ����

С������������Ϸ��2k��С����Χ��һ��Ȧ��������δ�1��2k������k�����ݺ��ˣ���k�����ݻ��ˡ�
��Ϸ�������£��ӵ�һ��С����ʼ����������mʱ����m��С�����߳���Ȼ�����һ��С����ʼ���ظ�
ǰ��Ĺ��̣�ֱ����ʣ��k��С����ֹͣ���ˡ�����ϣ�����߳��Ķ��ǻ��ˡ���֪ǰk���Ǻ��ˣ���k��
�ǻ��ˣ�����Ҫ�������ÿһ��k��ȷ��һ����С��������m��ʹ�ð���Ϸ�����߳���k����ֽ���ǻ��ˡ�

��������

�����ж��У�ÿ��һ���Ǹ�����k��k������13��������Ϊ0�����־�����������

�������

����ÿһ��������k�������С��m

��������

1
4
0

�������

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
