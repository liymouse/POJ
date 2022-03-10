#include <stdio.h>
#include <string.h>
int b[27][27];
int a[27];
int n;

void dfs(int x)
{
int i , j;

	if (a[x] == 1) return;
	a[x] = 1;
	for (i = 0; i < n; i ++)
		if (b[i][x] == 1)
		{
			for (j = 0; j < n; j ++)
				if (b[x][j] == 1) b[i][j] = 1;
			dfs(i);
		}
}

bool sortFinish(char * str)
{
int s[27] , k[27] , i , j , x;

	for (i = 0; i < n; i ++)
	{
		s[i] = 0; k[i] = i;
		for (j = 0; j < n; j ++) s[i] += b[i][j];
	}
	for (i = 0; i < n; i ++)
		for (j = 1; j < n - i; j ++)
			if (s[j-1] < s[j])
			{
				x = s[j-1]; s[j-1] = s[j]; s[j] = x;
				x = k[j-1]; k[j-1] = k[j]; k[j] = x;
			}
	for (i = 1; i < n; i ++)
		if (s[i] == s[i-1]) return false;
	for (i = 0; i < n; i ++)
		str[i] = k[i] + 'A';
	str[i] = 0;
	return true;
}

bool inconsistency()
{
int i , j;

	for (i = 0; i < n; i ++) for (j = 0; j < n; j ++) if (b[i][j] + b[j][i] == 2) return true;
	return false;
}

int main()
{

int m , step , x , y , i ,j , k;
char s[10] , res[30];
int ok;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if (n == 0 && m == 0) break;
		memset(b , 0 , sizeof(b));
		ok = 0;
		for (k = 1; k <= m; k ++)
		{
			scanf("%s" , s);
			if (ok > 0) continue;
			x = s[0] - 'A';
			y = s[2] - 'A';

			if (b[x][y] == 0)
			{
				b[x][y] = 1;
				if (inconsistency())
				{
					step = k;
					ok = 1;
				}
				else
				{
					for (i = 0; i < n; i ++) if (b[y][i] == 1) b[x][i] = 1;
					memset(a , 0 , sizeof(a));
					dfs(x);
					if (sortFinish(res))
					{
						step = k;
						ok = 2;
					}
				}
			}
		}
		if (ok == 0) printf("Sorted sequence cannot be determined.\n");
		else if (ok == 1) printf("Inconsistency found after %d relations.\n" , step);
		else printf("Sorted sequence determined after %d relations: %s.\n" , step , res);
	}
	return 0;
}
