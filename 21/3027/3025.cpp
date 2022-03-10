#include <stdio.h>
#include <math.h>

typedef struct
{
	double x , y , r;
}RING;
int father[100];

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

int cross(RING x , RING y)
{
double dist;

	dist = sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
	if ((dist < x.r + y.r) && (dist > fabs(x.r - y.r))) return 1;
	else return 0;
}

int main()
{
int n;
int b[100];
RING a[100];
int i , j;
int p , q;
int max;

	while (scanf("%d" , &n) == 1)
	{
		if (n < 0) break;
		for (i = 0; i < n; i ++)
		{
			scanf("%lf %lf %lf" , &a[i].x , &a[i].y , &a[i].r);
			father[i] = i;
		}
		for (i = 0; i < n; i ++)
			for (j = i + 1; j < n; j ++)
			{
				if (cross(a[i] , a[j]))
				{
					p = getfather(i);
					q = getfather(j);
					father[p] = q;
				}
			}
		for (i = 0; i < n; i ++) b[i] = 0;
		max = 0;
		for (i = 0; i < n; i ++)
		{
			p = getfather(i);
			b[p] ++;
			if (b[p] > max) max = b[p];
		}
		printf("The largest component contains %d rings\n" , max);
	}
	return 0;
}