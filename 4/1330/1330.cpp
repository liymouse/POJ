#include <stdio.h>

int main()
{
int n , t;
int father[10001];
int a , b , i , j , x , y , res;
int f1[10001] , f2[10001] , t1 , t2;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 1; i <= n; i ++) father[i] = i;
		for (i = 0; i < n - 1; i ++)
		{
			scanf("%d %d" , &x , &y);
			father[y] = x;
		}
		scanf("%d %d" , &a , &b);
		x = a; t1 = 0;
		while (father[x] != x)
		{
			f1[t1 ++] = x;
			x = father[x];
		}
		f1[t1 ++] = x;
		y = b; t2 = 0;
		while (father[y] != y)
		{
			f2[t2 ++] = y;
			y = father[y];
		}
		f2[t2 ++] = y;
		res = 0;
		for (i = 0; i < t1; i ++)
		{
			for (j = 0; j < t2; j ++)
				if (f1[i] == f2[j]) {res = f1[i]; break;}
			if (res > 0) break;
		}
		printf("%d\n" , res);
	}
	return 0;
}
