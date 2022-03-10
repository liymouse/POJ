#include <stdio.h>

int father[101];

int getfather(int x)
{
int f;

	if (father[x] == x) return x;
	else
	{
		f = getfather(father[x]);
		father[x] = f;
		return f;
	}
}

int main()
{
int a[101][101] = {0} , b[101] , done;
int p , t , x , y;
int i , j , k , tot;

	scanf("%d %d" , &p , &t);
	while (scanf("%d %d" , &x , &y) == 2)
		a[x][y] = 1;
	tot = 0;
	for (i = 1; i <= p; i ++) father[i] = i;
	for (i = 1; i <= p; i ++)
		for (j = i + 1; j <= p; j ++)
		{
			done = 0;
			for (k = 1; k <= t; k ++) if (a[i][k] != a[j][k]) {done = 1; break;}
			if (done == 0)
			{
				x = getfather(i); y = getfather(j);
				father[x] = y;
			}
		}
	for (i = 1; i <= p; i ++) b[i] = 0;
	for (i = 1; i <= p; i ++)
	{
		x = getfather(i);
		if (b[x] == 0) {tot ++; b[x] = tot;}
	}
	printf("%d\n" , tot);
	return 0;
}
