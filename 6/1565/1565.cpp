#include <stdio.h>
#include <string.h>

int main()
{
int p[32];
int i , L , t , x;
char s[32];

	p[0] = 1;
	for (i = 1; i < 32; i ++) p[i] = p[i-1] * 2;
	for (i = 1; i < 32; i ++) p[i] --;
	while (scanf("%s" , s) == 1)
	{
		if (s[0] == '0') break;
		L = strlen(s); t = 1; x = 0;
		for (i = L-1; i >= 0; i --)
			x += p[t ++] * (s[i] - '0');
		printf("%d\n" , x);
	}
}