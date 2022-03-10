#include <stdio.h>
#include <string.h>

int f[17][17];
int m , n;
int a[17][310];
int p[17];
int res[310];
int z[17];
int ok;
int r;

void find(int x)
{
	if (r == n) {ok = 1; return;}
	if (x >= m) return;
	

	//jianzhi
	memset(res , 0 , sizeof(res));
	for (int i = 0; i < x; i ++)
		if (p[i] == 2)
			for (int j = 0; j < n; j ++)
				res[j] += a[i][j];
	for (int i = x; i < m; i ++)
		if (p[i] == 1)
			for (int j = 0; j < n; j ++)
				res[j] += a[i][j];
	for (int i = 0; i < n; i ++)
		if (res[i] == 0) return;
	//end of jianzhi

	for (int i = x; i < m; i ++)
		if (p[i] == 1)
		{
			int q[17];
			for (int j = 0; j < m; j ++) q[j] = p[j];
			p[i] = 2;
			for (int j = i+1; j < m; j ++) if (f[i][j] == 0) p[j] = 0;
			//for (int j = 0; j < n; j ++) res[j] += a[i][j];
			r += z[i];
			find(i + 1);
			if (ok) return;
			r -= z[i];
			//for (int j = 0; j < n; j ++) res[j] -= a[i][j];
			for (int j = 0; j < m; j ++) p[j] = q[j];
		}
}

int main()
{
	while (scanf("%d %d" , &m , &n) == 2)
	{
		for (int i = 0; i < m; i ++)
		{
			z[i] = 0;
			for (int j = 0; j < n; j ++)
			{
				scanf("%d" , &a[i][j]);
				z[i] += a[i][j];
			}
		}
		memset(f , 0 , sizeof(f));
		for (int i = 0; i < m; i ++)
			for (int j = 0; j < m; j ++)
				if (i != j)
				{
					f[i][j] = 1;
					for (int k = 0; k < n; k ++)
						if (a[i][k] == 1 && a[j][k] == 1) {f[i][j] = 0; break;}
				}
		ok = 0;
		for (int i = 0; i < m; i ++) p[i] = 1;
		memset(res , 0 , sizeof(res));
		r = 0;
		find(0);
		if (ok) printf("Yes, I found it\n");
		else printf("It is impossible\n");
	}
	return 0;
}
