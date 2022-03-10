#include <stdio.h>
#include <math.h>

typedef struct {double date; int x , y;} kk;
kk a[5501];
int father[101];
double x[101] , y[101];
int n , t;

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

void qu(int s , int t)
{
int i , j;
double x;
kk y;

	i = s; j = t; x = a[(i+j)/2].date;
	while (i <= j)
	{
		while (a[i].date < x) i ++;
		while (a[j].date > x) j --;
		if (i <= j)
		{
			y = a[i]; a[i] = a[j]; a[j] = y;
			i ++; j --;
		}
	}
	if (s < j) qu(s , j);
	if (i < t) qu(i , t);
}

int main()
{
int i , j , p , q;
double tot;

	scanf("%d" , &n);
	t = 0;
	for (i = 1; i <= n; i ++) scanf("%lf %lf" , &x[i] , &y[i]);
	for (i = 1; i <= n; i ++) for (j = i; j <= n; j ++)
	{
		a[t].date = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		a[t].x = i; a[t].y = j;
		t ++;
	}
	for (i = 1; i <= n; i ++) father[i] = i;
	qu(0 , t - 1);
	tot = 0;
	for (i = 0; i < t; i ++)
	{
		p = getfather(a[i].x); q = getfather(a[i].y);
		if (p != q) 
		{
			tot += a[i].date;
			father[p] = q;
		}
	}
	printf("%.2lf\n" , tot);
	getchar(); getchar();
	return 0;
}
