#include <stdio.h>
#include <math.h>
#include <string.h>


int map[120][120];
int chk[120];
int match[120];
int m , n;
int xa[120] , ya[120] , xb[120] , yb[120];

int Dfs(int p)
{
	int i , t;
	for (i = 0; i < m; i ++)
		if (map[i][p] && !chk[i])
		{
			chk[i] = 1;
			t = match[i];
			match[i] = p;
			if(t == n || Dfs(t))return 1;
			match[i] = t;
		}
		return 0;
}

int maxmatch()
{
	int i , res = 0;

	for (i = 0; i < m; i ++) match[i] = n;
	for (i = 0; i < n; i ++)
	{
		memset(chk , 0 , sizeof(chk));
		if (Dfs(i))
			res ++;
	}
	return res;
}

int main()
{
	while (scanf("%d %d" , &m , &n) == 2)
	{
		for (int i = 0; i < m; i ++) scanf("%d %d" ,&xa[i] , &ya[i]);
		for (int i = 0; i < n; i ++) scanf("%d %d" , &xb[i] , &yb[i]);
		memset(map , 0 , sizeof(map));
		for (int i = 1; i < m; i ++)
		{
			double dist = sqrt(double(xa[i] - xa[i-1]) * (xa[i] - xa[i-1]) + (ya[i] - ya[i-1]) * (ya[i] - ya[i-1]));
			for (int j = 0; j < n; j ++)
			{
				double d1 = sqrt(double(xa[i] - xb[j])*(xa[i]-xb[j]) + (ya[i] - yb[j]) * (ya[i] - yb[j]));
				double d2 = sqrt(double(xa[i-1] - xb[j])*(xa[i-1]-xb[j]) + (ya[i-1]-yb[j]) * (ya[i-1] - yb[j]));
				if (d1 + d2 < 2 * dist)
					map[i-1][j] = 1;
			}
		}
		m --;
		maxmatch();
		int res = m + 1;
		for (int i = 0; i < m; i ++)
			if (match[i] != n) res ++;
		printf("%d\n" , res);
		for (int i = 0; i < m; i ++)
		{
			printf("%d %d " , xa[i] , ya[i]);
			if (match[i] != n)
				printf("%d %d " , xb[match[i]] , yb[match[i]]);
		}
		printf("%d %d\n" , xa[m] , ya[m]);
	}

	return 0;
}
