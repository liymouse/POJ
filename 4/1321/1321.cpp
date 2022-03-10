#include <stdio.h>

int a[8][8] , b[8];
int n , k , total;

void find(int x , int tot)
{
int i;

	if (x == n)
	{
		if (tot == k) total ++;
		return;
	}
	if (tot > k) return;
	for (i = 0; i < n; i ++)
		if ((a[x][i] == 0) && (b[i] == 0))
		{
			b[i] = 1;
			find (x + 1 , tot + 1);
			b[i] = 0;
		}
	find(x + 1 , tot);
}

int main()
{
int i , j;
char s[8];

	while (scanf("%d %d\n" , &n , &k) == 2)
	{
		if (n == -1) break;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			for (j = 0; j < n; j ++)
				if (s[j] == '#') a[i][j] = 0; else a[i][j] = 1;
			b[i] = 0;
		}
		total = 0;
		find(0 , 0);
		printf("%d\n" , total);
	}
	return 0;
}