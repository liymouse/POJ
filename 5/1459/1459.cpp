#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 100

int a[MAXN+3][MAXN+3] = {0};  //图的邻接矩阵

int maxflow(int n , int begin , int end) //n顶点个数 ， begin起点设为1, end终点设为最后一点
{
int p[MAXN+3] , L[MAXN+3] , f[MAXN+3][MAXN+3] , su;
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
			return tot;   //返回的最大流
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
int n , np , nc , m , i , x , y , z , j;
char s[20];

	while (scanf("%d %d %d %d" , &n , &np , &nc , &m) == 4)
	{
		memset(a , 0 , sizeof(a));
		for (i = 0; i < m; i ++)
		{
			scanf("%s" , s);
			x = 0; y = 0; z = 0;
			j = 1;
			while ((s[j] >= '0') && (s[j] <= '9')) {x = x * 10 + s[j]-'0'; j ++;}
			j ++;
			while ((s[j] >= '0') && (s[j] <= '9')) {y = y * 10 + s[j]-'0'; j ++;}
			j ++;
			while ((s[j] >= '0') && (s[j] <= '9')) {z = z * 10 + s[j]-'0'; j ++;}
			//scanf("(%d,%d)%d" , &x , &y , &z);
			if (x != y) a[x + 2][y + 2] = z;
		}
		for (i = 0; i < np; i ++)
		{
			scanf("%s" , s);
			x = 0; y = 0; j = 1;
			while ((s[j] >= '0') && (s[j] <= '9')) {x = x * 10 + s[j]-'0'; j ++;}
			j ++;
			while ((s[j] >= '0') && (s[j] <= '9')) {y = y * 10 + s[j]-'0'; j ++;}
			//scanf("(%d)%d" , &x , &y);
			a[1][x + 2] = y;
		}
		for (i = 0; i < nc; i ++)
		{
			scanf("%s" , s);
			x = 0; y = 0; j = 1;
			while ((s[j] >= '0') && (s[j] <= '9')) {x = x * 10 + s[j]-'0'; j ++;}
			j ++;
			while ((s[j] >= '0') && (s[j] <= '9')) {y = y * 10 + s[j]-'0'; j ++;}
			//scanf("(%d)%d" , &x , &y);
			a[x + 2][n + 2] = y;
		}
		printf("%d\n" , maxflow(n , 1 , n + 2));
	}
	return 0;
}