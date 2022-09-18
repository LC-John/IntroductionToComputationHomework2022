/*****
��Ŀ����

����n����������������ͣ���Լ��֮��������ʽ��ʾ��
���磺
q/p = x1/y1  + x2/y2 +....+ xn/yn��
q/pҪ���ǹ�Լ֮�����ʽ��
�磺5/6�Ѿ��������ʽ��3/6��Ҫ��ԼΪ1/2, 3/1��Ҫ��Լ��3��10/3���������ʽ��
PS:���Ӻͷ�ĸ��û��Ϊ0�������Ҳû�г��ָ��������

��������

��һ�е�����n,����һ���м���������Ҫ���
��������n���Ƿ���

�������

���ֻ��һ�У�����Լ��Ľ��

��������

2
1/2
1/3

�������

5/6
*****/

#include <cstdio>

int swp(unsigned int &a, unsigned int &b)
{
    if (a < b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return 0;
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    unsigned int r = 0;
    swp(a, b);
    while (a % b)
    {
        r = a % b;
        a = b;
        b = r;
        swp(a, b);
    }
    return b;
}

int main()
{
    int n = 0;
    unsigned int a = 0, b = 0;
    unsigned int numerator = 0, denominator = 0;

    scanf("%d", &n);
    while(n--)
    {
        unsigned int tmp = 0;
        scanf("%u/%u", &a, &b);
        /* Simplify the input fraction */
        tmp = gcd(a, b);
        a /= tmp;
        b /= tmp;
        /* Initialize numerator and denominator */
        if ((!numerator) && (!denominator))
        {
            numerator = a;
            denominator = b;
            continue;
        }
        /* Add the simplified fraction to the final fraction */
        tmp = b * (denominator / gcd(b, denominator));
        numerator = a * (tmp / b) + numerator * (tmp / denominator);
        denominator = tmp;
        /* Simplify the final fraction */
        tmp = gcd(numerator, denominator);
        numerator /= tmp;
        denominator /= tmp;
    }

    if (denominator == 1)
        printf("%u\n", numerator);
    else
        printf("%u/%u\n", numerator, denominator);

    return 0;
}
