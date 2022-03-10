#include <stdio.h>
#include <string.h>

int main()
{
char s[26];
int n , min , a[13] , tot , i;

	while(scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		min = 26;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			a[i] = strlen(s);
			if (a[i] < 25) {scanf("%s" , s); a[i] += strlen(s);}
			a[i] = 25 - a[i];
			if (a[i] < min) min = a[i];
		}
		tot = 0;
		for (i = 0; i < n; i ++) tot += a[i] - min;
		printf("%d\n" , tot);
	}
	return 0;
}