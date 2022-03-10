#include <stdio.h>
#include <math.h>

int main()
{
int a , b , x , y , k;
double min , p , temp , q;

	while (scanf("%d %d" , &a , &b) == 2)
	{
		min = 100000;
		p = a * 1.0 / b;
		for (y = 1; y <= b; y ++)
		{
			x = 1; k = -1; q = 10000;
			while(1)
			{
				temp = fabs(x * 1.0 / y - p);
				if (temp < min)	{min = temp; k = x;}
				else if (((q < temp) && (temp > min)) || (k > 0)) break;
				x ++; q = temp;
			}
			if (k > 0) printf("%d/%d\n" , k , y);
		}
		printf("\n");
	}
	return 0;
}
