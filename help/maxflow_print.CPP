#include <stdio.h>
#include <math.h>

int f[100][100] = {0} , c[100][100] = {0};
int L[100] = {0} , p[100] = {0};
int n , s , t , min;

int ford()
{
int i , j , m , x;
    
	for (i = 1; i <= n; i ++) {L[i] = 0; p[i] = 0;}
	L[s] = 1;
	while (1)
	{
		i = 1;
		while ((i <= n) && !((L[i] != 0) && (p[i] == 0))) i ++;
		if (i > n) return 1;
		for (j = 1; j <= n; j ++)
			if ((L[j] == 0) && ((c[i][j] > 0) || (c[j][i] > 0)))
			{
				if (f[i][j] < c[i][j]) L[j] = i;
				if (f[j][i] > 0) L[j] = -i;
			}
		p[i] = 1;
		if (L[t] != 0) break;
	}
	m = t; min = 32767;
	while (m != s)
	{
		j = m; m = (int)fabs(L[j]);
		if (L[j] < 0) x = f[j][m];
		if (L[j] > 0) x = c[m][j] - f[m][j];
		if (x < min) min = x;
	}
	return 0;
}

void change()
{
int m , j;

	m = t;
	while (m != s)
	{
		j = m; m = (int)fabs(L[j]);
		if (L[j] < 0) f[j][m] = f[j][m] - min;
		if (L[j] > 0) f[m][j] = f[m][j] + min;
	}
}

void print()
{
int i , j , max;

	max = 0;
	for (i = 1; i <= n; i ++)
	{
		if (f[i][t] != 0) max += f[i][t];
		for (j = 1; j <= n; j ++)
			if (f[i][j] != 0) printf("%d -> %d  %d\n" , i , j , f[i][j]);
	}
	printf("The Max Stream = %d" , max);
}

void maxflow()
{
int del , success;

	s = 1; t = n; success = 0;
	while (1)
	{
		success = ford();
		if (success == 1) {print(); break;}
		else change();
	}
}

int main()
{
int i , j;

	scanf("%d" , &n);
	for (i = 1; i <= n; i ++) for (j = 1; j <= n; j ++) scanf("%d" , &c[i][j]);
	maxflow();
	getchar(); getchar();
	return 0;
}
