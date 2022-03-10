#include <stdio.h>
#include <math.h>

int cmp(double x , int y)
{
	if (x - y < -1e-6) return -1;
	else if (x - y > 1e-6) return 1;
	else return 0;
}

int main()
{
int n , s , h , i , j , t , k , b , p , q;
double d , max;
int x[50] , y[50];

	scanf("%d" , &n);
	for (t = 0; t < n; t ++)
	{
		scanf("%d %d" , &s , &h);
		for (i = 0; i < h; i ++) scanf("%d %d" , &x[i] , &y[i]);
		for (i = 1; i < s; i ++)
		{
			for (j = 1; j < s; j ++)
			{
				max = 0; b = 0; p = i; q = j;
				if (s - i < i) p = s - i;
				if (s - j < j) q = s - j;
				for (k = 0; k < h; k ++)
				{
					if ((i == x[k]) && (j == y[k])) {b = 1; break;}
					d = sqrt((i - x[k]) * (i - x[k]) + (j - y[k]) * (j - y[k]));
					if (d > max) max = d;
					if ((cmp(max , p) > 0) || (cmp(max , q) > 0)) {b = 1; break;}
				}
				if (b == 0) {printf("%d %d\n" , i , j); break;}
			}
			if (b == 0) break;
		}
		if (b != 0) printf("poodle\n");
	}
	return 0;
}
