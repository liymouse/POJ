#include <stdio.h>
#include <math.h>

int main()
{
int n;
double kilo , result;
int no , i , h , m , s , totm , tots;
long tot;
char st[10];
int b;

	scanf("%d %lf" , &n , &kilo);
	while (scanf("%d" , &no) == 1)
	{
		b = 0; tot = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , st);
			if (st[0] == '-') b = 1;
			if (b == 1) continue;
			h = st[0] - '0';
			m = (st[2] - '0') * 10 + st[3] - '0';
			s = (st[5] - '0') * 10 + st[6] - '0';
			tot += h * 3600 + m * 60 + s;
		}
		if (no < 10) printf("  "); else if (no < 100) printf(" ");
		printf("%d: " , no);
		if (b == 1) printf("-\n");
		else
		{
			result = tot * 1.0 / kilo;
			if (result - floor(result) - 0.5 < -1e-6) totm = floor(result);
			else totm = floor(result) + 1;
			tots = totm % 60; totm = totm / 60;
			printf("%d:" , totm);
			if (tots < 10) printf("0");
			printf("%d min/km\n" , tots);
		}
	}
	return 0;
}
