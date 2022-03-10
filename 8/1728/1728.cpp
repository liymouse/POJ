#include <stdio.h>

int main()
{
int s , x , y , dx , dy , tot;

	while (scanf("%d %d %d %d %d" , &s , &x , &y , &dx , &dy) == 5)
	{
		if (s == 0) break;
		{
			tot = 0;
			while (1)
			{
				if ((x % s > 0) && (y % s > 0) && ((x / s + y / s) % 2 == 1))
				{printf("After %d jumps the flea lands at (%d, %d).\n" , tot , x , y); break;}
				tot ++; x += dx; y += dy;
				if (tot > 4000) {printf("The flea cannot escape from black squares.\n"); break;}
			}
		}
	}
	return 0;
}