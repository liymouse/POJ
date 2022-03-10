#include <stdio.h>
/*
#include <algorithm>
using namespace std;
*/
struct kk{int v , int t;} a[10000];

/*
bool cmp(kk &x , kk &y)
{
	return x.v > y.v;
}
*/

void qu(int s , int t)
{
int i , j , x;
struct kk y;

	i = s; j = t; x = a[(i+j)/2].v;
	while (i <= j)
	{
		while (a[i].v > x) i ++;
		while (a[j].v < x) j --;
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
int n , i , j , t , tot , min , max;
int b[10001];

	while (scanf("%d" , &n) == 1)
	{
		max = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &a[i].v , &a[i].t);
			if (a[i].t > max) max = a[i].t;
		}
		//sort(a , a + n , cmp);
		qu(0 , n - 1);
		tot = 0; min = 1;
		for (i = 0; i <= max; i ++) b[i] = 0;
		for (i = 0; i < n; i ++)
		{
			if (b[a[i].t] == 0) {tot += a[i].v; b[a[i].t] = 1;}
			else
			{
				for (j = a[i].t-1; j >= min; j --)
					if (b[j] == 0) {tot += a[i].v; b[j] = 1; break;}
			}
			if (b[min] == 1)
			{
				for (j = min + 1; j <= max; j ++) if (b[j] == 0) break;
				min = j;
				if (min > max) break;
			}
		}
		printf("%d\n" , tot);
	}
	return 0;
}