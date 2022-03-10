#include <stdio.h>
#include <string.h>

int main()
{
int n , m , i , s , t , tot , max , a , b;
char s1[100] , s2[100];

	while (scanf("%s %s" , s1 , s2) == 2)
	{
		printf("appx(%s,%s) = " , s1 , s2);
		if (strcmp(s1 , s2) == 0) {printf("1\n"); continue;}
		n = strlen(s1); m = strlen(s2);
		max = 0;
		for (i = 0; i < n; i ++)
		{
			s = i; t = 0; tot = 0;
			while ((s < n) && (t < m)) if (s1[s++] == s2[t++]) tot ++;
			if (tot > max) max = tot;
		}
		for (i = 1; i < m; i ++)
		{
			s = 0; t = i; tot = 0;
			while ((s < n) && (t < m)) if (s1[s ++] == s2[t ++]) tot ++;
			if (tot > max) max = tot;
		}
		if (max == 0) printf("0\n");
		else
		{
			a = n + m; b = max * 2;
			while (1)
			{
				if (a % b == 0) break;
				t = a % b; a = b; b = t;
			}
			max = (max * 2) / b; s = (n + m) / b;
			printf("%d/%d\n" , max , s);
		}
	}
	return 0;
}