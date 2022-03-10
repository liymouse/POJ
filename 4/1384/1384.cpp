#include <stdio.h>

int main()
{
int f[10001];
int x , y , n , t;
int i , j , min;
struct {int v , w;} a[500];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &x , &y);
		x = y - x;
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
			scanf("%d %d" , &a[i].v , &a[i].w);
		if (x == 0) {printf("The minimum amount of money in the piggy-bank is 0.\n"); continue;}
		for (i = 0; i <= x; i ++) f[i] = 0;
		for (i = 0; i <= x; i ++)
		{
			min = 1999999999;
			for (j = 0; j < n; j ++)
				if ((i == a[j].w) && (a[j].v < min)) min = a[j].v;
				else if ((i > a[j].w) && (f[i-a[j].w] > 0) && (f[i-a[j].w] + a[j].v < min))
					min = f[i-a[j].w] + a[j].v;
				if (min < 1999999999) f[i] = min;
		}
		if (f[x] == 0) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n" , f[x]);
	}
	return 0;
}