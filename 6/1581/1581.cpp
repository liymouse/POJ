#include <stdio.h>

int main()
{
int n , i , x , y , j;
struct kk{char name[21]; int tot , num;} a[100];

	scanf("%d" , &n);
	for (i = 0; i < n; i ++)
	{
		scanf("%s" , a[i].name);
		a[i].tot = 0; a[i].num = 0;
		for (j = 0; j < 4; j ++)
		{
			scanf("%d %d" , &x , &y);
			if (y != 0) {a[i].tot += y + (x-1) * 20; a[i].num ++;}
		}
	}
	x = 0; y = 0;
	for (i = 0; i < n; i ++) if (a[i].num > y) y = i;
	for (i = 0; i < n; i ++) if ((a[i].num == y) && ((a[i].tot < x) || (x == 0))) {x = a[i].tot; j = i;}
	printf("%s %d %d\n" , a[j].name , a[j].num , a[j].tot);
	return 0;
}