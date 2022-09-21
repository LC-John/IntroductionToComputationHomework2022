/*****
题目描述

a的立方=b的立方+c的立方+d的立方为完美立方等式。例如12的立方=6的立方+8的立方+10的立方。
编写一个程序，对任给的正整数N (N≤100)，寻找所有的四元组(a, b, c, d)，使得
a的立方=b的立方+c的立方+d的立方，其中a,b,c,d 大于 1, 小于等于N。

关于输入

正整数N (N≤100)

关于输出

每行输出一个完美立方，按照a的值，从小到大依次输出。当两个完美立方等式中a的值相同，则依
次按照b、c、d进行非降升序排列输出，即b值小的先输出、然后c值小的先输出、然后d值小的先输
出。

例子输入

24

例子输出

Cube = 6, Triple = (3,4,5)
Cube = 12, Triple = (6,8,10)
Cube = 18, Triple = (2,12,16)
Cube = 18, Triple = (9,12,15)
Cube = 19, Triple = (3,10,18)
Cube = 20, Triple = (7,14,17)
Cube = 24, Triple = (12,16,20)

提示信息

注意输出的格式应和例子输出一致
*****/

#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    for (int a = 2; a <= n; a++)
    {
        int a3 = a * a * a;
        for (int b = 2; b < a; b++)
        {
            int b3 = b * b * b;
            for (int c = b; c < a; c++)
            {
                int sum_bc = b3 + c * c * c;
                for (int d = c; d < a; d++)
                {
                    int sum = sum_bc + d * d * d;
                    if (a3 == sum)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    else if (a3 < sum)
                        break;
                }

            }

        }

    }

    return 0;
}
