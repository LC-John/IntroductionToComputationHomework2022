/*****
��Ŀ����

��ҽʱ�Բ�֢ͬ״�Ĳ��˷����Ƿǳ���Ҫ�ģ���������Ϊ��������רҵ��ҽ�������Ŀǰһ����n�����ˣ������1~n���ʼÿ
�����˵�֢״δ�����ࡣÿ����������һ�������ļ��ϡ�
����Ҫ����m�������������������֣�
��M a b��������֢״��ͬ�������Ϊa��b�������������ڼ��Ϻϲ���������������Ѿ���ͬһ�������У���������������
��Q a b����ѯ�ʱ��Ϊa��b�����������Ƿ���ͬһ�������У�

��������

��һ����������n��m��1��n,m��100
������m�У�ÿ�а���һ������ָ�ָ��Ϊ��M a b����Q a b���е�һ�֡�

�������

����ÿ��ѯ��ָ�Q a b������Ҫ���һ����������a��b��ͬһ�����ڣ��������Yes�������������No����ÿ�����ռһ�С�

��������

4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4

�������

Yes
No
Yes
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
int category[MAX_N] = {0};

void debug(int n)
{
    for (int i = 1; i <= n; i++)
        cout << i << "(" << category[i] << ")" << " ";
    cout << endl;
}

int main()
{
    int n = 0, m = 0, a = 0, b = 0;
    char opt = '\0';

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        category[i] = i;

    while(m--)
    {
        cin >> opt >> a >> b;
        switch(opt)
        {
        case 'M':
            if (category[a] == category[b])
                break;
            for (int i = 1; i <= n; i++)
                if (i != b && category[i] == category[b])
                    category[i] = category[a];
            category[b] = category[a];
            break;
        case 'Q':
            if (category[a] == category[b])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        default: break;
        }
        // debug(n);
    }

    return 0;
}
