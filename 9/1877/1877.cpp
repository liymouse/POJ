#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int &x , int &y)
{
	return x < y;
}

int main()
{
int m , n , i , num , min , t = 0;
int a[900];
double high , water;

	while (scanf("%d %d" , &m , &n) == 2)
	{
		t ++;
		if (m == 0) break;
		n *= m;
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		scanf("%lf" , &water);
		water /= 100;
		sort(a , a + n , cmp);
		num = 1; min = a[0];
		for (i = 1; i < n; i ++)
			if (a[i] == min) num ++;
			else
			{
				if (num * (a[i] - min) >= water) break;
				water -= num * (a[i] - min);
				min = a[i];	num ++;
			}
		high = min + water*1.0/num;
		printf("Region %d\n" , t);
		printf("Water level is %.2lf meters.\n" , high);
		printf("%.2lf percent of the region is under water.\n" , num * 100.0 / n);
	}
	return 0;
}