/*****
��Ŀ����

�������ĩ�������Ͼ�Ҫ��ʼ��, ������û���㹻�����������μ�, Ϊ�˰�������,����С����
��׼��һ̨������û�����ʼ��ʱ�����������ֵ��0, ������û���������ť:
1��N��ť: �������ӵ�е�����ֵΪx, ����֮������ֵ����Ϊ2*x+1��
2��G��ť: �����ǰӵ�е�����ֵΪx, ����֮������ֵ����Ϊ2*x+2��
����ֵ����Ҳ������,����������Ҫ���Լ�������ֵǡ�ñ�Ϊn, ������������һ��������û���
��������ʹ�椵�����ֵǡ�ñ�Ϊn��

��������

�������һ��, ����һ��������n(1 <= n <= 100000), ��ʾ���������Ҫ������ֵ��

�������

���һ���ַ���, ÿ���ַ���ʾ�ô�����ѡ�񰴶��İ�ť,'N'��ʾ�ôΰ���N��ť,'G'��ʾ�ôΰ�
��G��ť��

��������

20

�������

NGNG
*****/

#include <iostream>
using namespace std;

#define MAX_N 100000

char action[MAX_N] = "";    // �������Ķ�������

/** ����������� **/
bool brave_machine(int depth, int target, int current)  // depthΪ��ǰ������ȣ�targetΪĿ������ֵ��currentΪ��ǰ����ֵ
{
    /** ���ȿ��ǵݹ���ֹ����� **/
    if (current == target)  // ��current����target��˵��������ɣ��ҵ���Ҫ�Ķ�������
        return true;        // �ݹ���ֹ������true
    if (current > target)   // ��current����target��˵����ǰ���������Ѿ�����Ŀ��ֵ��������ǰ��������
        return false;       // �ݹ���ֹ������false

    /** ����������� **/
    action[depth] = 'N';    // ��depth��������Ϊ'N'�����������������Ƿ����
    if (brave_machine(depth + 1, target, current * 2 + 1))  // ���ݹ鷵��Ϊtrue��˵���ö�������
        return true;                                        // ֱ��return����������
    action[depth] = 'G';    // ��depth����������'N'������'G'����������
    if (brave_machine(depth + 1, target, current * 2 + 2))  // ͬ�ϣ�������true��˵����������
        return true;                                        // return��������
    action[depth] = '\0';   // ��depth������������'N'��'G'��˵��ǰ�������󣬻ָ�depth����Ϊ��ʼ����'\0'
    return false;           // ����false
}

int main()
{
    int target = 0;
    cin >> target;
    brave_machine(0, target, 0);    // DFS�ݹ�
    cout << action << endl;
    return 0;
}
