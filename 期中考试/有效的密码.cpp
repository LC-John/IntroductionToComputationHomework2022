/*****
题目描述

由于北大未名BBS比较知名，容易引来黑客攻击。因此，对每个人的账户而言，
密码越复杂，被黑客破解的可能性就越低。通常而言，密码至少由不少于六个
字符组成，由以下规则判定密码是否安全：
1. 如果密码长度小于6位，则不安全
2. 如果组成密码的字符只有一类，则不安全
3. 如果组成密码的字符有两类，则为中度安全
4. 如果组成密码的字符有三类或以上，则为安全
通常，把数字、大写字母、小写字母和其它符号归为四类不同的字符。

关于输入

输入的第一行是一个整数n，表明后面有n组密码输入。随后的n行每行代表一
个密码，每个密码的长度均小于50个字符（不含空格）。

关于输出

针对每一个密码判断并输出它是否安全。对于不安全的密码输出"Not safe"，
对于中度安全的密码输出"Medium safe"，对于安全的密码输出"Safe"

例子输入

5
1234
abcdefg
123safe
432*fe+93
AD7doiuo31

例子输出

Not safe
Not safe
Medium safe
Safe
Safe
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 100

enum CharType
{
    NUMBER = 0,
    LOWER,
    UPPER,
    OTHER,
    CHAR_TYPE_COUNT
};

enum SafeLevel
{
    NOT_SAFE,
    MEDIUM_SAFE,
    SAFE
};

CharType getCharType(char c)
{
    if (c >= '0' && c <= '9')
        return NUMBER;
    if (c >= 'a' && c <= 'z')
        return LOWER;
    if (c >= 'A' && c <= 'Z')
        return UPPER;
    return OTHER;
}

SafeLevel getSafeLevel(char* str)
{
    bool type[CHAR_TYPE_COUNT] = {false};
    int cnt = 0, l = 0;
    for (l = 0; str[l] != '\0'; l++)
        type[getCharType(str[l])] = true;
    if (l < 6)
        return NOT_SAFE;
    for (int i = 0; i < CHAR_TYPE_COUNT; i++)
        if (type[i])
            cnt++;
    switch(cnt)
    {
    case 1: return NOT_SAFE;
    case 2: return MEDIUM_SAFE;
    default: return SAFE;
    }
}

int main()
{
    int n = 0;
    char password[MAX_LEN] = "";
    cin >> n;
    while(n--)
    {
        cin >> password;
        switch(getSafeLevel(password))
        {
        case NOT_SAFE:
            cout << "Not safe" << endl;
            break;
        case MEDIUM_SAFE:
            cout << "Medium safe" << endl;
            break;
        case SAFE:
            cout << "Safe" << endl;
            break;
        default: break;
        }
    }
    return 0;
}
