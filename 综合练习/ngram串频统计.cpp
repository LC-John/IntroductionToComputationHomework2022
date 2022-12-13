/*****
描述
在文本分析中常用到n-gram串频统计方法，即，统计相邻的n 个单元（如单词、汉字、或者字符）
在整个文本中出现的频率。假设有一个字符串，请以字符为单位按n-gram 统计长度为n的子串出
现的频度，并输出最高频度以及频度最高的子串。设定所给的字符串不多于500个字符，且1<n<5。
如果有多个子串频度最高，则根据其在序列中第一次出现的次序输出多个，
每行输出一个，如果最高频度不大于1，则输出NO
例如，n=3，所给的串是：abcdefabcd，
则，所有的 3-gram是：abc,bcd,cde,def,efa,fab,abc,bcd。最后面的cd不足以形成3-gram，则
不考虑。这样，abc和bcd都出现了2次，其余的只出现了1次，于是，输出结果应该是：
2
abc
bcd
关于输入
第一行为n
第二行为字符串
关于输出
输出最高频度以及频度最高的所有子串。
例子输入
3
abcdefabcd
例子输出
2
abc
bcd
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10
#define MAX_L 510

char sub[MAX_L][MAX_N] = {'\0'};
int cnt[MAX_L] = {0};
char str[MAX_L] = "\0";

int main()
{
    int n_sub = 0;
    int n = 0, l =0;

    cin >> n_sub;
    cin.get();
    cin.getline(str, MAX_L);
    l = strlen(str);
    /* Count n-gram sub-sequences */
    strncpy(sub[n], str, n_sub);
    cnt[n++] = 1;
    for (int i = 1; i <= l - n_sub; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
            if (strncmp(sub[j], str + i, n_sub) == 0)
            {
                cnt[j]++;
                found = true;
                break;
            }
        if (!found)
        {
            strncpy(sub[n], str + i, n_sub);
            cnt[n++] = 1;
        }
    }
    /* Sort n-gram sub-sequences */
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (cnt[i] > cnt[j])
            {
                char tmp[MAX_N];
                strncpy(tmp, sub[i], n_sub);
                strncpy(sub[i], sub[j], n_sub);
                strncpy(sub[j], tmp, n_sub);
                cnt[i] = cnt[i] ^ cnt[j];
                cnt[j] = cnt[i] ^ cnt[j];
                cnt[i] = cnt[i] ^ cnt[j];
            }

    if (cnt[0] <= 1)
        cout << "NO";
    else
    {
        cout << cnt[0] << endl;
        for (int i = 0; i < n && cnt[i] == cnt[0]; i++)
            cout << sub[i] << endl;
    }
    return 0;
}
