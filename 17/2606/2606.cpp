#include <stdio.h>
#include <string.h>

int main()
{
int n , i , j , x , y , k , tot , max;
struct {int x , y;} a[200];
int b[200][200];

	scanf("%d" , &n);
	max = 0;
	for (i = 0; i < n; i ++)
		scanf("%d %d" , &a[i].x , &a[i].y);
	memset(b , 0 , sizeof(b));
	for (i = 0; i < n; i ++)
		for (j = i + 1; j < n; j ++)
			if (b[i][j] == 0)
			{
				x = a[j].x - a[i].x;
				y = a[j].y - a[i].y;
				tot = 0;
				for (k = 0; k < n; k ++)
					if (x * (a[k].y - a[i].y) == (a[k].x - a[i].x) * y) {b[k][i] = 1; tot ++;}
				if (tot > max) max = tot;
			}
	printf("%d\n" , max);
	return 0;
}
