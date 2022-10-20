/*****
��Ŀ����

��һ��N x N��NΪ��������1<=N<=10���ľ��󣬾����е�Ԫ�ض����ַ������������ܻᰴ�����µļ��ֱ�÷���֮һ���б�ã�ֻ����һ�Σ���
���ڸ���һ��ԭʼ�ľ��󣬺�һ����ú�ľ������дһ���������ж�ԭʼ�����ǰ�����һ�ַ�����ΪĿ�����ġ�
1. ����˳ʱ�뷽����ת90�ȣ�
�磺
1 2 3          7 4 1
4 5 6  ���Ϊ  8 5 2
7 8 9          9 6 3
2. ������ʱ�뷽����ת90�ȣ�
�磺
1 2 3         3 6 9
4 5 6  ���Ϊ  2 5 8
7 8 9          1 4 7
3. ����Ԫ�ز��䣨�������е� 5��������Ԫ�أ��������е�3���롰������Ԫ��Ϊ���ĵĶ�ӦԪ�ء����������е�7��������
�磺
1 2 3         9 8 7
4 5 6  ���Ϊ  6 5 4
7 8 9          3 2 1
4. ����ԭʼ���󣬲���ã�
5. ��� ��ԭʼ���� �� Ŀ����� �ı�ã��������κ�������ã������5

��������

��һ�У�����ÿ��/��Ԫ�صĸ��� N��
�ڶ��е���N+1�У�ԭʼ���󣬹�N�У�ÿ��N���ַ���
��N+2�е���2*N+1�У�Ŀ����󣬹�N�У�ÿ��N���ַ���

�������

ֻ��һ�У���ԭʼ���� �� Ŀ����� ������ȡ�� ��÷���ı�š�

��������

5
a b c d e
f g h i j
k l m n o
p q r s t
u v w x y
y x w v u
t s r q p
o n m l k
j i h g f
e d c b a

�������

3
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

char arr[2][MAX_N][MAX_N] = {""};
char tgt[MAX_N][MAX_N] = {""};
int n = 0;

/** �������arr[cur]��������debug **/
void print(int cur)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[cur][i][j] << " ";
        cout << endl;
    }
}

/** �ȶ�arr[cur]��tgt�Ƿ�һ�� **/
bool cmp(int cur)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[cur][i][j] != tgt[i][j])
                return false;
    return true;
}

/** ��arr[cur]˳ʱ��ת90�ȣ����������arr[nxt]�У�����nxt **/
int rotate90_clockwise(int cur)
{
    int nxt = 1 - cur;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[nxt][j][n - 1 - i] = arr[cur][i][j];
    return nxt;
}

/** ��arr[cur]���ĶԳƣ����������arr[nxt]�У�����nxt **/
int centrosymmetrize(int cur)
{
    int nxt = 1 - cur;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[nxt][n - 1 - i][n - 1 - j] = arr[cur][i][j];
    return nxt;
}

int main()
{
    int cur = 0;

    /** �������� **/
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[cur][i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> tgt[i][j];

    /** ����4�����ֲ��� **/
    if (cmp(cur))
    {
        cout << 4 << endl;
        return 0;
    }

    /** ����3�����ĶԳ� **/
    cur = centrosymmetrize(cur);
    if (cmp(cur))
    {
        cout << 3 << endl;
        return 0;
    }
    cur = centrosymmetrize(cur);    // ����ԭ

    /** ����1��˳ʱ����ת90�� **/
    cur = rotate90_clockwise(cur);
    if (cmp(cur))
    {
        cout << 1 << endl;
        return 0;
    }

    /** ����2����ʱ����ת90�� **/
    cur = rotate90_clockwise(cur);  // ��˳ʱ����ת90�ȵĻ���֮�ϣ�����ת����
    cur = rotate90_clockwise(cur);  // ��ͬ����ʱ����ת90��
    if (cmp(cur))
    {
        cout << 2 << endl;
        return 0;
    }

    /** ����5������ **/
    cout << 5 << endl;
    return 0;
}
