#include <stdio.h>

int main()
{
int n , i;
double a0 , an , c , s;

	scanf("%d" , &n);
	scanf("%lf %lf" , &a0 , &an);
	s = 0;
	for (i = 1; i <= n; i ++) {scanf("%lf" , &c); s += (n - i + 1) * c;}
	printf("%.2lf\n" , ((n * a0 + an) - 2 * s) / (n+1));
	return 0;
}