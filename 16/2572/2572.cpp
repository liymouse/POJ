#include <stdio.h>
#include <string.h>


char s[1000] , st[100] , ch;
__int64 a , b , c;
int i;

__int64 kk()
{
int t , j , L;
__int64 x;

	t = 0;
	while ((s[i] >= '0') && (s[i] <= '9')) st[t ++] = s[i ++];
	st[t] = 0;
	i ++;
	L = strlen(st);
	for (j = 0; j < L / 2; j ++)
	{ch = st[j]; st[j] = st[L - j - 1]; st[L - j - 1] = ch;}
	x = 0;
	for (j = 0; j < L; j ++) x = x * 10 + st[j] - '0';
	return x;
}

int main()
{
	while (scanf("%s" , s) == 1)
	{
		i = 0;
		a = kk();
		b = kk();
		c = kk();
		if (a + b == c) printf("True\n");
		else printf("False\n");
	}
	return 0;
}
