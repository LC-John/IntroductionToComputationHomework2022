/*****
��Ŀ����

����һ�����ӣ�һ�У����������е�ÿһ�����ʷ�ת�����

��������

ֻ��һ�У�Ϊһ���ַ�����������500���ַ�������֮���Կո������

�������

��תÿһ�����ʺ���ַ���

��������

hello world

�������

olleh dlrow

��ʾ��Ϣ

1. ÿ�����Ӷ�ֻ��һ�У���һ��ֻ�����ո����ĸ���ַ�����
2. �����뵥�ʼ�Ŀո���ܲ�ֻһ����
*****/

#include <cstdio>

#define MAX_LEN 1000
char w[MAX_LEN] = "";

bool is_delim(char c)
{
    return c == '\0' || c == ' ';
}

int main()
{
    scanf("%[^\n]", w); // ����һ���ַ���

    for (int _begin = 0, _end = 0; w[_end] != '\0'; _end++) // [_begin, _end)����Ϊһ�������ĵ��ʣ�����ҿ�
    {
        if (is_delim(w[_end]))  // ��_end�ǿո�
            printf(" ");        // ������ո�
        if (_end && is_delim(w[_end - 1]))  // ��_end��0��_end - 1�ǿո�
            _begin = _end;                  // �����_begin
        if (!is_delim(w[_end]) && is_delim(w[_end + 1]))    // ��_end���ǿո��_end + 1��
            for (int i = _end; i >= _begin; i--)            // ��˵���ҵ���һ�������ĵ���
                printf("%c", w[i]);                         // ��������õ���
    }
    printf("\n");
    return 0;
}
