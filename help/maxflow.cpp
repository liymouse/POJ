#include <stdio.h>
#include <math.h>
#include <string.h>

int n , begin , end;  //n顶点数    begin 原点 end 终点
int a[103][103] = {0};  //最大容量

int maxflow() //返回最大流
{
int p[103] , L[103] , f[103][103] , su;  //L标号，p检查 , f流量
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
			for (i = beign; i <= end; i ++) tot += f[i][end];
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
int max;

	max = maxflow();
	printf("%d\n" , max);
	return 0;
}