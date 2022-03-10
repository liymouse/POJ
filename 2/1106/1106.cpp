#include <stdio.h>
#include <string.h>

int cmp(double x , double y)
{
	if (x - y < -1e-6) return -1;
	else if (x - y > 1e-6) return 1;
	else return 0;
}

int main()
{
struct node{int x , y;} a[150];
int n , x , y , b[150];
int i , j , xi , yi , xj , yj , c , tota , totb , totc , max;
double r;

	while (scanf("%d %d %lf" , &x , &y , &r) == 3)
	{
		if (cmp(r , 0) < 0) break;
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) scanf("%d %d" , &a[i].x , &a[i].y);
		memset(b , 0 , sizeof(b));
		max = 0;
		for (i = 0; i < n; i ++) 
			if (cmp((a[i].x-x) * (a[i].x-x) + (a[i].y-y) * (a[i].y-y) , r * r) <= 0) b[i] = 1;
		for (i = 0; i < n; i ++)
			if (b[i] == 1)
			{
				b[i] = 4;
				xi = a[i].x - x; yi = a[i].y - y;
				for (j = 0; j < n; j ++)
					if (b[j] == 1)
					{
						xj = a[j].x - x; yj = a[j].y - y;
						c = xi * yj - xj * yi;
						if (cmp(c , 0) > 0) b[j] = 2;
						else if (cmp(c , 0) < 0) b[j] = 3;
						else b[j] = 4;
					}
				tota = 0; totb = 0; totc = 0;
				for (j = 0; j < n; j ++)
					if (b[j] == 2) tota ++;
					else if (b[j] == 3) totb ++;
					else if (b[j] == 4) totc ++;
				if (tota + totc > max) max = tota + totc;
				if (totb + totc > max) max = totb + totc;
				for (j = 0; j < n; j ++) if (b[j] != 0) b[j] = 1;
			}
		printf("%d\n" , max);
	}
	return 0;
}