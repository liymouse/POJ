#include <stdio.h>
#include <math.h>
#define e 2.718281828459045
#define Pi 2 * acos(0)

int main()
{
int t , n , i;
double k;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		k = 1;
		if (n <= 10000)
			for (i = 1; i <= n; i ++) k += log10(i);
		else k += n * log10(n / e) + 0.5 * log10(2 * Pi * n);
		k = (int)k;
		printf("%.0lf\n" , k);
	}
}
