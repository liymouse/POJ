#include <stdio.h>
#include <math.h>

int gcd(int x , int y)
{
int t;

	if (x < y) {t = x; x = y; y = t;}
	while (1)
	{
		if (x % y == 0) return y;
		t = y; y = x % y; x = t;
	}
}

int main()
{
int n , num , tot , i , j;
int a[50];
double pi;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		num = 0; tot = n * (n - 1) / 2;
		for (i = 0; i < n; i ++)
			for (j = i + 1; j < n; j ++)
				if (gcd(a[i] , a[j]) == 1) num ++;
		if (num == 0) printf("No estimate for this data set.\n");
		else
		{
			pi = sqrt(6 * tot * 1.0 / num);
			printf("%.6lf\n" , pi);
		}
	}
	return 0;
}