#include <stdio.h>

typedef struct
{
	int a , b , c , d;
}matrix;

void evaluate(matrix &x , int a , int b , int c , int d)
{
	x.a = a;
	x.b = b;
	x.c = c;
	x.d = d;
}

void multiply(matrix &x , matrix &y) //x ³Ëy·ÅÈëx
{
matrix z;

	z.a = (x.a * y.a + x.b * y.c) % 10000;
	z.b = (x.a * y.b + x.b * y.d) % 10000;
	z.c = (x.c * y.a + x.d * y.c) % 10000;
	z.d = (x.c * y.b + x.d * y.d) % 10000;
	x = z;
}

int main()
{
int n;
matrix base , ans;

	while (scanf("%d" , &n) == 1)
	{
		if (n == -1) break;
		evaluate(ans , 1 , 0 , 0 , 1);
		evaluate(base , 1 , 1 , 1 , 0);
		while (n)
		{
			if (n & 1) multiply(ans , base);
			multiply(base , base);
			n >>= 1;
		}
		printf("%d\n" , ans.b);
	}
	return 0;
}