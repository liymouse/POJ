#include <stdio.h>
#include <math.h>

struct {double x , y;} p[202];
int n;
double g[212][212] , d[212];
int vis[212] = {0};

int main()
{
int i , j , id;
double x , y , min;

	scanf("%lf %lf %lf %lf", &p[0].x , &p[0].y , &p[1].x , &p[1].y);
	for (i = 0; i < 202; i ++)
		for (j = 0; j < 202; j ++)
			g[i][j] = -100.0;
	n = 2;
	while (scanf("%lf %lf", &p[n].x , &p[n].y) != EOF) 
	{
		n++;
		scanf("%lf %lf", &p[n].x , &p[n].y);
		while (p[n].x !=-1 && p[n].y !=-1) 
		{
			x = p[n].x - p[n - 1].x;
			y = p[n].y - p[n - 1].y;
			g[n - 1][n] = sqrt(x * x + y * y) * 3.0 / 2000.0;
			g[n][n - 1] = g[n - 1][n];
			n ++;
			scanf("%lf %lf", &p[n].x , &p[n].y);
		}
	}
	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j ++)
			if (g[i][j] <= -100.0) 
			{
				x = p[i].x - p[j].x;
				y = p[i].y - p[j].y;
				g[i][j] = sqrt(x * x + y * y) * 3.0 / 500.0;
			}
	d[0] = 0;
	for (i = 1; i < n; i ++)
		d[i] = g[0][i];
	for (i = 1; i < n; i ++)
	{
		min = 10000000000;
		for (j = 0; j < n; j ++)
			if ((!vis[j]) && (d[j] < min))
			{
				id = j;
				min = d[j];
			}
		vis[id] = 1;
		for (j = 0; j < n; j ++)
			if (d[id] + g[id][j] < d[j]) d[j] = d[id] + g[id][j];
	}
	printf("%.0lf\n" , d[1]);
	return 0;
}