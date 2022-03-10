#include <stdio.h>
#define MAX 1999999999

int main()
{
int ti , x;
int n;
struct {int L , speed;} a[1000];
int t[1000];
int tot , min , i;

	while (scanf("%d %d" , &ti , &x) == 2)
	{
		tot = 0; min = MAX;
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &a[i].L , &a[i].speed);
			t[i] = (a[i].L - 1) / a[i].speed;
			if (t[i] < min) min = t[i];
		}
		if (min >= ti) tot = ti * x;
		else if (min == 0) tot = 0;
		else
		{
			tot = min * x; ti -= min;
			tot += (ti / 2) * x;
		}
		printf("%d\n" , tot);
	}
	return 0;
}
