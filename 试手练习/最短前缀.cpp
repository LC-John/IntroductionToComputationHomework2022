/*****
��Ŀ����

һ���ַ�����ǰ׺�ǴӸ��ַ����ĵ�һ���ַ���ʼ��һ���Ӵ������� "carbon"���ִ���: "c", "ca", "car", "carb", "carbo",
�� "carbon"��ע�⵽�������ǲ���Ϊ�մ����ִ�, ����ÿ���ǿմ�����������ִ�. ��������ϣ������ǰ׺�����Եı�ʾ���ʡ�
����, "carbohydrate" ͨ����"carb"�����Ա�ʾ. ���ڸ���һ�鵥��, Ҫ�����ҵ�Ψһ��ʶÿ�����ʵ����ǰ׺
������������У�"carbohydrate" �ܱ����Գ�"carboh", ���ǲ��ܱ����Գ�"carbo" (��������̵�ǰ׺) ��Ϊ�Ѿ���һ������
��"carbo"��ʼ
һ����ȷƥ��Ḳ��һ��ǰ׺ƥ�䣬���磬ǰ׺"car"��ȷƥ�䵥��"car". ��� "car" �� "car"����������û�ж����Ե�,��car��
���ᱻ����"carriage"�����κ����б�����"car"��ʼ�ĵ���.

��������

�����������2�У�����1000��. ÿ�а���һ����Сд��ĸ��ɵĵ��ʣ����ʳ���������1��������20.

�������

����������������������ͬ��ÿ���������Ӧ������ĵ��ʿ�ʼ���������һ���ո����������Ӧ���ʵ�û�ж����Ե����ǰ׺
��ʶ����

��������

carbohydrate
cart
carburetor
caramel
caribou
carbonic
cartilage
carbon
carriage
carton
car
carbonate

�������

carbohydrate carboh
cart cart
carburetor carbu
caramel cara
caribou cari
carbonic carboni
cartilage carti
carbon carbon
carriage carr
carton carto
car car
carbonate carbona
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_L 30
#define MAX_N 1010

char str[MAX_N][MAX_L + MAX_L], pre[MAX_L];
int n = 0;

/* Check whether s is a prefix of any string in str,
    besides str[index] */
bool in(char *s, int index)
{
    for (int i = 0; i < n; i++)
    {
        if (i == index)
            continue;
        if (strstr(str[i], s) == str[i])
            return true;
    }
    return false;
}

int main()
{
    while (cin >> str[n++]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(str[i]); j++)
        {
            memset(pre, 0, sizeof(pre));
            strncpy(pre, str[i], j+1);
            if (strcmp(pre, str[i]) == 0 || !in(pre, i))
            {
                strcat(str[i], " ");
                strcat(str[i], pre);
                break;
            }
        }
        cout << str[i] << endl;
    }
    return 0;
}
