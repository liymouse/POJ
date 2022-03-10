#include <stdio.h>

int main()
{
int p , q , r , s , i , j , k , t , b;
double res;

	while (scanf("%d %d %d %d" , &p , &q , &r , &s) == 4)
	{
		res = 1;
		/*for (i = 1; i <= q; i ++)
			res *= (p - q + i) * 1.0 / i;
		for (i = 1; i <= s; i ++)
			res *= i * 1.0 / (r - s + i);
		*/
		if (s < q) k = q; else k = s;
		for (i = 1; i <= k; i ++)
		{
			if (i <= q) res *= (p - q + i) * 1.0 / i;
			if (i <= s) res *= i * 1.0 / (r - s + i);
		}
		
		/*
		for (i = k; i <= t; i ++) 
			if (b) res *= i; else res *= 1.0 / i;
		for (i = 1; i <= s; i ++) res *= 1.0 / (r - s + i);
		for (i = 1; i <= q; i ++) res *= p - q + i;
		*/
		printf("%.5lf\n" , res);
	}
	return 0;
}