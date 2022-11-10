/*****
��Ŀ����

������������S��һ��Ŀ����T���ж��Ƿ���Դ�S����ѡһ���ǿ��Ӽ����Ӽ��е�����˵ĳ˻�ΪT��

��������

����Ϊ���С�
��һ��ΪĿ����T��S�е�Ԫ�ظ���N���Կո������
�ڶ���ΪS�е�N��Ԫ�أ��Կո������
���� N <= 16��

�������

������ԣ������YES���������NO��

��������

Sample Input 1:
12 5
1 2 3 4 5

Sample Input 2:
33 5
4 2 8 7 5

�������

Sample Output 1:
YES

Sample Output 2:
NO
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

int s[MAX_N] = {}, n = 0;

/** ����������� **/
bool dfs(int t, int depth)  // tΪĿ��˻���depthΪ�������
{
    if (t == 1)         // tΪ1��˵��Ŀ���Ѿ����
        return true;    // ����true
    if (depth >= n)     // depth����n��˵��Ŀ���޷����
        return false;   // ����false
    if (dfs(t, depth + 1))  // ����s[depth]�����Ŀ��
        return true;
    if (s[depth] && !(t % s[depth]) && dfs(t / s[depth], depth + 1))    // ��s[depth]�����Ŀ�꣬��Ҫ����0�����
        return true;
    return false;
}

int main()
{
    int t = 0;
    cin >> t >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    if (dfs(t, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
