#include <stdio.h>
#include <string.h>
#include <math.h>

int n , m , a[500][500];
int cx[500], cy[500], vx[500], vy[500];

int find(int u)
{
int v;

	vx[u] = 1;
	for (v = 0; v < m; ++v)
	{
		if (!a[u][v] || vy[v]) continue;
		vy[v] = 1;
		if (cy[v] == -1 || find(cy[v]))
		{
			cx[u] = v; cy[v] = u;
			return 1;
		}
	}
	return 0;
}

int maxmatch() 
{
int i , res;

	memset(cx , -1 , sizeof(cx));
	memset(cy , -1 , sizeof(cy));
	res = 0;
	for (i = 0; i < n; i ++)
	{
		memset(vx , 0 , sizeof(vx));
		memset(vy , 0 , sizeof(vy));
		if (find(i)) res ++;
	}
	return res;
}

int main()
{
int i , t , x , y , k;

	while (scanf("%d %d %d" , &n , &m , &k) == 3)
	{
		memset(a , 0 , sizeof(a));
		for (i = 0; i < k; i ++)
		{
			scanf("%d %d %d" , &t , &x , &y);
			if ((x != 0) && (y != 0)) a[x][y] = 1;
		}
		t = maxmatch();
		printf("%d\n" , t);
	}
	return 0;
}