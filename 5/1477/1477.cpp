#include <stdio.h>

int main()
{
int n , a[50] , ave , tot , t , i;

	t = 0;
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		ave = 0; t ++; tot = 0;
		for (i = 0; i < n; i ++) {scanf("%d" , &a[i]); ave += a[i];}
		ave /= n;
		for (i = 0; i < n; i ++) if (a[i] > ave) tot += a[i] - ave;
		printf("Set #%d\n" , t);
		printf("The minimum number of moves is %d.\n\n" , tot);
	}
	return 0;
}