#include <stdio.h>
#include <string.h>
#include <math.h>

int a[101][301] , chk[301] , match[301] , n , m;

int Dfs(int p)
{
int i , t;
	for(i = 0; i < m; i ++)
		if(a[i][p] && !chk[i])
		{
			chk[i] = 1;
			t = match[i];
			match[i] = p;
			if(t == n || Dfs(t))return 1;
			match[i] = t;
		}
	return 0;
}

int Pro()
{
int i , res = 0;

	for (i = 0; i < m; i ++) match[i] = n;
	for(i = 0; i < n; i ++)
	{
		memset(chk , 0 , sizeof(chk));
		if(Dfs(i))
		res ++;
	}
	return res;
}


int main()
{
int t , i , j , k , x , b[300];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &m , &n);
		memset(a , 0 , sizeof(a));
		memset(b , 0 , sizeof(b));
		for (i = 0; i < m; i ++)
		{
			scanf("%d" , &k);
			for (j = 0; j < k; j ++)
			{
				scanf("%d" , &x);
				b[x-1] = 1;
				a[i][x-1] = 1;
			}
		}
		k = 0;
		for (i = 0; i < n; i ++) k += b[i];
		if ((n < m) || (k < m)) {printf("NO\n"); continue;}
		k = Pro();
		if (k == m) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}