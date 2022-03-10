#include <stdio.h>
#include <string.h>

int main()
{
char s[100];
int a[26] , n , i , j , tot;

	scanf("%d\n" , &n);
	for (i = 1; i <= n; i ++)
	{
		memset(a , 0 , sizeof(a));
		gets(s);
		j = 0;
		while (s[j] > 0)
		{
			a[s[j]-'a'] ++;
			j ++;
		}
		gets(s);
		j = 0;
		while (s[j] > 0)
		{
			a[s[j]-'a'] --;
			j ++;
		}
		tot = 0;
		for (j = 0; j < 26; j ++) if (a[j] > 0) tot += a[j]; else tot -= a[j];
		printf("Case #%d:  %d\n" , i , tot);
	}
	return 0;
}