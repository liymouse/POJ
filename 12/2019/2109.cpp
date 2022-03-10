#include <stdio.h>
#include <math.h>

int main()
{
double n , m;

	while(scanf("%lf%lf",&n,&m)==2) printf("%.0lf\n",pow(m,1/n));
	return 0;
}
