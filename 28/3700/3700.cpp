#include <stdio.h>
#include <memory.h>

int n;
int a[60];
int u[8] , d[8] , U , D;
int res;

void dfs(int x)
{
	if (U + D >= res) return;
	if (x == n)
	{
		if (U + D < res) res = U + D;
		return;
	}
	//up
	int max = 0, t = -1;
	for (int i = 0; i < U; i ++)
	{
		if (a[x] > u[i] && u[i] > max) {max = u[i]; t = i;}
	}
	if (t == -1)
	{
		u[U ++] = a[x];
		dfs(x + 1);
		u[-- U] = 0;
	}
	else
	{
		int k = u[t];
		u[t] = a[x];
		dfs(x + 1);
		u[t] = k;
	}
	int min = 999999999;
	t = -1;
	for (int i = 0; i < D; i ++)
		if (a[x] < d[i] && d[i] < min) {min = d[i]; t = i;}
	if (t == -1)
	{
		d[D ++] = a[x];
		dfs(x + 1);
		d[-- D] = 0;
	}
	else
	{
		int k = d[t];
		d[t] = a[x];
		dfs(x + 1);
		d[t] = k;
	}
}

int main()
{
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (int i = 0; i < n; i ++) scanf("%d" , &a[i]);
		memset(u , 0 , sizeof(u));
		memset(d , 0 , sizeof(d));
		U = 0; D = 0; res = 8;
		dfs(0);
		printf("%d\n" , res);
	}
	
	return 0;
}
