#include <stdio.h>

int a[7] , tot , k;
int p[4] = {0 , 5 , 3 , 1};
int q[4] = {0 , 7 , 6 , 5};

int main()
{
	while (scanf("%d %d %d %d %d %d" , &a[1] , &a[2] , &a[3] , &a[4] , &a[5] , &a[6]) == 6)
	{
		if (!(a[1] || a[2] || a[3] || a[4] || a[5] || a[6])) return 0;
		tot = 0;
		while (1)
		{
			if (a[6] > 0)
			{
				tot += a[6]; a[6] = 0; 
			}
			else if (a[5] > 0)
			{
				tot += a[5];
				a[1] -= a[5] * 11;
				a[5] = 0; 
				if (a[1] < 0) a[1] = 0;
			}
			else if (a[4] > 0)
			{
				tot += a[4];
				if (a[2] >= 5 * a[4]) a[2] -= 5 * a[4];
				else
				{
					k = 5 * a[4] - a[2];
					a[2] = 0;
					k *= 4;
					a[1] -= k;
					if (a[1] < 0) a[1] = 0;
				}
				a[4] = 0;
			}
			else if (a[3] > 0)
			{
				tot += a[3] / 4;
				if (a[3] % 4 > 0)
				{
					tot ++;
					if (a[2] > p[a[3] % 4]) 
					{
						a[2] -= p[a[3] % 4];
						a[1] -= q[a[3] % 4];
						if (a[1] < 0) a[1] = 0;
					}
					else
					{
						k = 36 - 9 * (a[3] % 4) - a[2] * 4;
						a[2] = 0;
						a[1] -= k;
						if (a[1] < 0) a[1] = 0;
					}
				}
				a[3] = 0;
			}
			else if (a[2] > 0)
			{
				tot += a[2] / 9;
				if (a[2] % 9 > 0) 
				{
					tot ++;
					k = 36 - (a[2] % 9) * 4;
					a[1] -= k;
					if (a[1] < 0) a[1] = 0;
				}
				a[2] = 0;
			}
			else if (a[1] > 0)
			{
				tot += a[1] / 36;
				if (a[1] % 36 > 0) tot ++;
				a[1] = 0;
			}
			else break;
		}
		printf("%d\n" , tot);
	}
	return 0;
}
