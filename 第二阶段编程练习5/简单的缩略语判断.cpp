/*****
��Ŀ����

�������Զ�������������纺���ϵġ��ǵ䣨�ǵ����Է��ף����������󣨱�����ѧ������Ӣ���ϵ�
��SARS(Severe Atypical Respiratory Syndrome)�����ٶ�ĳ���ַ���A�е�ÿ���ַ���������һ��
�ַ���S�в�ͬ��λ�ã���Сд��ȫ��ͬ�������ַ��� A ���ַ���ǰ���ϵ�� S �в������ı䣬ͬʱ��
A�ĳ���С��S�ĳ��ȣ�����Ϊ A �� S ��һ�������������������������Դ������ж�ǰ��Ĵ��Ƿ�
�Ǻ��洮�Ŀ�����������ǣ������ YES��������� NO

��������

��1��Ϊ������Ŀn��
���� n ���У�ÿ����һ���ַ����������ð�ż�����ж���ߵĴ��Ƿ����ұߴ����ܵ���������ٶ�
��ߴ��ĳ��Ȳ�����30���ַ����ұߴ��ĳ��Ȳ�����300���ַ���

�������

����n�ԣ����� n �������ÿ�ж�Ӧ�жϵĽ�������ǿ��ܵ���������YES��������� NO

��������

6
AB:ACDEbFBkBD
AR:ACDBrT
SARS:Severe Atypical Respiratory Syndrome
ACDEFBD:AB
ABD:ACDEDkBY
ABBR:ACDEDkBRT

�������

YES
NO
YES
NO
NO
NO
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 1000

char abbr[MAX_LEN] = "", str[MAX_LEN] = "";

int main()
{
    int n = 0;
    int abbr_idx = 0, str_idx = 0;
    cin >> n;
    cin.get();      // �������뻺�����е�'\n'����ֹӰ��cin.getline��������
    while (n--)
    {
        abbr_idx = 0;
        str_idx = 0;
        cin.getline(abbr, MAX_LEN, ':');    // ����abbr��ֱ�����ȴﵽMAX_LEN���޻�������','��ֹ
        cin.getline(str, MAX_LEN, '\n');    // ͬ�ϣ�����str

        /** �������������abbr�ĳ��Ȳ�����str **/
        if (strlen(abbr) >= strlen(str))
        {
            cout << "NO" << endl;
            continue;
        }

        /** ����abbr��str **/
        while(abbr[abbr_idx] != '\0' && str[str_idx] != '\0')
        {
            if (abbr[abbr_idx] == str[str_idx]) // ��abbr���ַ���str���ַ�һ��
                abbr_idx++;                     // ��abbr_idx�����ƶ�һλ
            str_idx++;                          // ������Σ�str_idx�����ƶ�һλ
        }

        /** ��� **/
        if (abbr[abbr_idx] != '\0')     // abbr_idxָ���ַ���Ϊ'\0'
            cout << "NO" << endl;       // ��˵��abbrû����str��ȫƥ��
        else                            // ����
            cout << "YES" << endl;      // abbr��str��ȫƥ��
    }
    return 0;
}
