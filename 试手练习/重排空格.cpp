/*****
��Ŀ����

����һ���ַ��� text�����ַ��������ɱ��ո��Χ�ĵ�����ɡ�ÿ��������һ�����߶��С
дӢ����ĸ��ɣ�������������֮�����ٴ���һ���ո�
�����������пո�ʹÿ�����ڵ���֮��Ŀո���Ŀ����ȣ�����������󻯸���Ŀ�������
������ƽ���������пո��뽫����Ŀո�������ַ���ĩβ����Ҳ��ζ��������ַ���Ӧ��
��ԭ�ַ����ĳ�����ȡ�

��������

һ����СдӢ����ĸ�Ϳո���ɵ��ַ�����
�ַ������Ȳ�����1000�����ٰ���һ�����ʡ�

�������

һ�к�ԭ�ַ���������ȵ��ַ�����

��������

  this   is  a sentence

�������

this   is   a   sentence
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 1010
char str[MAX_LEN] = "\0";

int main()
{
    int cnt = 0, len = 0, ws = 0, pad = 0;
    bool flag = false;

    cin.getline(str, MAX_LEN);
    len = strlen(str);

    for (int i = 0; i < len; i++)
        if (str[i] == ' ')
        {
            str[i] = '\0';
            ws++;
        }
        else if ((!i) || str[i - 1] == '\0')
            cnt++;

    if (cnt == 1)
    {
        pad = ws;
        ws = 0;
    }
    else
    {
        pad = ws % (cnt - 1);
        ws /= (cnt - 1);
    }

    for (int i = 0; i < len; i++)
        if (str[i] && ((!i) || (!str[i - 1])))
        {
            if (flag)
                for (int j = 0; j < ws; j++)
                    cout << " ";
            else
                flag = true;
            cout << str + i;
        }
    for (int j = 0; j < pad; j++)
        cout << " ";
    cout << endl;
    return 0;
}
