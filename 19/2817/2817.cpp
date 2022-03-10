#include <stdio.h>
#include <string.h>

int res , a[10][10] , b[10] , n;

void find(int x , int tot)
{
int i;

	if (tot > res) res = tot;
	for (i = 0; i < n; i ++)
		if ((b[i] == 0) && (a[x][i] > 0))
		{
			b[i] = 1;
			find(i , tot + a[x][i]);
			b[i] = 0;
		}
}

int main()
{
int i , j , t , k , max , L1 , L2 , tot , min;
char s[10][12];

	while (scanf("%d" , &n) == 1)
	{
		if (n <= 0) break;
		for (i = 0; i < n; i ++) scanf("%s" , s[i]);
		memset(a , 0 , sizeof(a));
		memset(b , 0 , sizeof(b));
		for (i = 0; i < n; i ++)
			for (j = i + 1; j < n; j ++)
			{
				max = 0; L1 = strlen(s[i]); L2 = strlen(s[j]);
				for (t = 0; t < L2; t ++)
				{
					min = (t + L1) < L2 ? (t + L1) : L2;
					tot = 0;
					for (k = t; k < min; k ++) if (s[i][k - t] == s[j][k]) tot ++;
					if (tot > max) max = tot;
				}
				for (t = 0; t < L1; t ++)
				{
					min = (t + L2) < L1 ? (t + L2) : L1;
					tot = 0;
					for (k = t; k < min; k ++) if (s[j][k - t] == s[i][k]) tot ++;
					if (tot > max) max = tot;
				}
				if (max > 0) {a[i][j] = max; a[j][i] = max;}
			}
		res = 0;
		for (i = 0; i < n; i ++) {b[i] = 1; find(i , 0); b[i] = 0;}
		printf("%d\n" , res);
	}
	return 0;
}