#include <stdio.h>
#include <string.h>
#include <math.h>

int n , d;
struct kk{int x , y;} a[1000];
double b[1000];

void qu(int s , int t)
{
int i , j;
double x , y;
kk z;

	i = s; j = t; x = b[(i + j)/2];
	while (i <= j)
	{
		while (b[i] - x < -1e-6) i ++;
		while (b[j] - x > 1e-6) j --;
		if (i <= j)
		{
			y = b[i]; b[i] = b[j]; b[j] = y;
			z = a[i]; a[i] = a[j]; a[j] = z;
			i ++; j --;
		}
	}
	if (s < j) qu(s , j);
	if (i < t) qu(i , t);
}

int main()
{
int i , j , bo , tot , h;
int biao[1000];

	h = 0;
	while (scanf("%d %d" , &n , &d) == 2)
	{
		if (n == 0) break;
		bo = 0; h ++; tot = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &a[i].x , &a[i].y);
			if (a[i].y > d) bo = 1;
			if (bo == 0) b[i] = a[i].x + sqrt(d * d - a[i].y * a[i].y);
		}
		if (bo) printf("Case %d: -1\n" , h);
		else
		{
			qu(0 , n - 1);
			memset(biao , 0 , sizeof(biao));
			for (i = 0; i < n; i ++)
			{
				if (biao[i]) continue;
				else
				{
					tot ++;
					for (j = 0; j < n; j ++)
						if ((biao[j] == 0) && ((a[j].x-b[i])*(a[j].x-b[i]) + a[j].y*a[j].y <= d*d))
							biao[j] = 1;
				}
			}
			printf("Case %d: %d\n" , h , tot);
		}
	}
	return 0;
}