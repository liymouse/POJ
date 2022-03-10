#include <stdio.h>
#define Pi 3.141592653589793238436
#define IN 2.54

int main()
{
int sw , p , d , i;
double res;
char s[10];

	while (scanf("%s" , s) == 1)
	{
		printf("%s " , s);
		scanf("%d / %d" , &sw , &p);
		printf("%d / %d " , sw , p);
		scanf("%s" , s);
		printf("%s" , s);
		while ((s[0] < '0') || (s[0] > '9')) {scanf("%s" , s); printf(" %s" , s);}
		d = 0;
		i = 0;
		while (s[i] > 0) {d = d * 10 + s[i] - '0'; i ++;}
		res = (0.002 * sw * p + d * IN) * Pi;
		printf(": %.0lf\n" , res);
	}
	return 0;
}