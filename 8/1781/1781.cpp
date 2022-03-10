#include <stdio.h>
#include <string.h>

int main()
{
char s[5];
int a[27] , b[27];
int x , i , k;

	a[0] = 1;
	for (i = 1; i < 27; i ++) a[i] = a[i-1] * 2;
	while (scanf("%s" , s) == 1)
	{
		if (strcmp(s , "00e0") == 0) break;
		x = s[0] - '0';
		x = x * 10 + s[1] - '0';
		for (i = 0; i < s[3] - '0'; i ++) x *= 10;
		k = 26;
		while (x < a[k]) k --;
		x -= a[k];
		for (i = k-1; i >= 0; i --) if (x >= a[i]) {b[i + 1] = 1; x -= a[i];} else b[i + 1] = 0;
		b[0] = 1;
		x = 0;
		for (i = 0; i <= k; i ++)
			x += a[i] * b[i];
		printf("%d\n" , x);
	}
	return 0;
}