/*****
��Ŀ����

��׺���ʽ��ָ������һ�����ʽ��ʽ�в�ʹ�����ţ�������ŷ��������������֮��
���м��㰴������ų��ֵ�˳���ϸ����������½��У����ÿ�������������ȼ���
�磺3*(5-2)+7��Ӧ�ĺ�׺���ʽΪ��3 5 2 - *  7 + @����@��Ϊ���ʽ�Ľ������š�
ע�⣬�����������ʹ�����ͽ������㡣

��������

���У�ÿ��һ���ÿո�ָ�ĺ�׺���ʽ����֤���ʽ���Ȳ�����1000���ַ���

�������

������У�Ϊ��Ӧ���ʽ��ֵ��
�������������г��ֳ�0�������NaN��

��������

3 5 2 - *  7 + @

�������

16
*****/

#include <cstdio>
#include <cstring>
#define MAX_LEN 1010


char buf[MAX_LEN] = "\0";           // ��ǰ��������ֻ����
long long _stack[MAX_LEN] = {0};    // ��ǰ���������δ������������
int l = 0;                          // _stack�����ֵĸ���
/** ÿ����������������ȡ��_stack������������ֽ��и����㣬�����������_stackĩβ **/

/** Debug **/
void print()
{
    for (int i = 0; i < l; i++)
        printf("%ld ", _stack[i]);
    printf("\t%s\n", buf);
}

int main()
{
    bool nan = false;   // ��¼�Ƿ����NaN
    while (scanf("%s", buf) != EOF)
    {
        if (buf[0] != '@' && nan)   // ���Ѿ�NaN�����������в������������������
            continue;
        switch (buf[0])     // ����ݲ�������ִ�в�ͬ�Ĳ���
        {
        case '@':                           // �������
            if (nan)                        // �Ѿ�NaN
                printf("NaN\n");            // �����NaN
            else if (l == 1)                // ����Ӧ���������㶼��������ʱ_stack��Ӧ��ֻ��һ����
                printf("%ld\n", _stack[0]); // ���ǣ������_stack�еĸ���
            else                            // ����˵������������������
                printf("Error\n");          // ���Error
            /** ��ʼ�� **/
            memset(_stack, 0x00, sizeof(_stack));
            l = 0;
            nan = false;
            break;
        case '+': _stack[l - 2] = _stack[l - 2] +  _stack[l - 1]; l--; break;   // �ӷ�����
        case '-': _stack[l - 2] = _stack[l - 2] -  _stack[l - 1]; l--; break;   // ��������
        case '*': _stack[l - 2] = _stack[l - 2] *  _stack[l - 1]; l--; break;   // �˷�����
        case '/':               // ��������
            if (!_stack[l - 1]) // ����������Ϊ��
                nan = true;     // �������NaN
            else
            {
                _stack[l - 2] = _stack[l - 2] /  _stack[l - 1];
                l--;
            }
            break;
        default:                            // �����������
            sscanf(buf, "%ld", &_stack[l]); // �������_stackĩβ�ȴ�����
            l++;
        }
        //print();
    }
    return 0;
}
