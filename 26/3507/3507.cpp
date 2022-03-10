#include <stdio.h>

int main()
{
int a[6] , min , max , i , s;
double x;

	while (1)
	{
		s = 0;
		for (i = 0; i < 6; i ++) {scanf("%d" , &a[i]); s += a[i];}
		if (s == 0) break;
		min = 10000;
		max = 0;
		for (i = 0; i < 6; i ++) if (a[i] > max) max = a[i];
		for (i = 0; i < 6; i ++) if (a[i] < min) min = a[i];
		x = (s - min - max) * 1.0 / 4;
		printf("%g\n" , x);
	}
	return 0;
}
