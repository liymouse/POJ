#include <stdio.h>
#include <math.h>

int main()
{
int L , i , x , y , minn , mind , z;
double a , k , min;

	while (scanf("%lf" , &a) == 1)
	{
		scanf("%d" , &L);
		min = 1000000;
		for (i = 1; i <= L; i ++)
		{
			x = 1; y = L;
			while (x <= y)
			{
				z = (x + y) / 2;
				k = double(z) / double(i);
				if (k > a) y = z - 1;
				else if (k < a) x = z + 1;
					else break;
			}
			if (fabs(a - double(z) / double(i)) < min)
			{
				min = fabs(a - double(z) / double(i));
				mind = i; minn = z;
			}
			if ((z < L) && (fabs(a - double(z+1) / double(i)) < min))
			{
				min = fabs(a - double(z+1) / double(i));
				mind = i; minn = z+1;
			}
			if ((z > 0) && (fabs(a - double(z-1) / double(i)) < min))
			{
				min = fabs(a - double(z-1) / double(i));
				mind = i; minn = z-1;
			}
		}
		printf("%d %d\n" , minn , mind);
	}
	return 0;
}