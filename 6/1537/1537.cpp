#include <stdio.h>
#include <string.h>
#define NO printf("illegal.\n")
#define YES printf("legal.\n")

int xiaoshu(char s[])
{
int i , L , tot , j , b;

	tot = 0; L = strlen(s);
	for (i = 0; i < L; i ++) if (s[i] == '.') {j = i; tot ++;}
	if (tot > 1) return 0;  //多于一个小数点
	else if ((j == 0) || (j == L-1)) return 0; //小数点在第一位或者最后一位
		else
		{
			tot = 0;
			for (i = 0; i < L; i ++) if ((s[i] == '+') || (s[i] == '-')) tot ++;
			if ((tot == 0) || ((tot == 1) && ((s[0] == '+') || (s[0] == '-'))))
			{
				if ((s[j-1] >= '0') && (s[j-1] <= '9') && (s[j+1] >= '0') && (s[j+1] <= '9')) return 1;
				else return 0; //小数点两边不是数字
			}
			else return 0; //符号有多个或者符号不在第一位
		}
}

int zhengshu(char s[])
{
int i , L , tot , b;

	L = strlen(s);
	tot = 0;
	for (i = 0; i < L; i ++) if ((s[i] == '+') || (s[i] == '-')) tot ++;
	if (tot > 1) return 0; //有多个符号
	else if ((s[0] != '+') && (s[0] != '-') && (tot == 1)) return 0;// 符号不在首位
		else if ((tot == 1) && (L == 1)) return 0;//只有一个符号,没有数字
			else return 1;
}

int main()
{
char s1[100] , s[100] , s2[100];
int i , L , j , b1 , b2 , tot , b;

	while (1)
	{
		gets(s1);
		if (s1[0] == '*') break;
		i = 0; L = 0; b1 = 0; b2 = 0;
		while (s1[i] > 0)
		{
			if (s1[i] != ' ') s[L ++] = s1[i];
			if (s1[i] == '.') b1 = 1;
			if ((s1[i] == 'E') || (s1[i] == 'e')) b2 = 1;
			i ++;
		}
		s[L] = 0;
		printf("%s is " , s);
		if ((b1 == 0) && (b2 == 0)) NO;
		else if ((b1 == 1) && (b2 == 0))
		{
			if (xiaoshu(s) == 1) YES; else NO;
		}
		else if ((b1 == 0) && (b2 == 1))
		{
			tot = 0;
			for (i = 0; i < L; i ++) if ((s[i] == 'e') || (s[i] == 'E')) {j = i; tot ++;}
			if (tot > 1) NO; // 有多个E
			else if ((j == 0) || (j == L-1)) NO; //E在首位或末尾
				else
				{
					for (i = 0; i < j; i ++) s1[i] = s[i];
					s1[i] = 0;
					for (i = j + 1; i < L; i ++) s2[i-j-1] = s[i];
					s2[i-j-1] = 0;
					if ((zhengshu(s1) == 1) && (zhengshu(s2) == 1)) YES;
					else NO;
				}
		}
		else
		{
			tot = 0;
			for (i = 0; i < L; i ++) if ((s[i] == 'e') || (s[i] == 'E')) {j = i; tot ++;}
			if (tot > 1) NO;
			else if ((j == 0) || (j == L-1)) NO; //E在首位或末尾
				else
				{
					for (i = 0; i < j; i ++) s1[i] = s[i];
					s1[i] = 0;
					for (i = j + 1; i < L; i ++) s2[i-j-1] = s[i];
					s2[i-j-1] = 0;
					tot = 0;
					for (i = 0; i < j; i ++) if (s[i] == '.') {tot = 1; break;}
					if ((tot == 1) && (xiaoshu(s1) == 1)) b = 1;
					else if ((tot == 0) && (zhengshu(s1) == 1)) b = 1;
						else b = 0;
					tot = 0;
					for (i = j + 1; i < L; i ++) if (s[i] == '.') {tot = 1; break;}
					if (tot == 1) b = 0;
					else if ((tot == 0) && (zhengshu(s2) == 1) && (b == 1)) b = 1;
						else b = 0;
					if (b) YES; else NO;
				}
		}
	}
	return 0;
}