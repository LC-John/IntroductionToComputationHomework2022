/*****
��Ŀ����

�ڲ�ͬ�Ĺ��Һ͵�����ʱ���ʾ����������ͬ������ͬ��2006��5��1�գ����Ա�ʾΪ2006-May-01��May-01-2006��01-May-2006�ȵȡ�
�ּٶ���ʹ������ yyyy ���ĸ����ֱ�ʾ����ʹ������ Mmm ��Ӣ���·ݼ�д��ʾ����ʹ������ dd ���������ֱ�ʾ������֮��ʹ�÷���
- �� / �ָ��������ǵ��������г��ֵ�ǰ��˳�򲻶�����дһ�����򣬶��������㱾��Լ���������ַ�����������������ڼ���

��������

�����ж��У���һ����һ������n����ʾ�ж��ٸ�������������ַ�����
������n�������ַ�����ÿ��һ����
���ڷ�Χ��1900��1��1����2099��12��31�ա�

�������

�����n�У������Ӧ���ڵ����ڵ�Ӣ����д����дǰ��Ӧ�пհ��ַ��������ַ���

��������

3
2006-Jun-07
May-01-2006
2006-01-Sep

�������

Wed.
Mon.
Fri.
��ʾ��Ϣ

���ڵ�Ӣ����д��
Sun Mon Tue Wed Thu Fri Sat
�·ݵ�Ӣ����д��
Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
1900��1��1��������һ�����Դ�Ϊ��׼���ڡ�
ע���������⣬�����ж�����Ϊ����ܱ�4���������ܱ�100���������ܱ�400������
����ԭ��򵥣������̽ϸ��ӣ���Ҫͨ���ṹ���������˼�룬���ò�ͬ�ĺ�������ͬ�Ĳ��裬ʵ�ֲ�ͬ�Ĺ��ܡ�
*****/

#include <cstdio>
#include <cstring>

#define MAX_LEN 100
#define N_MONTH 12
#define N_WEEK 7


char str[MAX_LEN] = "\0";

const int month_day[2][N_MONTH + 1] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
const int year_day[2] = {365, 366};
const char month_abbr[N_MONTH + 1][MAX_LEN] = {
    "\0", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
const char week_abbr[N_WEEK][MAX_LEN] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

/** ������str���ַ�������Ϊ������ **/
void parse_date(int* y, int* m, int* d) // ͨ�������д����ָ�룬���ض����ֵ
{
    char buffer[MAX_LEN] = "\0";
    for(int _begin = 0, _end = 0; true; _end++) // _begin��_end��Ӧ�ַ�������ֱ�Ӷ�ȡ��Ƭ�Σ������ꡢ�»��գ�����������ҿ�
    {
        if (str[_end] == '-' || str[_end] == '/' || str[_end] == '\0')  // ��_end����'-'��'/'��'\0'ʱ
        {                                                               // ˵����ǰ��ֱ�Ӷ�ȡ��Ƭ���Ѿ���ֹ��������һ���µ�Ƭ��
            memset(buffer, '\0', sizeof(char) * MAX_LEN);
            strncpy(buffer, str + _begin, _end - _begin);   // ����ǰƬ�ε��ַ���������buffer��
            switch(_end - _begin)           // ���Ƭ�γ���
            {
            case 4:                         // Ƭ�γ���Ϊ4
                sscanf(buffer, "%d", y);    // ��˵����Ƭ�ζ�Ӧ������ݣ���buffer�е�����д�뵽yָ����
                break;
            case 3:                                     // Ƭ�γ���Ϊ3
                for (int i = 1; i <= N_MONTH; i++)      // ��˵����Ƭ�ζ�Ӧ�����·�
                    if (!strcmp(buffer, month_abbr[i])) // ��������·���д
                    {
                        *m = i;                         // ����ȷ���·�д��mָ����
                        break;
                    }
                break;
            case 2:                         // Ƭ�γ���Ϊ2
                sscanf(buffer, "%d", d);    // ��˵����Ƭ�ζ�Ӧ�������ڣ���buffer�е�����д�뵽dָ����
                break;
            default: break;
            }
            if (str[_end] == '\0')  // ����ʱ_end��'\0'
                return;             // ��˵���ַ����Ѿ�������ϣ���������
            _begin = _end + 1;      // �Ѿ���ɵ�ǰƬ�εĴ���_end������һ���µ�Ƭ�Σ�����_beginΪ_end+1
        }
    }
}

/** ������� **/
int is_leap(int y)
{
    if (((y % 100) && !(y % 4)) || !(y % 400))
        return 1;
    return 0;
}

/** �������� **/
int get_week(int year, int month, int day)
{
    int ret = 0, leap = is_leap(year);
    for (int y = 1900; y < year; y++)   // ��1900���𣬵�yearΪֹ������year���꣩
        ret += year_day[is_leap(y)];    // ����ȥ�˶�����
    for (int m = 1; m < month; m++)     // year�����У���monthΪֹ������month���£�
        ret += month_day[leap][m];      // ����ȥ�˶�����
    ret += day;     // year���꣬month���£���day����ȥ�˶�����
                    // ע������ȥ�����컹��Ҫ��1����Ϊ�˼���������Ҫ����1900��1��1�յ�����һ������һ��
                    // һ��һ������������˿��Բ�������
    return ret % N_WEEK;
}

int main()
{
    int n = 0;
    int year = 0, month = 0, day = 0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", str);
        parse_date(&year, &month, &day);    // &��ʾȡyear��month��day���ڴ��ַ���൱��ָ�룩
        printf("%s.\n", week_abbr[get_week(year, month, day)]);
    }
    return 0;
}
