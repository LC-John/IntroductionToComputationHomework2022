/*****
��Ŀ����

N����Χ��һȦ�洫����Ϸ����ʼʱ����һ����������ÿ���˰��򴫸����ֵĵ�K���ˣ�
���У�1 <= K <= N/2����������K��ʹ�õ�һ���������õ���֮ǰ��ÿ���˶��ù���

��������

������N���ٶ�N��ֵ����2

�������

K�����ֵ

��������

9

�������

4
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000000
bool flag[MAX_N] = {false};

int main()
{
    int n = 0, cnt = 0, curr = 0;
    while(cin >> n)
        for (int i = n / 2; i > 0; i--)
        {
            /** ��ʼ�� **/
            memset(flag, 0x00, sizeof(flag));
            cnt = 0;
            curr = 0;

            /** ��������ֱ���õ�����˴�ǰ�Ѿ��ù��� **/
            while (!flag[curr])
            {
                flag[curr] = true;
                curr = (curr + i) % n;
                cnt++;
            }
            if (cnt == n)
            {
                cout << i << endl;
                break;
            }
        }
    return 0;
}
