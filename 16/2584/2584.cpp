#include <stdio.h>
#include <string.h>
#include <math.h>

int a[28][28] , n , begin , end;

int change(char c)
{
	switch (c)
	{
		case 'S': return n + 2;
		case 'M': return n + 3;
		case 'L': return n + 4;
		case 'X': return n + 5;
		case 'T': return n + 6;
	}
}

int maxflow()
{
int p[28] , L[28] , f[28][28] , su;
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
			for (i = n + 2; i <= n + 6; i ++) tot += f[i][end];
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
int i , j , small , big , num , tot;
char s[50];
	
	while (scanf("%s" , s) == 1)
	{
		if (s[0] == 'E') return 0;
		scanf("%d" , &n);
		for (i = 2; i <= n+1; i ++) 
		{
			scanf("%s" , s);
			for (j = change(s[0]); j <= change(s[1]); j ++)
				a[i][j] = 1;
		}
		begin = 1; end = n + 7;
		for (i = n + 2; i <= n + 6; i ++)
		{
			scanf("%d" , &num);
			a[i][end] = num;
		}
		scanf("%s" , s);
		for (i = 2; i <= n+1; i ++) a[begin][i] = 1;
		tot = maxflow();
		if (tot == n) printf("T-shirts rock!\n");
		else printf("I'd rather not wear a shirt anyway...\n");
	}
	return 0;
}