#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
int a[3001] , b[3001];
int n , i , k;

	while (scanf("%d" , &n) == 1)
	{
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		memset(b , 0 , sizeof(b));
		for (i = 1; i < n; i ++)
			b[abs(a[i-1] - a[i])] = 1;
		k = 0;
		for (i = 1; i < n; i ++) if (b[i] == 1) k ++;
		if (k == n - 1) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}
