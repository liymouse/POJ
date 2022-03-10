#include <stdio.h>
#include <string.h>
#include <math.h>

#define Pi 3.1415926

int main()
{
int n , Li;
int x[1003] , y[1003];
int tu[1003];
int i , j , min , max , s , t , k , ss , tt , tot , p;
double dian , L1 , L2 , maxcos , maxL , L;

	scanf("%d %d" , &n , &Li);
	for (i = 0; i < n; i ++) scanf("%d %d" , &x[i] , &y[i]);
	memset(tu , 0 , sizeof(tu));
	min = 9999999; max = 0;
	for (i = 0; i < n; i ++)
		if ((y[i] < min) || (y[i] == min && x[i] > max))
		{
			min = y[i];
			max = x[i]; 
			j = i;
		}
	s = 1; t = 0; tot = 1;
	tu[j] = 1;
	while (1)
	{
		maxcos = -3;
		maxL = 0;
		for (i = 0; i < n; i ++)
			if (i != j)
			{
				ss = x[i] - x[j];
				tt = y[i] - y[j];
				dian = ss * s + tt * t;
				L1 = sqrt((double)(s * s + t * t));
				L2 = sqrt((double)(ss * ss + tt * tt));
				dian /= L1 * L2;
				if (dian > maxcos || (dian == maxcos && L2 > maxL))
				{
					maxcos = dian; maxL = L2; k = i;
				}
			}
		if (tu[k] == 1) break;
		tu[k] = 1;
		tot ++;
		s = x[k] - x[j];
		t = y[k] - y[j];
		j = k;
	}
	for (i = 0; i < n; i ++)
		if (tu[i] == 1) {s = i; t = i; break;}
	L = 0;
	while (i < n)
	{
		if (tu[i] == 1)
		{
			L += sqrt((double)(x[i] - x[t]) * (double)(x[i] - x[t]) + (double)(y[i] - y[t]) * (double)(y[i] - y[t]));
			t = i;
		}
		i ++;
	}
	L += sqrt((double)(x[t] - x[s]) * (double)(x[t] - x[s]) + (double)(y[t] - y[s]) * (double)(y[t] - y[s]));
	L += 2 * Pi * Li;
	printf("%.0lf\n" , L);
	return 0;
}
