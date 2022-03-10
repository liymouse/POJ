#include <stdio.h>

int main()
{
int n , i , x , y , z , max , min , p , q;
struct {int tot; char name[11];} a[10];

	while (scanf("%d" , &n) == 1)
	{
		if (n == -1) break;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d %d %s" , &x , &y , &z , a[i].name);
			a[i].tot = x * y * z;
		}
		max = 0; min = 9999999;
		for (i = 0; i < n; i ++)
		{
			if (a[i].tot > max) {max = a[i].tot; p = i;}
			if (a[i].tot < min) {min = a[i].tot; q = i;}
		}
		printf("%s took clay from %s.\n" , a[p].name , a[q].name);
	}
	return 0;
}