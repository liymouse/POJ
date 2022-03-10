#include <stdio.h>
#include <string.h>

int letter(char c)
{
	if ((c >= 'a') && (c <= 'z') || (c >= 'A') && (c <= 'Z')) return 1;
	else return 0;
}

int upletter(char c)
{
	if ((c >= 'A') && (c <= 'Z')) return 1; else return 0;
}

int digit(char c)
{
	if ((c >= '0') && (c <= '9')) return 1; else return 0;
}

int biao(char c)
{
	if (!letter(c) && !digit(c) && (c != ' ') && (c != '"')) return 1;
	else return 0;
}

int main()
{
char s[100];
int i , b , L;

	while (gets(s))
	{
		if (s[0] == '#') break;
		b = 1; L = strlen(s);
		if ((L == 1) && (s[0] != 'A') && (s[0] != 'a') && (s[0] != 'I')) b = 0;
		if (b)
		for (i = 1; i < L; i ++)
			if (upletter(s[i-1]) && upletter(s[i])) {b = 0; break;}
		if (b)
		{
			for (i = 1; i < L; i ++)
				if ((digit(s[i-1]) && letter(s[i])) || (digit(s[i]) && letter(s[i-1])))
				{b = 0; break;}
		}
		if (b)
		{
			for (i = 1; i < L-1; i ++)
				if ((s[i] != 'A') && (s[i] != 'a') && (s[i] != 'I') && (s[i-1] == ' ') && (s[i + 1] == ' '))
				{b = 0; break;}
			if ((s[0] != 'A') && (s[0] != 'a') && (s[0] != 'I') && (s[1] == ' ')) b = 0;
			if ((s[L-2] == ' ') && (s[L-1] != 'A') && (s[L-1] != 'a') && (s[L-1] != 'I')) b = 0;
		}
		if (b)
		{
			for (i = 1; i < L; i ++)
				if (biao(s[i-1]) && biao(s[i])) {b = 0; break;}
		}
		if (b) printf("OK\n"); else printf("suspicious\n");
	}
	return 0;
}