#include <stdio.h>

int main()
{
int f[301][31] = {0} , a[301] = {0} , d[301][301] = {0};
int i , j , k , t , v , p , min , tot;

	scanf("%d %d" , &v , &p);
	for (i = 1; i <= v; i ++) scanf("%d" , &a[i]);
	for (i = 1; i <= v; i ++)
		for (j = i + 1; j <= v; j ++)
		{
			t = i + (j - i) / 2; d[i][j] = 0;
			for (k = i; k < t; k ++) d[i][j] += a[t] - a[k];
			for (k = t + 1; k <= j; k ++) d[i][j] += a[k] - a[t];
		}
	for (i = 1; i <= v; i ++) f[i][1] = d[1][i];
	for (i = 1; i <= v; i ++)
		for (j = 2; j <= p; j ++)
		{
			if (j > i) break;
			min = 999999999;
			for (k = j; k < i; k ++)
				if (f[k][j-1] + d[k+1][i] < min) min = f[k][j-1] + d[k+1][i];
			f[i][j] = min;
		}
	printf("%d\n" , f[v][p]);
	return 0;
}
