#include <stdio.h>

int main()
{
char s[11];
int sum , i , k , x;

	gets(s);
	sum = 0;
	for (i = 0; i < 10; i ++)
		if (s[i] == 'X') sum += (10-i) * 10;
		else if (s[i] == '?') k = 10 - i;
		else sum += (10 - i) * (s[i] - '0');
	if (k == 1) x = 10; else x = 9;
	for (i = 0; i <= x; i ++) if ((sum + i * k) % 11 == 0) {k = -1; break;}
	if (k != -1) printf("-1\n");
	else if (i < 10) printf("%d\n" , i); else printf("X\n");
	return 0;
}
