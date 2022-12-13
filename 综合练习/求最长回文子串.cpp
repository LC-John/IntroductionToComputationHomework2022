/*****
题目描述

给定一个串S，长度小于等于100000，求S的最长回文子串的长度（回文串是指一个串正序和逆序相同）。

关于输入

给定的字符串S

关于输出

一个数，表示最长回文子串的长度

例子输入

aaabbac

例子输出

4

提示信息

暴力会超时，用分治吧
*****/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX_N 1001000

const int P = 131;
char str[MAX_N];
unsigned long long h1[MAX_N], h2[MAX_N], p[MAX_N];

unsigned long long hash1(int l, int r)
{
    return h1[r] - h1[l - 1] * p[r - l + 1];
}

unsigned long long hash2(int l, int r)
{
    return h2[l] - h2[r + 1] * p[r - l + 1];
}

int main()
{
    cin >> str + 1;
    int len = strlen(str + 1);

    h1[0] = 0;
    for(int i = 1; i <= len; i++)
        h1[i] = h1[i - 1] * P + (str[i] - 'a' + 1);
    h2[len + 1] = 0;
    for(int i = len; i >= 1; i--)
        h2[i] = h2[i + 1] * P + (str[i] - 'a' + 1);
    p[0] = 1;
	for(int i = 1;i < MAX_N; i++)
        p[i] = p[i - 1] * P;

    int ans = 0;
    for(int i = 1; i <= len; i++)
    {
        int l = 0, r = min(i - 1, len - i);
        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            if(hash1(i - mid, i - 1) == hash2(i + 1, i + mid))
                l = mid;
            else
                r = mid - 1;
        }
        ans=max(ans, l + l + 1);

        l = 0;
        r = min(i - 1, len - i + 1);
        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            if(hash1(i - mid, i - 1) == hash2(i, i + mid - 1))
                l = mid;
            else r = mid - 1;
        }
        ans = max(ans, l + l);
    }
    cout << ans << endl;
	return 0;
}
