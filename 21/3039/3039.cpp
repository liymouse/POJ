#include <stdio.h>
#include <math.h>

int gcd(int x , int y)
{
int c;

	while (y)
	{
		c = y; y = x % y; x = c;
	}
	return x;
}

int main()
{
int a , b;
int x , y;
int rx , ry;
double min , temp;

	while (scanf("%d %d" , &a , &b) == 2)
	{
		min = 32777;
		temp = a * 1.0 / b;
		for (y = 1; y <= 32767; y ++)
		{
			x = (int)((a * 1.0 / b) * y);
			if (x > 32767) continue;
			if ((gcd(x , y) == 1) && (fabs(x * 1.0 / y - temp) < min) && ((x != a) || (y != b)))
			{
				rx = x; ry = y;
				min = fabs(x * 1.0 / y - temp);
			}
			x ++;
			if ((x <= 32767) && (gcd(x , y) == 1) && (fabs(x * 1.0 / y - temp) < min) && ((x != a) || (y != b)))
			{
				rx = x; ry = y;
				min = fabs(x * 1.0 / y - temp);
			}
		}
		printf("%d %d\n" , rx , ry);
	}
	return 0;
}