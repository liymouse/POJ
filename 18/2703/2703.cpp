#include <stdio.h>
#include <algorithm>
using namespace std;

struct kk{int min , max;}a[1000];

bool cmp(kk x , kk y)
{
	return x.min > y.min;
}

int main()
{
int n , x , y , i , area;

	while (scanf("%d" , &n) == 1)
	{
		if (n < 0) break;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &x , &y);
			if (x > y) {a[i].max = x; a[i].min = y;}
			else {a[i].min = x; a[i].max = y;}
		}
		sort(a , a + n , cmp);
		x = a[0].min; y = x; area = x * x;
		for (i = 0; i < n; i ++)
		{
			if ((x < y) && (a[i].max > x))
			{
				area += (a[i].max - x) * a[i].min;
				x = a[i].max;
			}
			else if (a[i].max > y)
			{
				area += (a[i].max - y) * a[i].min;
				y = a[i].max;
			}
		}
		printf("%d\n" , area);
	}
	return 0;
}