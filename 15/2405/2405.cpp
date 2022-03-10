#include <stdio.h>
#include <math.h>
#define Pi 3.1415926535897932384626433832795

int main()
{
int D , V;
double x;

	while (scanf("%d %d" , &D , &V) == 2)
	{
		if (D == 0) break;
		x = D * 1.0 / 2;
		x = x * x * x - 0.75 * V / Pi;
		x = log(x) / 3;
		x = exp(x) * 2;
		printf("%.3lf\n" , x);
	}
	return 0;
}