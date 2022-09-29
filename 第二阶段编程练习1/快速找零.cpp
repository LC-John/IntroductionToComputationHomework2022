/*****
��Ŀ����

J.P.Flathead���ӻ���������̨�Ϲ�Ӷ���۵��Ͷ��������͵��ˣ������Ǹ��еĺ��ӣ������Ҵ�Ǯ���˿͡�Flathead�Ǹ�С����
�������Ҵ��Ǯ�������Ļ�Ҫ�࣬Ҳ����˵����Ա�����Ҹ����Ǯ���ͻ���
Flathead��Ҫ���дһ��������������Ӧ���Ҷ���quarters��$0.25����dimes($0.10)��nickel($0.05)��pennies($0.01)����
�͡����Ҫ�ҵ�Ǯ��5.00��Ԫ���߸��٣�Flathead�����Ҹ�����Ӳ�ҡ���Ҳ���Ҹ��˿�����������Ӳ�ҡ����磬Ҫ�Ҹ��˿͵�Ǯ��
1.24��Ԫ����ô���˿�Ӧ���õ�4quarters��2dimes��0nickels��4pennies��

��������

�������ݵĵ�һ����һ��������N����ʾ�������ݼ��ĸ�����ÿ�����ݼ�����һ��������ɣ�ռһ�У������������cents�����֣���
C��1 <= C <= 500��

�������

����ÿ�����ݼ�����ӡ�����ݼ�����ţ�һ���ո�������⴮�ַ�����
Q QUARTER(S), D DIME(S),n NICKEL(S),P PENNY(S)
���Q��quarters��Ŀ��D��dimes��Ŀ��n��nickels��Ŀ����P��pennies��Ŀ��

��������

3
124
25
194

�������

1 4 QUARTER(S),2 DIME(S),0 NICKEL(S),4 PENNY(S)
2 1 QUARTER(S),0 DIME(S),0 NICKEL(S),0 PENNY(S)
3 7 QUARTER(S),1 DIME(S),1 NICKEL(S),4 PENNY(S)
*****/

#include <iostream>
using namespace std;

#define MAX_N 4
#define MAX_L 100
int value[MAX_N] = {25, 10, 5, 1};  // ������ֵ��С
char currency[MAX_N][MAX_L] = {     // ������ֵ��Ӧ����
    "QUARTER(S)", "DIME(S)", "NICKEL(S)", "PENNY(S)"
};

int main()
{
    int n = 0, change = 0, cnt = 0;
    cin >> n;
    for (int _case = 1; _case <= n; _case++)
    {
        cout << _case << " ";
        cin >> change;
        /** ����ֵ�Ӵ�С̰����Ǯ���� **/
        for (int v = 0; v < MAX_N; v++)
        {
            cnt = change / value[v];
            change = change % value[v];
            if (v > 0)
                cout << ",";
            cout << cnt << " " << currency[v];
        }
        cout << endl;
    }
    return 0;
}
