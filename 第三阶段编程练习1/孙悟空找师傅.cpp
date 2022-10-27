/*****
��Ŀ����

����ʦ�֣�ʦ���ֱ�����ץ���ˣ�����ɳʦ��˵����������������Ϣ��������ǰȥ��ʦ�������ǵ�����������ֶ���ʱ��
�������ָ��Լ�����һ����ֻ�гɹ��ƽ��������ղ��ܾȳ�ʦ�����������ж����ܷ�ȳ�ʦ����

��������

�����һ������������m��n����ʾ����Ϊm*n��С��0 < m,n <= 50��mΪ�У�nΪ�У�����������һ��m*n�ľ����ʾ���
������0Ϊ�����п��ߵ�·��1Ϊǽ���������ߵ�λ�ã���2Ϊ��յ�λ�ã�3Ϊʦ����λ�á����ֻ���ĸ����е����߷�
�򣺼����ϡ��¡����ң�����б�Խ��ߴ�Խ��ÿ�����������֮�䶼�ǿո�����

�������

���ֻ��һ�У�"Yes"��"No"��ʾ����Ƿ���Գɹ��ȳ�ʦ����������ߵ�ʦ����λ�ü��ɾȳ�ʦ������

��������

8 7
1 1 1 1 1 1 3
1 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 0 0 1 1 1
1 1 1 0 0 0 1
1 0 0 0 1 0 1
1 0 1 1 1 0 1
2 0 1 1 1 0 0

�������

Yes
*****/

#include <iostream>
using namespace std;

#define MAX_N 100
#define EMPTY 0
#define WALL 1
#define WUKONG 2
#define SIFU 3
#define DIR_N 4

int arr[MAX_N][MAX_N] = {0};
int n = 0, m = 0;
int dr[DIR_N] = {0, 0, 1, -1};
int dc[DIR_N] = {1, -1, 0, 0};

void print()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout <<endl;
}

/** �������飬������EMPTY����SIFU���ΪWUKONG **/
void traverse(int r, int c, int step)
{
    // print();
    if ((arr[r][c] == WUKONG && step) || arr[r][c] == WALL) // ײǽ���߻ص��߹��ĵط�
        return;                                             // ��ֹ
    arr[r][c] = WUKONG;                             // ��ǵ�ǰλ��ΪWUKONG����ʾ�Ѿ��߹���
    for (int d = 0; d < DIR_N; d++)                 // ���ĸ�����
        traverse(r + dr[d], c + dc[d], step + 1);   // �ݹ����
}

int main()
{
    int st_r = 0, st_c = 0;
    int end_r = 0, end_c = 0;

    /** �������� **/
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == WUKONG)
            {
                st_r = i;
                st_c = j;
            }
            if (arr[i][j] == SIFU)
            {
                end_r = i;
                end_c = j;
            }
        }

    /** ���Թ���������һȦWALL **/
    for (int i = 1; i <= m; i++)
        arr[i][0] = arr[i][n + 1] = WALL;
    for (int j = 1; j <= n; j++)
        arr[0][j] = arr[m + 1][j] = WALL;

    /** ��WUKONG��ʼ������������Թ� **/
    traverse(st_r, st_c, 0);

    /** ���SIFUλ���Ƿ񱻱��ΪWUKONG **/
    if (arr[end_r][end_c] ==  WUKONG)   // �������
        cout << "Yes" << endl;          // ��˵�������ҵ�
    else                                // ����
        cout << "No" << endl;           // ˵���Ҳ���
    return 0;
}
