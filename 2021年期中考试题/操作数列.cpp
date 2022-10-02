/*****
��Ŀ����

����һ����ʼ���ּ��ϣ��������������ֲ�����
1. ���һ���µ�����
2. �������е�ǰ��С������ȡ���������ɾ�����������С�������ж����ֻȡ������һ����

��������

�����ļ���һ��Ϊ����n��������n����������ʾ��ʼ�����ּ��ϡ�
�����һ������m����ʾ�����ĸ�����������m�У�ÿ�б�ʾһ�������������������ʽ��
ADD x����ʾ�����ּ��������һ��x
EXTRACT-MIN����ʾȡ����ǰ���ּ�������С����
ע�����ּ����е�����ʱ�����ظ���
n>=0
m>=0
n+m<=200000

�������

����ÿһ��EXTRACT-MIN�������С����ֵ�������ǰEXTRACT-MIN����ʱ����Ϊ�գ������"NULL"

��������

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

�������

1
1
2
1
2
3
NULL
5
NULL

��ʾ��Ϣ

�Լ�ʵ����Ӧ�����ݽṹ������ʹ��ϵͳ�Ŀ⺯����
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
