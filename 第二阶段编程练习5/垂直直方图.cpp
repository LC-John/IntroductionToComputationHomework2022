/*****
��Ŀ����

����4��ȫ���ɴ�д��ĸ��ɵ��ı������һ����ֱֱ��ͼ������ÿ���ַ����ֵĴ�����
ע�⣺ֻ������ַ��ĳ��ִ�������������հ��ַ������ֻ��߱����ŵ����������

��������

���룺����4���ɴ�д��ĸ��ɵ��ı���ÿ�����ַ�����Ŀ������80����

�������

��������������С��������һ�и���26����дӢ����ĸ����Щ��ĸ֮���ÿո������
ǰ��ļ��а����ո���Ǻţ�ÿ����ĸ���ּ��Σ����������ĸ���Ϸ����һ���Ǻš�
ע�⣺����ĵ�һ�в����ǿ��С�ÿ�е�ĩβ�����пո�ÿ����#��ʼ

��������

THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!

�������

#                             *
#                             *
#         *                   *
#         *                   *     *   *
#         *                   *     *   *
# *       *     *             *     *   *
# *       *     * *     * *   *     * * *
# *       *   * * *     * *   * *   * * * *
# *     * * * * * *     * * * * *   * * * *     * *
# * * * * * * * * * * * * * * * * * * * * * * * * * *
# A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 100
#define N_CHAR 300
#define BAR '#'
#define PAD ' '
#define HIST '*'

char str[MAX_LEN] = "";
int cnt[N_CHAR] = {0};

int main()
{
    int max_cnt = 0, n_pad = 0;
    while (cin >> str)
    {
        for (int i = 0; str[i] != '\0'; i++)
            if (max_cnt < ++cnt[str[i]])
                max_cnt = cnt[str[i]];
    }
    for (int i = max_cnt - 1; i >= 0; i--)
    {
        n_pad = 0;
        cout << BAR;
        for (char c = 'A'; c <= 'Z'; c++)
            if (cnt[c] > i)
            {
                for (int j = 0; j < n_pad; j++)
                    cout << " " << PAD;
                cout << " " << HIST;
                n_pad = 0;
            }
            else
                n_pad++;
        cout << endl;
    }
    cout << BAR;
    for (char c = 'A'; c <= 'Z'; c++)
        cout << " " << c;
    cout << endl;
    return 0;
}
