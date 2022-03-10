#include <stdio.h>
#include <string.h>

int main()
{
char a[400][100];
int num[400] , x[400] , y[400];
char s[600] , word[300];
int t , h , n;
int i , j , k , z , tot , bo;

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d" , &n); gets(s);
		tot = 0;
		for (i = 0; i < n; i ++) num[i] = 0;
		for (i = 0; i < n-1; i ++)
		{
			gets(s);
			k = 0;
			while (s[k] != ' ') {word[k] = s[k]; k ++;}
			bo = 0; word[k] = 0;
			for (j = 0; j < tot; j ++)
				if (strcmp(word , a[j]) == 0) {z = j; bo = 1; num[j] ++; break;}
			if (bo == 0)
			{
				strcpy(a[tot] , word);
				z = tot;
				num[tot] ++;
				tot ++;
			}
			x[i] = z;
			while (s[k] == ' ') k ++;
			j = 0;
			while ((s[k] != ' ') && (s[k] != 0)) {word[j] = s[k]; k ++; j ++;}
			bo = 0; word[j] = 0;
			for (j = 0; j < tot; j ++)
				if (strcmp(word , a[j]) == 0) {z = j; bo = 1; num[j] ++; break;}
			if (bo == 0)
			{
				strcpy(a[tot] , word);
				z = tot;
				num[tot] ++;
				tot ++;
			}
			y[i] = z;
		}
		bo = 0;
		printf("Scenario #%d:\n" , h);
		for (i = 0; i < tot; i ++) if (num[i] == 1) {k = i; break;}
		for (i = 0; i < n; i ++) if (x[i] == k) {bo = 1; break;}
		if (bo == 0) for (i = k + 1; i < tot; i ++) if (num[i] == 1) {k = i; break;}
		for (i = 0; i < n-1; i ++)
		{
			for (j = 0; j < n; j ++)
				if (x[j] == k) {printf("%s\n" , a[k]); k = y[j]; break;}
		}
		for (i = 0; i < n; i ++) if (y[j] == k) {printf("%s\n" , a[k]); break;}
		printf("\n");
    }
    return 0;
}
