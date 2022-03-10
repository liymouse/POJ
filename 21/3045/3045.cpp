#include <stdio.h>
#include <algorithm>
using namespace std;

#define max(a,b) (((a)>(b))?(a):(b))
typedef struct
{
	int w , s;
}cow;
cow a[50000];

int cmp(cow &x , cow &y)
{
	return (x.w + x.s) < (y.w + y.s);
}

int main()
{
int n , i , sum , res;

	while (scanf("%d" , &n) == 1)
	{
		for (i = 0; i < n; i ++)
			scanf("%d %d" , &a[i].w , &a[i].s);
		sort(a , a + n , cmp);
		sum = 0; res = -1000000000;
		for (i = 0; i < n; i ++)
		{
			res = max(res , sum - a[i].s);
			sum += a[i].w;
		}
		printf("%d\n" , res);
	}
	return 0;
}
