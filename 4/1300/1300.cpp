#include <stdio.h>
#include <string.h>
int a[30][30] , b[30] , c[30];
int n;

void dfs(int x)
{
	c[x] = 1;
	for (int i = 0; i < n; i ++)
		if (c[i] == 0 && a[x][i] > 0) dfs(i);
}

int main()
{
int m;
char s[100];

int i , j , t , res;

	while (scanf("%s" , s) == 1)
	{
		if (s[0] == 'E') break;
		scanf("%d %d\n" , &m , &n);
		memset(a , 0 , sizeof(a));
		res = 0;
		for (i = 0; i < n; i ++)
		{
			gets(s); t = -1;
			for (j = 0; j < strlen(s); j ++)
				if (s[j] >= '0' && s[j] <= '9')
				{
					if (t == -1) t = s[j] - '0';
					else t = t * 10 + s[j] - '0';
				}
				else
				{
					if (t != -1) { a[i][t] ++; a[t][i] ++; res ++; }
					t = -1;
				}
			if (t != -1) {a[i][t] ++; a[t][i] ++; res ++; }
		}
		gets(s);
		t = 1;
		for (i = 0; i < n; i ++)
		{
			b[i] = 0;
			for (j = 0; j < n; j ++) b[i] += a[i][j];
		}
		memset(c , 0 , sizeof(c));
		dfs(0);
		if (c[0] + c[m] != 2) t = 0;
		if (t)
		{
			for (i = 0; i < n; i ++)
				if (c[i] == 0 && b[i] > 0) {t = 0; break;}
		}
		if (t)
		{
			for (i = 1; i < n; i ++)
				if (i != m && b[i] % 2 == 1) {t = 0; break;}
		}
		if (t)
		{
			if (m > 0 && b[0] % 2 == 1 && b[m] % 2 == 1) t = 1;
			else if (m == 0 && b[0] % 2 == 0) t = 1;
			else t = 0;
		}
		if (t) printf("YES %d\n" , res);
		else printf("NO\n");
	}
	return 0;
}