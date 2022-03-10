#include <stdio.h>
#include <math.h>
#define Pi 3.1415926535897932384626433832795

int main()
{
int u , a , d;
double angle , step;

	while (scanf("%d %d %d" , &u , &a , &d) == 3)
	{
		if (u == 0) break;
		angle = double(a) * Pi / 180;
		step = d * (exp(angle / sqrt(3.0)) - 1) / u;
		if (step >= 10000.0) printf("God help me!\n");
		else printf("%.0lf\n" , step);
	}
	return 0;
}

// GUSH 积出来的公式 
