#include <stdio.h>
#include <math.h>
#include <string.h>

int m , n , begin , end;
int a[103][103] = {0};

int maxflow()
{
int p[103] , L[103] , f[103][103] , su;
int i , j , m , x , tot , min;

	memset(f , 0 , sizeof(f));
	while (1)
	{
		su = 0;		
		for (i = begin; i <= end; i ++) {L[i] = 0; p[i] = 0;}
		L[begin] = begin;
		while (1)
		{
			i = begin;
			while ((i <= end) && !((L[i] != 0) && (p[i] == 0))) i ++;
			if (i > end) {su = 1; break;}
			for (j = begin; j <= end; j ++)
				if ((L[j] == 0) && ((a[i][j] > 0) || (a[j][i] > 0)))
				{
					if (f[i][j] < a[i][j]) L[j] = i;
					if (f[j][i] > 0) L[j] = -i;
				}
			p[i] = 1;
			if (L[end] != 0) break;
		}
		if (su == 0)
		{
			m = end; min = 32767;
			while (m != begin)
			{
				j = m; m = (int)fabs(L[j]);
				if (L[j] < 0) x = f[j][m];
				if (L[j] > 0) x = a[m][j] - f[m][j];
				if (x < min) min = x;
			}
		}
		if (su == 1) 
		{
			tot = 0;
			for (i = 2; i <= n + 1; i ++) tot += f[i][end];
			return tot;
		}
		else 
		{
			m = end;
			while (m != begin)
			{
				j = m; m = (int)fabs(L[j]);
				if (L[j] < 0) f[j][m] = f[j][m] - min;
				if (L[j] > 0) f[m][j] = f[m][j] + min;
			}
		}
	}
}

int main()
{
int pig[1000] , i , j , k , x , pre[1000] , max;

	scanf("%d %d" , &m , &n);
	begin = 1; end = 2 + n;
	for (i = 0; i < m; i ++) {scanf("%d" , &pig[i]); pre[i] = begin;}
	for (i = 0; i < n; i ++)
	{
		scanf("%d" , &k);
		for (j = 0; j < k; j ++) 
		{
			scanf("%d" , &x);
			if (pre[x-1] == begin) a[pre[x-1]][i + 2] += pig[x-1];
			else a[pre[x-1]][i+2] = 9999999;
			pre[x-1] = i + 2;
		}
		scanf("%d" , &x); a[i + 2][end] = x;
	}
	max = maxflow();
	printf("%d\n" , max);
	return 0;
}