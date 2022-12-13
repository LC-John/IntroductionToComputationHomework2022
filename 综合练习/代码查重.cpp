/*****
题目描述

五道口某职业学校开设了一门名为计算概论的课程。这门课程开设最初，老师、同学、助教相亲相爱，十分和谐。
直到有一天，一名丧心病狂的助教写了一个代码查重程序，之前的温馨和谐的关系开始崩坏。学生们甚至发生了暴
动，这个事件被后世成为T大计算机系灭门惨案。
十年过去了，为了研究T大计算机系灭门惨案的始末，P大的老师让同学们实现那名丧心病狂的助教写的伤害了无数
无辜同学的查重程序的简化版本。
输入两份代码，分别统计两份代码中的if，switch，while，for语句的数量，若两份代码中if和switch的数量之
和，与while、for之和分别都相等，则判定这两份代码有相互抄袭的嫌疑。【简直丧心病狂！

关于输入

第1行一个整数n，代表第一份代码的行数
随后从2到n+1行为第一份代码
第n+2行一个整数m，代表第二份代码的行数
随后从n+3到n+m+2行为第二份代码

关于输出

一行, 两份代码有相互抄袭的嫌疑, 输出Yes，否则输出No

例子输入

3
int main() {
  printf("Hello World!");
}
4
int main()
{
  printf("Hello World!");
}

例子输出

Yes

提示信息

We’ll be using a sophisticated cheat checker that compares handins between all students.
Please don’t copy another student’s code.
*****/

#include <cstring>
#include <iostream>
using namespace std;

void strip(char *s)
{
	int l = strlen(s);
	int idx = 0;
	for (int i = 0; i <= l; ++i)
		if (s[i] != ' ')
			s[idx++] = s[i];
}

void CNT(char *s, int &cnt1, int &cnt2)
{
	strip(s);
	int l = strlen(s);
	const char word[4][10] = { "if", "switch", "while", "for" };
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < 4; ++j) {
			char saved = s[i + strlen(word[j])];
			s[i + strlen(word[j])] = '\0';
			if (strcmp(word[j], s + i) == 0 && saved == '(') {
				if (i < 2)
					cnt1 += 1;
				else
					cnt2 += 1;
			}
			s[i + strlen(word[j])] = saved;
		}
	}
}

int main()
{
	char s[1010];
	int n1, n2, cnt11 = 0, cnt12 = 0, cnt21 = 0, cnt22 = 0;
	cin >> n1;
	cin.get();
	while (n1--) {
		cin.getline(s, 1000);
		CNT(s, cnt11, cnt12);
	}
	cin >> n2;
	cin.get();
	while (n2--) {
		cin.getline(s, 1000);
		CNT(s, cnt21, cnt22);
	}
	bool res = cnt11 == cnt21 && cnt12 == cnt22;
	cout << (res ? "Yes" : "No") << endl;
	return 0;
}
